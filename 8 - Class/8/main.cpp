#include<iostream>
#include "class.h"

using namespace std;

int main(){
    char str1[10];
    char str2[10];
    char str3[10];
    cin>>str1>>str2>>str3;

    Calculator c1(str1);
    Calculator c2(str2);
    Calculator c3(str3);

    c1.print_total_expression();
    c1.print_self_expression();
    c1.print_value();

    cout<<endl;

    c1.combine(c2);
    c1.print_total_expression();
    c1.print_self_expression();
    c1.print_value();
    cout<<endl;

    c1.combine(c3).combine(c3).print_value();
    c1.print_total_expression();
    cout<<endl;

    return 0;
}