// 请在下方添加代码
/********** Begin *********/
#include<iostream>

using namespace std;
int main() 
{
  char ch;
  cin >> ch;

  if ('a'<= ch && 'z'>=ch)
      ch -= 32;
      else if('A'<=ch && 'Z'>= ch)
      ch +=32;

  cout << ch;





  return 0;
}
/********** End **********/

