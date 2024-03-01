#include <iostream>
using namespace std;
 
bool solve(unsigned long long x, unsigned long long k) {
    if (x <= (k * (k - 1)) / 2) {
        return true;
    }
    return false;
}
 
int main() {
    unsigned long long n, k, x, t;
    scanf("%llu", &t);
    while (t--) {
        scanf("%llu %llu %llu", &n, &k, &x);
        if (solve(x, k))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}