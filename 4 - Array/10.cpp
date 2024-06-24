// 请在下方添加代码
/********** Begin *********/
#include <iostream>
using namespace std;

int main(){
    
    char str[81];

    cin.getline(str,80);

    char ch;
    cin.get(ch);
    
    int index = -1;
    int n = 0;

    while(str[n] != '\0'){
        if (str[n] == ch){
            index = n;
        }
       
        n += 1;
    }

    if(index != -1){
        cout << "Index="<<index;
    }else{
        cout << "Not Found";
    }
    
    
    
    return 0;
}
/********** End **********/