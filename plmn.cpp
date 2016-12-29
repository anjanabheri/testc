
#include "include.h"

int main(int argc, char** argv)
{
    string mcc= argv[1];
    string mnc= argv[2];
    string plmn;

    int mncId = atoi(argv[2]);

    plmn[0] = mcc[1];
    plmn[1] = mcc[0];
    plmn[3] = mcc[2];

    if (mncId < 100U)
    {
        plmn[2] = 'F';
        plmn[4] = mnc[1];
        plmn[5] = mnc[0];
    }
    else
    {
        plmn[2] = mnc[0];
        plmn[4] = mnc[2];
        plmn[5] = mnc[1];
    }

    unsigned int plmnId = 0;
    plmnId = strtol(plmn.c_str(), 0, 16);

    cout << "plmn string: " << plmn.c_str() << endl;

    cout << "plmnId: " << plmnId << endl;

    return 0;
}
