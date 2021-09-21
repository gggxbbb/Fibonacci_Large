#include <iostream>

using namespace std;

int a[10000] = {0};
int b[10000] = {0};
int t[10000] = {0};

int main() {
    int times;
    cout << "Which: ";
    cin >> times;
    if (times == 1 or times == 2) {
        cout << 0 << endl;
        return 0;
    }
    a[0] = 1;
    b[0] = 1;
    for (int time = 3; time <= times; time++) {
        for (int i = 0; i < 10000; i++) {
            t[i] += a[i] + b[i];
            if (t[i] >= 10) {
                t[i] -= 10;
                t[i + 1] += 1;
            }
        }
        for (int i = 0; i < 10000; i++) {
            a[i] = b[i];
            b[i] = t[i];
            t[i] = 0;
        }
    }
    cout << endl;
    bool opt = false;
    for (int i = 9999; i >= 0; i--) {
        if (b[i] != 0) {
            opt = true;
        }
        if (opt) {
            cout << b[i];
        }
    }
    cout << endl;
    return 0;
}
