

unsigned char right_rotate(unsigned char s, unsigned char bits)
{
    unsigned char temp = s;
    int loop = bits;

    temp = temp >> bits;
    temp = temp | (s << (8 - bits));

    return temp;
}

unsigned char left_rotate(unsigned char s, unsigned char bits)
{
    unsigned char temp = s;
    int loop = bits;

    temp = temp << bits;
    temp = temp | (s >> (8 - bits));

    return temp;
}

const char *byte_to_binary(unsigned char x)
{
    static char b[9];
    b[0] = '\0';

    unsigned char z;
    for (z = 0x80; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

void main()
{
    unsigned char s;

    s = 15;

    char* schar = byte_to_binary(s);
    printf("before: %s\n", schar);

    unsigned char new = left_rotate(s, 5);
    char* newchar = byte_to_binary(new);

    printf("after : %s\n", newchar);
}
