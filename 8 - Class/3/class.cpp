#include <iostream>
#include <cstdio>
#include <cmath>
#include "class.h"
using namespace std;

Clock::Clock() {
    // 默认构造函数的定义
}
Clock::Clock(int hh, int mm, int ss) {
    SetTime(hh, mm, ss);
}
Clock::Clock(int stamp){
    timestamp = stamp;
}

Clock::~Clock() {
    
}

void Clock::SetTime(int hh, int mm, int ss) {
    timestamp = hh * 3600 + mm * 60 + ss;
}

void Clock::DisplayTime() {
    printf("%02d:%02d:%02d\n",
           (timestamp / 3600) % 24, (timestamp / 60) % 60, timestamp % 60);
}
int Clock::getTimestamp() const {
        return timestamp;
    }