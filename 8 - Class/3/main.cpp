#include <iostream>
#include "class.h"

Clock Time(Clock &c1, Clock &c2) {
    Clock result(abs(c1.getTimestamp() - c2.getTimestamp()));
    result.DisplayTime();
    return result;
}

int main(){
    int hh, mm, ss;
    Clock time1, time2;
    scanf("%d:%d:%d", &hh, &mm, &ss);
    time1.SetTime(hh, mm, ss);
    scanf("%d:%d:%d", &hh, &mm, &ss);
    time2.SetTime(hh, mm, ss);
    Time(time1,time2);
    return 0;
}