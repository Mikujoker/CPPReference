#include <iostream>
using namespace std;

int main()
{
    char str1[20];
    char str2[20];

    cin.getline(str1,20);
    cin.getline(str2,20);

    /*Start your code here*/
    for (int i = 0; i < 20; i++)
    {
        if (str1[i] == '\0' || str2[i] == '\0')
            break;
        swap(str1[i], str2[i]);
    }
    cout << str1 << endl;
    cout << str2 << endl;

    /*end your code*/
    return 0;
}