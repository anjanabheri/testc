
char* fun()
{
   return "home";
}

main()
{
    char* s;

    s = fun();
    printf("string: %s\n", s);
    free(s);
}
