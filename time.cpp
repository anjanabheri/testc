
#include "include.h"

int main()
{
    int basicTimerPeriod = (int) 300;
    time_t startTime = time(NULL);
    time_t myStartTime = time(NULL);
    cout << ":Current time = " << startTime << endl;
    startTime = (startTime/basicTimerPeriod)*basicTimerPeriod + basicTimerPeriod;
    cout << ":Current time = " << startTime << endl;

    myStartTime = myStartTime + (basicTimerPeriod - (myStartTime % basicTimerPeriod));

    cout << ":my Current time = " << myStartTime << endl;
    return 0;
}
