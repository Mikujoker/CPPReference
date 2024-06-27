#include<iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if(n == 1){
        return false;
    }
    int k = 2;
    while (k <= sqrt(n)){
        if (n % k == 0){
            return false;
        }
        k += 1;
    }
    return true;
    
}

int main()
{
    int m , n;
    cin >> m >> n;

    int sum = 0;

    while(m <= n){
        if(isPrime(m)){
            sum += 1;
        }
        m++;
    }

    cout << sum;
    return 0;
}
