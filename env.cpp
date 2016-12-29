
#include "include.h"

std::string GETENV(char *env)
{
    char *envvalue = getenv(env);

    if (NULL == envvalue)
        return "";
    else
        return envvalue;
}

int main()
{

    std::string some;
    some = GETENV("SOMETHING_XXX");
    if (some.empty())
        cout << "env not set" << endl;
    else
        cout << "some: " << some << std::endl;

    return 0;
}
