
#include "include.h"

stringstream c;

int main(int argc, char** argv)
{
    string str = "HI This is me speaking";
    string word;
    stringstream stream(str);
    while( getline(stream, word, ' ') )
        cout << word << "\n";
    return 0;
}
