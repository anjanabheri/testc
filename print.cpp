
#include "include.h"

void
hexDumpMessage(char* buffer, unsigned int length, std::ostringstream& oss)
{
    unsigned int index = 0U;

    for (index = 0U; index < length; index ++)
    {
        if ((index % 8U) == 0U)
        {
            oss << std::endl << setfill('0') << std::setw(6) << index;
            oss << "  ";
        }
        oss << std::hex << std::setw(2) << std::uppercase << (unsigned short)buffer[index];
        oss << " ";
    }

    return;
}


int main()
{
    char buf[] = "345";
    ostringstream oss;
    hexDumpMessage(buf, 3, oss);
    cout << "" << oss.str();
    return 0;
}
