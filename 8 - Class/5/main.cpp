#include <iostream>
#include "class.h"


using namespace std;

int main(){
    BigInteger num1, num2;
    num1.read();
    num2.read();

    BigInteger sum = add(num1, num2);

    cout << sum;

    return 0;



    return 0;
}