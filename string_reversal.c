#include<stdio.h>

reverse(char* word_begin, char* end)
{
    char temp;

    while(word_begin < end)
    {
        temp = *word_begin;
        *word_begin ++ = *end;
        *end -- = temp;
    }
}


int main(void)
{
    char s[] = "Life is Beautiful";
    char* word_begin = s;
    char* temp = s;

    while (*temp)
    {
        temp ++;
        if (*temp == ' ')
        {
            reverse(word_begin, temp-1);
            word_begin = temp + 1;
        }
        else if (*temp == '\0')
        {
            reverse(word_begin, temp-1);
            break;
        }
    }
    reverse(s, temp-1);
    printf("string after first reversal: %s\n", s);

    return 0;
}
