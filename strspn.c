// C program to illustrate strspn() function 
#include <stdio.h> 
#include <string.h> 

char *file = "TNR08095dev.c";
  
int main () { 

    int len1 = strspn(file, ".\\");

   int len = strspn("geeks for geeks","geeks"); 
   printf("Length of initial segment matching : %d\n", len1 );     
   return(0); 
}
