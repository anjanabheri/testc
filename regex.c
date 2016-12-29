
#include "include.h"

regex_t regex;
int ret;
char msgbuf[100];

main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printf("pass the String to match\n");
        printf("usage: ./a.out <regex> <string>\n");
        return 0;
    }

    /* Compile regular expression */
    ret = regcomp(&regex, argv[1], REG_EXTENDED);
    if (ret) {
        printf("Could not compile regex\n");
        return 0;
    }

    /* Execute regular expression */
    ret = regexec(&regex, argv[2], 0, NULL, 0);
    if (!ret) {
        puts("Match");
    }
    else if (ret == REG_NOMATCH) {
        puts("No match");
    }
    else {
        regerror(ret, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        return 0;
    }

    /* Free compiled regular expression if you want to use the regex_t again */
    regfree(&regex);
}
