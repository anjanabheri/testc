
#include "../include.h"
#include "assert.h"
#include "time.h"

void add()
{
    /*
  This program is for adding two numbers
  By: Alaap
  */

    //This is a comment
    int a;
    int b;
    int c;

    printf("Program for adding 2 numbers\n");
    printf("Enter first number: ");
    scanf("%i", &a);
    printf("\nEnter second number: ");
    scanf("%i", &b);

    printf("Sum: %d\n", a+b);
    printf("Difference: %d\n", a-b);
    printf("Product: %d\n", a * b);
    printf("Quotient: %d\n", a / b);
}

void setup()
{
    printf("Calling setup()\n");
}

void loop()
{
    printf("LED ON...\n");
    sleep(1);
    printf("LED Off...\n");
    sleep(1);
}

main()
{

    setup();

    while(1)
    {
        loop();
    }
}

