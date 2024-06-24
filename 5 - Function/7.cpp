#include<iostream>  
using namespace std; 

long long factorial(int n){
    if (n == 0){
        return 1;
    }else
        return n * factorial(n-1);
}
 
int main(){
	int n,m;
    cin >> n >> m;

    if (n<m){
        cout<<"wrong!";
    }else
        cout << factorial(n)/factorial(m)/factorial(n-m);
    return 0;
}