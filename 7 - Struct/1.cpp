#include <iostream>
#include <iomanip> // 用于输出时保持格式

using namespace std;

// 定义一个结构体来存储时间
struct Clock {
    int hour;
    int minute;
    int second;

    // 设置时间的函数
    void setTime(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    // 时间增加一秒的函数
    void increase() {
        second++;
        if (second >= 60) {
            second = 0;
            minute++;
            if (minute >= 60) {
                minute = 0;
                hour++;
                if (hour >= 24) {
                    hour = 0;
                }
            }
        }
    }

    // 显示时间的函数
    void showTime() const {
        cout << setw(2) << setfill('0') << hour << ":"
             << setw(2) << setfill('0') << minute << ":"
             << setw(2) << setfill('0') << second << endl;
    }
};

int main() {

    Clock clock1, clock2;

    
    int h1, m1, s1, h2, m2, s2;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

    
    clock1.setTime(h1, m1, s1);
    clock1.showTime();
    clock1.increase();
    clock1.showTime();

    
    clock2.setTime(h2, m2, s2);
    clock2.showTime();
    clock2.increase();
    clock2.showTime();

    return 0;
}
