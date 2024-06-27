// 请在下方添加代码
/********** Begin *********/
#include <iostream>
using namespace std;

int main()
{
    int n;
    
    cin >> n;
    cin.ignore(); // 忽略输入缓冲区中的换行符

    string inputText = "";
    
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        inputText += line;
    }

    int letterCount = 0;
    int digitCount = 0;
    int otherCount = 0;
    for (int i = 0; i < inputText.length(); ++i) {
        if (isalpha(inputText[i])) {
            letterCount++;
        } else if (isdigit(inputText[i])) {
            digitCount++;
        } else if (!isspace(inputText[i])) {
            otherCount++;
        }
    }


    cout << "英文字母：" << letterCount << "\n数字："<<digitCount<<"\n其他字符："<<otherCount;
	
    
    
    return 0;
}
/********** End **********/