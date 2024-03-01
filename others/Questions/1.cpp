#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;

    int k;
    cin >> k;

    int n = input.length();
    string output(k, ' ');

    int j = 0;
    for (int i = n - k; i < n; i++) {
        output[j] = input[i];
        j++;
    }

    for (int l = 0; l < n - k; l++, j++) {
        output[j] = input[l];
    }

    cout << output << endl;

    return 0;
}