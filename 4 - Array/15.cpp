#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string input;
    getline(cin,input);

    int num1,num2;
    char op;

    stringstream ss(input);
    ss >> num1 >> op >> num2;

    int result;

    switch(op){
        case '+':
            result = num1 + num2;
            break;
        
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        default:
            result = num1 / num2;
        
    }
    cout << input << "="<< result;

    return 0;
    

}