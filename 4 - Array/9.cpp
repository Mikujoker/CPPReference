// 请在下方添加代码
/********** Begin *********/
#include <iostream>
#include <string>
using namespace std;

int main(){
    int i = 0;
    char str[80];

    cin.getline(str,80);
    

    string vowels = "AEIOUaeiou";
    int count = 0;
    for (char n : str) {
        for (char v : vowels) {
            if (n == v) {
                count++;
                break;
            }
        }
    }

    cout << "Count="<<count;
    
	
	
	
    return 0;
}
/********** End **********/