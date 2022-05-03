
#include "include.h"
#include "assert.h"

main()
{
    char    to_version[]          = "ver 09.0.00devT241";
    char    from_version[]          = "10.0.00devT243";
    char*   token                   = NULL;
    char*   from_platform_type_str  = NULL;
    int     from_platform_type      = 0;
    char*   to_platform_type_str    = NULL;
    int     to_platform_type        = 0;

    printf("si_migration: from version: %s, to version: %s\n", from_version, to_version);

    token = strtok(from_version, "T");
    from_platform_type_str = strtok(NULL, "T");
    from_platform_type = atoi(from_platform_type_str) % 10;

    token = strtok(to_version, "T");
    to_platform_type_str = strtok(NULL, "T");
    to_platform_type = atoi(to_platform_type_str) % 10;

    printf("si_migration: from_platform_type: %u to_platform_type: %u\n", from_platform_type, to_platform_type);
}


