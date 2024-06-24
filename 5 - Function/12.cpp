#include<iostream>

using namespace std;

int Gcd(int a,int b){
    if (a == b){
        return a;
    }
    if (a > b){
        return Gcd(a - b,b);
    }
    return Gcd(a,b-a);
}
int main()
{
    int m,n;
    cin >> m >>n;

    if (m<=0 || n<= 0){
        cout << "Input error!";
    }else{
        cout << Gcd(m,n);
    }


	return 0;
}