
void fun(char** s )
{
    strcpy(s, "some");
}

main()
{
    //read only data segment
    char* s1 = "hello";
    //read write data segment
    char s2[] = "yellow";
    fun(&s2);
    printf("s2: %s\n", s2);
    fun(&s1);
    printf("s1: %s\n", s1);
}
