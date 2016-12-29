#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank";

 // Declare second integer, double, and String variables.
    int is = 0;
    double ds = 0;
    char ss[50];


    // Read and save an integer, double, and String to your variables.
    scanf("%d", &is);
    scanf("%lf", &ds);
    fgets(ss, 49, stdin);
    printf("ss: %s\n", ss);

    // Print the sum of both integer variables on a new line.
    printf("%d\n", i+is);

    // Print the sum of the double variables on a new line.

    printf("%lf\n", d+ds);
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.

    printf("%s %s", s, ss);

    return 0;
}

