#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int factorial (int number);

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n = 0;
    scanf("%d", &n);
    n = factorial(n);
    printf("%d", n);
    return 0;
}

int factorial (int number)
{
    if (number != 1)
        return (number * factorial(number - 1));
    return 1;
}

