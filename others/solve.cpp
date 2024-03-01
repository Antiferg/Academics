#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;
    cin.ignore();

    string num_list;
    getline(cin, num_list);

    stringstream ss(num_list);
    int currentNum;
    vector<int> numbers;

    while (ss >> currentNum) {
        numbers.push_back(currentNum);
    }

    bool check = true;
    for (int i = 0; i < numbers.size(); i++) {
        if (num % numbers[i] != 0) {
            check = false;
            break;
        }
    }
    if (check) {
        cout << "divisible by all" << endl;
    } else {
        cout << "not divisible by all" << endl;
    }

    return 0;
}