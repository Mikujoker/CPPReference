#include "class.h"
#include <cstring>
#include <iostream>

using namespace std;

PersonScore::PersonScore(char* i, char* n, int m, int e, int c) {
    strcpy(id, "00000000");
    strcpy(name, "name");
    math = 0;
    English = 0;
    CS = 0;
}

PersonScore::~PersonScore() {
    
}

void PersonScore::GiveValue(int m, int e, int c){
    math = m;
    English = e;
    CS = c;
}

void PersonScore::Display(){
    cout << id << " " << name << " " << math << " " << English << " " << CS << endl;
}

int PersonScore::GetHigh(){
    int max = math;
    if (English > max) max = English;
    if (CS > max) max = CS;
    return max;
}

int PersonScore::GetLow(){
    int min = math;
    if (English < min) min = English;
    if (CS < min) min = CS;
    return min;
}

bool PersonScore::isMathPass(){
    return math >= 60;
}

bool PersonScore::isEnglishPass(){
    return English >= 60;
}

bool PersonScore::isCSPass(){
    return CS >= 60;
}