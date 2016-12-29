
#include "include.h"

int *array;

int maxRow = 2;
int maxCol = 3;

int getEntry(int row, int column);
int setEntry(int row, int column, int data);

int main()
{
    array = (int*)malloc (sizeof(int) * (maxRow + 1) * (maxCol + 1));

    setEntry(0,0,1);
    setEntry(0,1,2);
    setEntry(0,2,3);
    setEntry(0,3,4);

    setEntry(1,0,11);
    setEntry(1,1,12);
    setEntry(1,2,13);
    setEntry(1,3,14);

    setEntry(2,0,21);
    setEntry(2,1,22);
    setEntry(2,2,23);
    setEntry(2,3,24);

    int i = 0, j = 0;

    for (i = 0; i <= maxRow; i ++)
    {
        for (j = 0; j <= maxCol; j ++)
        {
            cout << " " << getEntry(i, j);
        }
        cout << endl;
    }

    return 0;
}


int getEntry(int row, int column)
{
    return *(((char*)array) + ((maxCol + 1) * row) + column);
}
int setEntry(int row, int column, int data)
{
    cout << "ptr position: " << (((maxCol + 1) * row) + column) << endl;
    *(((char*)array) + ((maxCol + 1) * row) + column) = data;
}


