
#include "include.h"

typedef std::set<uint32_t> plmnRef;
typedef std::map<uint32_t, plmnRef> tacRefList;

tacRefList tacList;

int array[6]={0x0221, 0x0224, 0x0221, 0x0321, 0x0336, 0x0421};

int getTac(int tai)
{
    return (tai >> 8);
}
int getPlmn(int tai)
{
    return (0xFF & tai);
}

int fun1()
{
    tacRefList::iterator tac;
    int i, t1, p1 = 0;

    for (i = 0; i < 6; i++)
    {
        t1 = getTac(array[i]);
        p1 = getPlmn(array[i]);

        printf("tac: %x, plmn: %x \n", t1, p1);

        tac = tacList.find(t1);
        if (tac == tacList.end())
        {
            printf("its end \n");
            //tacRefList newTac;
            plmnRef plmnList;
            tacList[t1] = plmnList;
            tac = tacList[t1];
        }
        else
        {
        }

        tac->second.insert(p1);    

        //plmnList.insert(22);    
        //tacList[t1] = plmnList;
    }

    return 0;
}

int print()
{

    printf("Printing the tree \n\n");

    tacRefList::iterator tac = tacList.begin();

    for (; tac != tacList.end(); ++ tac)
    {
        printf("tac: %x \n", tac->first);

        plmnRef::iterator plmn = tac->second.begin();
        for(; plmn != tac->second.end(); plmn ++)
        {
            printf("    plmn: %x \n", *plmn);
        }

    }
    return 0;
}

int main()
{
    fun1();
    print();

    return 0;
}
