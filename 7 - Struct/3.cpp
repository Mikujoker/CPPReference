#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Date {
    int year, month, day;
};

struct Student {
    string name;
    Date birthday;
    string phoneNumber;
    string address;

    // 这个函数用于比较两个学生的年龄，用于排序
    bool operator<(const Student& other) const {
        if (birthday.year == other.birthday.year) {
            if (birthday.month == other.birthday.month) {
                return birthday.day > other.birthday.day;
            }
            return birthday.month > other.birthday.month;
        }
        return birthday.year > other.birthday.year;
    }
};

void printStudent(const Student& student) {
    cout << student.name << " " << student.birthday.year << " " << student.birthday.month << " " << student.birthday.day << " " << student.phoneNumber << " " << student.address << endl;
}

int main() {
    int n;
    cin >> n;

    vector<Student> students(n);

    for (int i = 0; i < n; ++i) {
        cin >> students[i].name >> students[i].birthday.year >> students[i].birthday.month >> students[i].birthday.day >> students[i].phoneNumber;
        cin.ignore(); // 忽略电话号码后的空格
        getline(cin, students[i].address); // 读取包含空格的地址
    }

    // 按生日从小到大排序，即从年长到年轻
    sort(students.begin(), students.end());

    // 输出排序后的学生信息
    for (const auto& student : students) {
        printStudent(student);
    }

    return 0;
}

