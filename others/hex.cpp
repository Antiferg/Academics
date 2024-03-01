#include <iostream>
using namespace std;

string toHexDigit(int value) {
    if (value < 10) {
        return to_string(value);
    } else {
        char ch = 'A' + (value - 10);
        return string(1, ch);
    }
}

string rgbToHex(int r, int g, int b) {
    string hexCode = "#";
    hexCode += toHexDigit(r / 16) + toHexDigit(r % 16);
    hexCode += toHexDigit(g / 16) + toHexDigit(g % 16);
    hexCode += toHexDigit(b / 16) + toHexDigit(b % 16);
    return hexCode;
}

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    string hexCode = rgbToHex(r, g, b);
    cout << hexCode << std::endl;
    return 0;
}
