#include<iostream>
using namespace std;

int Gcd(int a,int b){
    if(b == 0){
        return a;
    }else{
        return Gcd(b,a%b);
    }
}
int main()
{
    int m, n;
    
    cin >> m >> n;
    // Gcd()

    if(m<0 || n<=0){
        cout << "Input error!";
    }else{
        cout << m / Gcd(m,n)<<"/"<< n/Gcd(m,n);
    }
    return 0;
}