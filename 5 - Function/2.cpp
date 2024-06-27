#include<iostream>
using namespace std;

bool perfectNumber(int n){
    int i = 1;
    int sum = 0;
    while (i < n){
        if (n % i == 0){
            sum += i;
        }
        i++;
    }
    if (sum == n){
        return true;
    }else{
        return false;
    }
    
}

int main()
{
    int m,n;
    cin>>m>>n;

    bool judging = false;

    while(m<=n){
        if(perfectNumber(m)){
            cout << m << " ";
            judging = true;
        }
        m += 1;
    }

    if(!judging){
        cout << -1;
    }
    
    
    return 0;
}
