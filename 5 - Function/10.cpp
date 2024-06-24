#include<iostream>
using namespace std;

int CountDigit(int number,int digit)
{
    int a,sum;
    sum = 0;
    while(number >0){
        a = number % 10;
        if (a == digit){
            sum += 1;
        }
        number /=10;    
    }
    return sum;

}

int main()
{
	int number,digit;
	cin>>number>>digit;
	cout << CountDigit(number,digit) <<endl;
	return 0;
}
