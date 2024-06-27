#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, double> unitFactors = {
    {"millimeters", 100},
    {"inches", 3.94},
    {"centimeters", 10},
    {"decimeters", 1},
    {"meters", 0.1},
    {"yards", 0.10936},
    {"feet", 0.328}
};

double convertUnit(const string& unit1, const string& unit2, double value) {

    double factor1 = unitFactors[unit1];
    double factor2 = unitFactors[unit2];

    return value * factor1 / factor2;
}

void processInput(const string& input, string& A, string& B, string& C, int& num) {
    vector<string> words;
    istringstream iss(input);
    string word;
    
    while (iss >> word) {
        words.push_back(word);
    }   
    
    A = words[2];
    B = words[6];
    C = words[5];
    num = stoi(C);
    
}


int main() {
    bool Continue = true;

    
    while(Continue){
        cout << "Please input:"<<endl;

        string input;
        getline(cin, input);

        string A, B, C;
        int num;

        processInput(input, A, B, C, num);


        double result = convertUnit(A, B, num);
        
        cout << result << endl;

        cout << "Go on?(y/n):";
        string response;
        cin >> response;

        if (response != "y" && response != "Y") {
            Continue = false;
        }
        cin.ignore(); 
    
    }


    return 0;
}