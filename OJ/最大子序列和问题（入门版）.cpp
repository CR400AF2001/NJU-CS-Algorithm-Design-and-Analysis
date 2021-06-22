#include <iostream> 
using namespace std;

int main() {
    int a;
    int sum = 0;
    int max = 0;
    while (cin >> a) {
        sum += a;
        if (sum > max) {
            max = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
        if (cin.get() == '\n') {
            break;
        }
    }
    cout << max << endl;
    return 0;
}