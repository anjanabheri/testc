
#include "../include.h"

int main(int argc, char* argv[])
{
    int* buf = NULL;
    long unsigned int size = 1024 * 1024;
    long unsigned int successMallocedSize = 0;
    

    while (1)
    {
        buf = (int*)calloc(1, size);

        if (buf != NULL)
        {
            //cout << "malloc of size: " << size << " successful" << ", ptr: " << buf << endl;
            free(buf);
            successMallocedSize = size;
            size = size + (1024 * 1024);
        }
        else
        {
            cout << "malloc of size: " << size << " failed" << endl;
            cout << "last malloc of size: " << (successMallocedSize / (1024 * 1024 * 1024)) << " GB successful" << endl;

            size = successMallocedSize;
            buf = (int*)calloc(1, size);
            cout << "1 malloc of size: " << size << " successful" << ", ptr: " << buf << endl;
            buf = (int*)calloc(1, size);
            cout << "2 malloc of size: " << size << " successful" << ", ptr: " << buf << endl;

            return 0;
        }
    }

    return 0;
}
