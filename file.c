
#include "include.h"
#include "assert.h"

int main()
{
    FILE *fp;
    fp = fopen("temp_file.txt", "w");
    fprintf(fp, "%d", 12345);
    fprintf(fp, " %d", 6754);
    fclose(fp);

    FILE *fp1 = fopen("temp_file.txt", "r");
    int val1 = 0;
    int val2 = 0;
    fscanf(fp1, "%d", &val1);
    fscanf(fp1, "%d", &val2);
    fclose(fp1);
    printf("%d - %d", val1, val2);

}
old()
{

    FILE *ptr;
    ptr = fopen("dummy_global.txt","w");
    fprintf(ptr, "5");
    fclose(ptr);

    FILE *rptr;
    int num = 0;
    rptr = fopen("dummy_global.txt","r");
    fscanf(rptr,"%d", &num);
    fclose(rptr);

    printf("read file: %d\n", num);

    return 0;
}
