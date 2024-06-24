// 请在下方添加代码
/********** Begin *********/
#include<iostream>

using namespace std;
int main() 
{
  int n;
  cin >> n;

  int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31,30, 31};
  int dayCount[7] = {0}; // 记录每个星期几出现的次数

  int dayOfWeek = 0; // 1900年1月1日是星期一
  for (int year = 1900; year < 1900 + n; ++year) {
      for (int month = 0; month < 12; ++month) {
          int days = daysInMonth[month];
          if (month == 1 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
              days = 29; // 闰年2月
          }
          for (int day = 1; day <= days; ++day) {
              if (day == 13) {
                  dayCount[dayOfWeek]++;
              }
              dayOfWeek = (dayOfWeek + 1) % 7;
            }
        }
    }

  for (int i = 0; i < 7; ++i) {
      cout << dayCount[i] << " ";
  }




  return 0;
}
/********** End **********/

