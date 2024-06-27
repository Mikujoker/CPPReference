#include<iostream>
using namespace std;

void valid(int n){
    cout << n << " ";
    if (n == 1){
        return;
    }else if(n%2 == 0){
        valid(n / 2);
    }else{
        valid(n * 3 + 1);
    }
    
}

int main()
{
    int n;
    cin>>n;
    valid(n);
    return 0;
}
