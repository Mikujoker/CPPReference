// 请在下方添加代码
/********** Begin *********/
#include<iostream>

using namespace std;
int main() 
{
  char s;
  cin >> s;
  switch (s) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
          cout << "vowel" << endl;
          break;
      default:
          cout << "consonant" << endl;
          break;
  }





  return 0;
}
/********** End **********/

