
#include "include.h"

typedef struct packet
{
    struct packet*  next;
    void*           data;
    int             len;
} packet;

packet* head = NULL;

void recvPacket(void* data, int len);
void getPacket(void* buffer, int len, int offset);

packet* newPacket(void* data, int len)
{
    packet* newPacket = (packet*)malloc(len);
    newPacket->data = data;
    newPacket->len = len;
    newPacket->next = NULL;

    return newPacket;
}

void recvPacket(void* data, int len)
{
    packet* node = head;

    if (node == NULL) 
    {
        head = newPacket(data, len);
        return;
    }

    while (node->next != NULL)
    {
        node = node->next;
    }

    //insert at the tail

    node->next = newPacket(data, len);

    return;
}

void getPacket(void* buffer, int packetLen, int packOffset)
{
    packet* node    = head;
    int     len     = 0;
    int     offset  = 0;
    int     lenToCopy = 0;
    int     copyOffset = 0;

    if ((buffer == NULL) || (packetLen == 0))
    {
        cout << "buffer is null or lenght is zero. please check." << endl;
        return;
    }

    offset = packOffset;

    while ((node != NULL) && (packetLen != 0))
    {
        len = node->len;

        if (offset > len)
        {
            offset = offset - len;
            node = node->next;
            continue;
        }

        if (packetLen <= (len - offset))
            lenToCopy = packetLen;
        else
            lenToCopy = len - offset;

        memcpy((char*)buffer + copyOffset, (char*)node->data + offset, lenToCopy);
        copyOffset += lenToCopy;

        offset = 0;

        packetLen = packetLen - lenToCopy;

        node = node->next;
    }

    return;
}

void showPackets()
{
    packet* node    = head;
    int     count   = 0;

    if (node == NULL)
    {
        return;
    }

    while (node != NULL)
    {
        count ++;
        cout << "Packet " << count << ": len: " << node->len << ", data: " << (char*)node->data << endl;
        node = node->next;
    }

    return;
}

int main()
{
    int caseNum = 0;
    int len = 0;
    int offset = 0;

    char packet1[] = "This is testing ";
    char packet2[] = "the packet reception. ";
    char packet3[] = "And also ";
    char packet4[] = "reassembly.";

    char buffer[100];

    recvPacket(packet1, strlen(packet1));
    recvPacket(packet2, strlen(packet2));
    recvPacket(packet3, strlen(packet3));
    recvPacket(packet4, strlen(packet4));

    showPackets();
    cout << endl;

    memset(buffer, 0, sizeof(buffer)); 
    caseNum ++;
    len = 4;
    offset = 0;
    getPacket(buffer, len, offset);
    cout << "case " << caseNum << ": length: " << len << ", offset: " << offset << ", buffer: " << buffer << endl;

    memset(buffer, 0, sizeof(buffer)); 
    caseNum ++;
    len = 2;
    offset = 5;
    getPacket(buffer, len, offset);
    cout << "case " << caseNum << ": length: " << len << ", offset: " << offset << ", buffer: " << buffer << endl;

    memset(buffer, 0, sizeof(buffer)); 
    caseNum ++;
    len = 26;
    offset = 0;
    getPacket(buffer, len, offset);
    cout << "case " << caseNum << ": length: " << len << ", offset: " << offset << ", buffer: " << buffer << endl;

    memset(buffer, 0, sizeof(buffer)); 
    caseNum ++;
    len = 40;
    offset = 5;
    getPacket(buffer, len, offset);
    cout << "case " << caseNum << ": length: " << len << ", offset: " << offset << ", buffer: " << buffer << endl;

    memset(buffer, 0, sizeof(buffer)); 
    caseNum ++;
    len = 20;
    offset = 38;
    getPacket(buffer, len, offset);
    cout << "case " << caseNum << ": length: " << len << ", offset: " << offset << ", buffer: " << buffer << endl;

    memset(buffer, 0, sizeof(buffer)); 
    caseNum ++;
    len = 26;
    offset = 20;
    getPacket(buffer, len, offset);
    cout << "case " << caseNum << ": length: " << len << ", offset: " << offset << ", buffer: " << buffer << endl;

    return 0;
}


