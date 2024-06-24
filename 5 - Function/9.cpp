#include<iostream>
using namespace std;

int Func(int n){
    for(int i = 999;i>=100;i--){
        if(n % i == 0){
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    // Func(n)
    if(n<1000||n>1000000){
        cout <<"Input error!";
    }else if (Func(n) == -1){
        cout << "Not found!";
    }else{
        cout << Func(n);
    }
    return 0;
}