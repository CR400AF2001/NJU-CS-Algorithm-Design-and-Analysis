#include <iostream> 
using namespace std;

int main() {
    int n, c;
    cin >> n;
    int a[1000];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i] + a[j] == c && a[i] < a[j]) {
                cout << a[i] << " " << a[j] << endl;
            }
            if (a[i] + a[j] > c) {
                break;
            }
        }
    }
    return 0;
}