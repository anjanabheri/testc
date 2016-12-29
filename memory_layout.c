
/* 
 size <executable> will give the memory layout
 Ex: size memory_layout
   text    data     bss     dec     hex filename
   1040     492      24    1556     614 memory_layout
*/

int global = 10; /* Uninitialized variable stored in bss*/
 
int main(void)
{
    static int i; /* Uninitialized static variable stored in bss */
    static int j; /* Uninitialized static variable stored in bss */
    static int k = 100; 
    return 0;
}
