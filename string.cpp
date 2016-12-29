
#include "include.h"

stringstream c;

void fun2()
{
    string one = "/tmp/hi";
    string two = "/tmp/me";
    string three = "/tmp/hi";
    string four = "/tmp/me";

    if (one == two) cout << "1 & 2 are same" << std::endl;
    if (one == three) cout << "1 & 3 are same" << std::endl;
    if (one == four) cout << "1 & 4 are same" << std::endl;


    string t1 = "ss";
    string t2 = "nn";

    if (t1.compare("ss")) cout << "both are same" << std::endl;

}

int main(int argc, char** argv)
{
    string str = "HI This is me speaking";
    string word;
    stringstream stream(str);
    while( getline(stream, word, ' ') )
        cout << word << "\n";

    fun2();

    return 0;
}

