
#include "include.h"

typedef unsigned char u_int8_t;
typedef unsigned int u_int32_t;

#define ECOMMUNITY_IANA_BIT        0X80
#define ECOMMUNITY_ENCODE_AS       0x00
#define ECOMMUNITY_ENCODE_IP       0x01
#define ECOMMUNITY_ENCODE_AS4      0x02
/*rfc 4360 */
#define ECOMMUNITY_OPAQUE                     0x03
/* sub-types defined by IANA */

/* Low-order octet of the Extended Communityes type field. */
#define ECOMMUNITY_ROUTE_TARGET               0x02
#define ECOMMUNITY_SITE_ORIGIN                0x03


#define ECOMMUNITY_FORMAT_ROUTE_MAP            0
#define ECOMMUNITY_FORMAT_COMMUNITY_LIST       1
#define ECOMMUNITY_FORMAT_DISPLAY              2


struct ecommunity
{
    u_int32_t refcnt;
    u_int32_t size;
    char val[32];
    char *str;
};

/* Extended community value is eight octet.  */
struct ecommunity_val
{
    u_int8_t val[8];
};

/* For parse Extended Community attribute tupple. */
struct ecommunity_as
{
    int as;
    u_int32_t val;
};

struct ecommunity_ip
{
  struct in_addr ip;
  u_int16_t val;
};


char* ecommunity_com2str (struct ecommunity *ecom);
char* ecommunity_com2str_quagga (struct ecommunity *ecom);
char * ecommunity_com2str_mine (struct ecommunity *ecom, int format);
char * ecommunity_ecom2str (struct ecommunity *ecom, int format);

int main()
{
    struct ecommunity ecom;
    char expected_string1[] = "rt 12345:67890 soo 101.102.103.104:56789 ? rt 1234567890:43210";
    char expected_string2[] = "RT:12345:67890 SoO:101.102.103.104:56789 ? RT:1234567890:43210";
    char expected_string3[] = "12345:67890 101.102.103.104:56789 ? 1234567890:43210";
    char expected_val[32];

    // RT 12345:67890
    ecom.val[0] = 0x00;
    ecom.val[1] = 0x02;
    ecom.val[2] = 0x30;
    ecom.val[3] = 0x39;
    ecom.val[4] = 0x00;
    ecom.val[5] = 0x01;
    ecom.val[6] = 0x09;
    ecom.val[7] = 0x32;

    // SOO 101.102.103.104:56789
    ecom.val[8] = 0x01;
    ecom.val[9] = 0x03;
    ecom.val[10] = 0x65;
    ecom.val[11] = 0x66;
    ecom.val[12] = 0x67;
    ecom.val[13] = 0x68;
    ecom.val[14] = 0xdd;
    ecom.val[15] = 0xd5;

    ecom.val[16] = 0x07;
    ecom.val[17] = 0x08;
    ecom.val[18] = 0x49;
    ecom.val[19] = 0x96;
    ecom.val[20] = 0x02;
    ecom.val[21] = 0xd2;
    ecom.val[22] = 0xa8;
    ecom.val[23] = 0xca;

    ecom.val[24] = 0x02;
    ecom.val[25] = 0x02;
    ecom.val[26] = 0x49;
    ecom.val[27] = 0x96;
    ecom.val[28] = 0x02;
    ecom.val[29] = 0xd2;
    ecom.val[30] = 0xa8;
    ecom.val[31] = 0xca;

    memcpy(expected_val, ecom.val, sizeof(expected_val));

    ecom.size = 4;

    //ecom.str =  ecommunity_com2str_quagga(&ecom);
    //ecom.str =  ecommunity_com2str(&ecom);
    //ecom.str = ecommunity_ecom2str(&ecom, ECOMMUNITY_FORMAT_COMMUNITY_LIST);


    // Community Format
    ecom.str = ecommunity_com2str_mine(&ecom, ECOMMUNITY_FORMAT_COMMUNITY_LIST);
    printf("Community: ecom.str:%s \n", ecom.str);

    if (!strncmp(ecom.str, expected_string1, strlen(expected_string1)))
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
        printf("\n");
        return 0;
    }

    // Display (show) format
    ecom.str = ecommunity_com2str_mine(&ecom, ECOMMUNITY_FORMAT_DISPLAY);
    printf("Display: ecom.str:%s \n", ecom.str);

    if (!strncmp(ecom.str, expected_string2, strlen(expected_string2)))
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
        printf("\n");
        return 0;
    }

    // Route-map format (for regular expression match)
    ecom.str = ecommunity_com2str_mine(&ecom, ECOMMUNITY_FORMAT_ROUTE_MAP);
    //ecom.str = ecommunity_ecom2str(&ecom, ECOMMUNITY_FORMAT_ROUTE_MAP);
    printf("Routemap: ecom.str:%s \n", ecom.str);

    if (!strncmp(ecom.str, expected_string3, strlen(expected_string3)))
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
        printf("\n");
        return 0;
    }

    if (!memcmp(expected_val, ecom.val, sizeof(expected_val)))
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
        printf("\n");
        return 0;
    }
    printf("\n");
    return 0;
}

char* ecommunity_com2str (struct ecommunity *ecom)
{
    int i = 0;
    char *str = NULL;
    char *strp = NULL;
    char *pnt = NULL;
    int len= 0;
    int encode = 0;
    int first = 0;
    struct ecommunity_as eas;
    struct ecommunity_ip eip;
    struct in_addr p;
    char buff [50];

    if (!ecom)
        return NULL;

    /* When communities attribute is empty.  */
    if (ecom->size == 0)
    {
        str = (char*)malloc(1);
        str[0] = '\0';
        return str;
    }

    for (i = 0; i < ecom->size; i++)
    {
        memset (&eas, 0, sizeof (struct ecommunity_as));
        pnt = ecom->val + (i * 8);
        pnt++;
        if (*pnt == ECOMMUNITY_ROUTE_TARGET)
            len += strlen (" rt ");
        else if (*pnt == ECOMMUNITY_SITE_ORIGIN)
            len += strlen (" soo ");
        else if (*pnt == ECOMMUNITY_OPAQUE)
            len += strlen (" opaque ");
        /* calculate bytes required for ASN:NN or IP:NN */
        len += strlen (" 255.255.255.255:65535 ");
    }
    /* Allocate memory.  */
    strp = str = pnt = (char*)malloc(len);
    first = 1;

    /* Fill in string.  */
    for (i = 0; i < ecom->size; i++)
    {
        if (first)
            first =0;
        else
            *pnt ++ = ' ';

        pnt = ecom->val + (i * 8);

        if (!pnt)
            break;

        encode = *pnt;
        pnt++;
        if (*pnt == ECOMMUNITY_ROUTE_TARGET)
        {
            strcpy (pnt, " rt ");
            strp += strlen (" rt ");
        }
        else if (*pnt == ECOMMUNITY_SITE_ORIGIN)
        {
            strcpy (pnt, " soo ");
            pnt += strlen (" soo ");
        }
        else if (*pnt == ECOMMUNITY_OPAQUE)
        {
            strcpy (pnt, " opaque ");
            pnt += strlen (" opaque ");
        }
        if (encode == ECOMMUNITY_ENCODE_AS)
        {
            eas.as = (*pnt++ << 8);
            eas.as |= (*pnt++);

            eas.val = (*pnt++ << 24);
            eas.val |= (*pnt++ << 16);
            eas.val |= (*pnt++ << 8);
            eas.val |= (*pnt++);

            snprintf (pnt, (str+len) - pnt,"%u:%u", eas.as, eas.val);
        }
        else if (encode == ECOMMUNITY_ENCODE_AS4)
          {
            eas.as = (*pnt++ << 24);
            eas.as |= (*pnt++ << 16);
            eas.as |= (*pnt++ << 8);
            eas.as |= (*pnt++);

            eas.val |= (*pnt++ << 8);
            eas.val |= (*pnt++);
            snprintf (pnt, (str+len) - pnt,"%u:%u", eas.as, eas.val);
          }
        else if (encode == ECOMMUNITY_ENCODE_IP)
          {
            memcpy (&eip.ip, pnt, 4);
            pnt += 4;
            eip.val = (*pnt++ << 8);
            eip.val |= (*pnt++);
            snprintf (pnt, (str+len) - pnt, "%s:%u", inet_ntoa (eip.ip), eip.val);
          }
     }

    if (pnt)
        *pnt = '\0';

    return str;
}

    char *
ecommunity_com2str_quagga (struct ecommunity *ecom)
{
    int i;
    u_int8_t *pnt;
    int encode = 0;
    int type = 0;
#define ECOMMUNITY_STR_DEFAULT_LEN  27
    int str_size;
    int str_pnt;
    char *str_buf;
    const char *prefix;
    int len = 0;
    int first = 1;
    struct ecommunity_as eas;
    struct ecommunity_ip eip;

    if (ecom->size == 0)
    {
        str_buf = (char*)malloc(1);
        str_buf[0] = '\0';
        return str_buf;
    }

    /* Prepare buffer.  */
    str_buf = (char*)malloc(ECOMMUNITY_STR_DEFAULT_LEN + 1);
    str_size = ECOMMUNITY_STR_DEFAULT_LEN + 1;
    str_pnt = 0;

    for (i = 0; i < ecom->size; i++)
    {
        /* Make it sure size is enough.  */
        while (str_pnt + ECOMMUNITY_STR_DEFAULT_LEN >= str_size)
        {
            str_size *= 2;
            str_buf = realloc(str_buf, str_size);
        }

        /* Space between each value.  */
        if (! first)
            str_buf[str_pnt++] = ' ';

        pnt = ecom->val + (i * 8);

        /* High-order octet of type. */
        encode = *pnt++;
        if (encode != ECOMMUNITY_ENCODE_AS && encode != ECOMMUNITY_ENCODE_IP
                && encode != ECOMMUNITY_ENCODE_AS4)
        {
            len = sprintf (str_buf + str_pnt, "?");
            str_pnt += len;
            first = 0;
            continue;
        }

        /* Low-order octet of type. */
        type = *pnt++;
        if (type !=  ECOMMUNITY_ROUTE_TARGET && type != ECOMMUNITY_SITE_ORIGIN)
        {
            len = sprintf (str_buf + str_pnt, "?");
            str_pnt += len;
            first = 0;
            continue;
        }

        prefix = (type == ECOMMUNITY_ROUTE_TARGET ? "rt " : "soo ");

        /* Put string into buffer.  */
        if (encode == ECOMMUNITY_ENCODE_AS4)
        {
            eas.as = (*pnt++ << 24);
            eas.as |= (*pnt++ << 16);
            eas.as |= (*pnt++ << 8);
            eas.as |= (*pnt++);

            eas.val = (*pnt++ << 8);
            eas.val |= (*pnt++);

            len = sprintf( str_buf + str_pnt, "%s%u:%u", prefix,
                    eas.as, eas.val );
            str_pnt += len;
            first = 0;
        }
        if (encode == ECOMMUNITY_ENCODE_AS)
        {
            eas.as = (*pnt++ << 8);
            eas.as |= (*pnt++);

            eas.val = (*pnt++ << 24);
            eas.val |= (*pnt++ << 16);
            eas.val |= (*pnt++ << 8);
            eas.val |= (*pnt++);

            len = sprintf (str_buf + str_pnt, "%s%u:%u", prefix,
                    eas.as, eas.val);
            str_pnt += len;
            first = 0;
        }
        else if (encode == ECOMMUNITY_ENCODE_IP)
        {
            memcpy (&eip.ip, pnt, 4);
            pnt += 4;
            eip.val = (*pnt++ << 8);
            eip.val |= (*pnt++);

            len = sprintf (str_buf + str_pnt, "%s%s:%u", prefix,
                    inet_ntoa (eip.ip), eip.val);
            str_pnt += len;
            first = 0;
        }
    }
    return str_buf;
}

#define ONE_ECOMMUNITY_STR_MAX_LEN      40
#define ECOMMUNITY_ATTRIBUTE_LEN    8

char * ecommunity_com2str_mine (struct ecommunity *ecom, int format)
{
    int i;
    u_int8_t *pnt;
    int encode_type = 0;
    int ecom_type = 0;
    int str_size;
    char *str_buf;
    int len = 0;
    int first = 1;
    u_int8_t *prefix;
    struct ecommunity_as eas;
    struct ecommunity_ip eip;

    if (ecom->size == 0)
    {
        str_buf = (char*)malloc(1);
        str_buf[0] = '\0';
        return str_buf;
    }

    /* Allocate maximum buffer */
    str_size = ONE_ECOMMUNITY_STR_MAX_LEN * ecom->size;
    str_buf = (char*)malloc(str_size);
    memset(str_buf, str_size, 0);

    /* Iterate through all the extended community attributes */
    for (i = 0; i < ecom->size; i++)
    {
        /* Point to begining of attribute, each iteration points to next attribute */
        pnt = ecom->val + (i * ECOMMUNITY_ATTRIBUTE_LEN);

        /* Space not needed for first attribute*/
        if (i != 0)
          len += snprintf (str_buf + len, str_size - len, " ");

        /* Get Encoding Type from High-order octet */
        encode_type = *pnt++;

        if (encode_type != ECOMMUNITY_ENCODE_AS && 
            encode_type != ECOMMUNITY_ENCODE_IP &&
            encode_type != ECOMMUNITY_ENCODE_AS4)
        {
            len += snprintf (str_buf + len, str_size - len, "?");
            continue;
        }

        /* Get Type from Low-order octet */
        ecom_type = *pnt++;

        if (ecom_type != ECOMMUNITY_ROUTE_TARGET && 
            ecom_type != ECOMMUNITY_SITE_ORIGIN &&
            ecom_type != ECOMMUNITY_OPAQUE)
        {
            len += snprintf (str_buf + len, str_size - len, "?");
            continue;
        }

        /* String format depends on the argument sent */
        switch (format)
        {
            case ECOMMUNITY_FORMAT_COMMUNITY_LIST:

                if (ecom_type == ECOMMUNITY_ROUTE_TARGET)
                    prefix = "rt ";
                else if (ecom_type == ECOMMUNITY_SITE_ORIGIN)
                    prefix = "soo ";
                else if (ecom_type == ECOMMUNITY_OPAQUE)
                    prefix = "opaque ";

                break;

            case ECOMMUNITY_FORMAT_DISPLAY:

                if (ecom_type == ECOMMUNITY_ROUTE_TARGET)
                    prefix = "RT:";
                else if (ecom_type == ECOMMUNITY_SITE_ORIGIN)
                    prefix = "SoO:";
                else if (ecom_type == ECOMMUNITY_OPAQUE)
                    prefix = "Opaque:";

                break;

            case ECOMMUNITY_FORMAT_ROUTE_MAP:
                prefix = "";
                break;

            default:
                if (str_buf)
                    free(str_buf);
                return "Unknown";
        }

        len += snprintf (str_buf + len, str_size - len, "%s", prefix);

        /* Make string from the value */
        if (encode_type == ECOMMUNITY_ENCODE_AS4)
        {
            /* Get First 4 byte as AS */
            eas.as = ntohl(*((u_int32_t*)pnt));
            pnt += sizeof(u_int32_t);

            /* Get next 2 byte as value */
            eas.val = ntohs(*((u_int16_t*)pnt));
            pnt += sizeof(u_int16_t);

            len += snprintf( str_buf + len, str_size - len, "%u:%u", eas.as, eas.val );
        }
        else if (encode_type == ECOMMUNITY_ENCODE_AS)
        {
            /* Get First 2 byte as AS */
            eas.as = ntohs(*((u_int16_t*)pnt));
            pnt += sizeof(u_int16_t);

            /* Get next 4 byte as value */
            eas.val = ntohl(*((u_int32_t*)pnt));
            pnt += sizeof(u_int32_t);

            len += snprintf( str_buf + len, str_size - len, "%u:%u", eas.as, eas.val );
        }
        else if (encode_type == ECOMMUNITY_ENCODE_IP)
        {
            /* Get first 4 byte as IP Address */
            memcpy (&eip.ip, pnt, sizeof(struct in_addr));
            pnt += sizeof(struct in_addr);

            /* Get next 2 byte as value */
            eip.val = ntohs(*((u_int16_t*)pnt));
            pnt += sizeof(u_int16_t);

            len += snprintf( str_buf + len, str_size - len, "%s:%u", inet_ntoa (eip.ip), eip.val);
        }
    }
    return str_buf;
}
char *
ecommunity_ecom2str (struct ecommunity *ecom, int format)
{
  int i;
  u_int8_t *pnt;
  struct ecommunity_as eas;
  struct ecommunity_ip eip;
  int encode = 0;
  int type = 0;
  int str_size;
  int str_pnt;
  char* str_buf;
  char* prefix;
  int len = 0;
  int first = 1;

  if (ecom->size == 0)
    {
      str_buf = malloc(1);
      str_buf[0] = '\0';
      return str_buf;
    }

  /* Prepare buffer.  */
  str_buf = malloc(ECOMMUNITY_STR_DEFAULT_LEN + 1);
  str_size = ECOMMUNITY_STR_DEFAULT_LEN + 1;
  str_pnt = 0;

  for (i = 0; i < ecom->size; i++)
    {
      pnt = ecom->val + (i * 8);

      /* High-order octet of type. */
      encode = *pnt++;
      if (encode != ECOMMUNITY_ENCODE_AS && encode != ECOMMUNITY_ENCODE_IP)
        {
#ifdef ORIG
          if (str_buf)
            free( str_buf);
          return "Unknown";
#else
          len = snprintf (str_buf + str_pnt, str_size - str_pnt,
                              "unknown");
          str_pnt += len;
#endif
        }

      /* Low-order octet of type. */
      type = *pnt++;
      if (type !=  ECOMMUNITY_ROUTE_TARGET && type != ECOMMUNITY_SITE_ORIGIN)
        {
#ifdef ORIG
          if (str_buf)
            free( str_buf);
          return "Unknown";
#else
          len = snprintf (str_buf + str_pnt, str_size - str_pnt,
                              "unknown");
          str_pnt += len;
#endif
        }

      switch (format)
        {
        case ECOMMUNITY_FORMAT_COMMUNITY_LIST:
          prefix = (type == ECOMMUNITY_ROUTE_TARGET ? "rt " : "soo ");
          break;
        case ECOMMUNITY_FORMAT_DISPLAY:
          prefix = (type == ECOMMUNITY_ROUTE_TARGET ? "RT:" : "SoO:");
          break;
        case ECOMMUNITY_FORMAT_ROUTE_MAP:
          prefix = "";
          break;
        default:
          if (str_buf)
            free( str_buf);
          return "Unknown";
          break;
        }

      /* Make it sure size is enough.  */
      while (str_pnt + ECOMMUNITY_STR_DEFAULT_LEN >= str_size)
        {
          str_size *= 2;
          str_buf = realloc(str_buf, str_size);
        }

      /* Space between each value.  */
      if (! first)
        str_buf[str_pnt++] = ' ';

      /* Put string into buffer.  */
      if (encode == ECOMMUNITY_ENCODE_AS)
        {
          eas.as = (*pnt++ << 8);
          eas.as |= (*pnt++);

          eas.val = (*pnt++ << 24);
          eas.val |= (*pnt++ << 16);
          eas.val |= (*pnt++ << 8);
          eas.val |= (*pnt++);

          len = snprintf (str_buf + str_pnt, str_size - str_pnt,
                              "%s%d:%d", prefix, eas.as, eas.val);
          str_pnt += len;
          first = 0;
        }
      else if (encode == ECOMMUNITY_ENCODE_IP)
        {
          memcpy (&eip.ip, pnt, 4);
          pnt += 4;
          eip.val = (*pnt++ << 8);
          eip.val |= (*pnt++);

          len = snprintf (str_buf + str_pnt, str_size - str_pnt,
                           "%s%s:%d", prefix, inet_ntoa (eip.ip), eip.val);
                           //"%s%r:%d", prefix, &eip.ip, eip.val);
          str_pnt += len;
          first = 0;
        }
    }
  return str_buf;
}
