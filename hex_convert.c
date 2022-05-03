
#include "include.h"
#include "assert.h"

char convert[10] = {0};
char hex[16] = "0123456789ABCDEF";
void idToShortURL(int n)
{
    // code here

    unsigned int multiple = 0;
    unsigned int remainder = 0;
    unsigned int string_index = 0;
    int base = 62;

    while (n >= base)
    {
        multiple = n / base;
        remainder = n % base;
        if (multiple)
        {
            convert[string_index] = hex[remainder];
            string_index ++;
        }
        n = multiple;
    }
    convert[string_index] = hex[n];
    //reverse(convert.begin(), convert.end());

}

print_convert()
{
    int i = 0;
    for (i=9; i >= 0; i --)
        printf("%c", convert[i]);
}

main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("AKDEBUG %s()-%d: arg please\n", __FUNCTION__, __LINE__); 
        return;
    }

    idToShortURL(atoi(argv[1]));
    printf("hex of %s is ", argv[1]);
    print_convert();
    printf("\n");
}


