#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char s[20000];
    int i = 0;

    scanf("%s", s);
    
    if (strlen(s) < 2)
        return 0;
    
    for (i = 0; i < strlen(s); i += 2)
        printf("%c", s[i]);
    
    printf(" ");

    for (i = 1; i < strlen(s); i += 2)
        printf("%c", s[i]);
    
    
    return 0;
}
