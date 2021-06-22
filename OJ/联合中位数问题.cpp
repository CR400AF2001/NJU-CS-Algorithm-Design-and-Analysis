#include <iostream> 
#include <cstdio>
#include <vector>

using namespace std;


int main() {
    int n = 0;
    scanf("%d", &n);
    vector<int> a(n);
    vector<int> b(n);
    int temp = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        a[i] = temp;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        b[i] = temp;
    }
    if (a[n - 1] < b[0]) {
        printf("%d\n", a[n - 1]);
        return 0;
    }
    else if (b[n - 1] < a[0]) {
        printf("%d\n", b[n - 1]);
        return 0;
    }
    int higha = n - 1;
    int lowa = 0;
    bool found = false;
    while (lowa <= higha) {
        int mida = (higha + lowa) / 2;
        int highb = n - 1;
        int lowb = 0;
        int midb = 0;
        while (lowb <= highb) {
            midb = (highb + lowb) / 2;
            if (midb == n - 1) {
                break;
            }
            else {
                if (b[midb] < a[mida] && a[mida] < b[midb + 1]) {
                    break;
                }
                else if (b[midb] > a[mida]) {
                    highb = midb - 1;
                    if (midb == 0) {
                        midb--;
                    }
                }
                else {
                    lowb = midb + 1;
                }
            }
        }
        if (midb + mida + 2 == n) {
            printf("%d\n", a[mida]);
            found = true;
            break;
        }
        else if (midb + mida + 2 > n) {
            higha = mida - 1;
        }
        else {
            lowa = mida + 1;
        }
    }
    if (!found) {
        int highb = n - 1;
        int lowb = 0;
        while (lowb <= highb) {
            int midb = (highb + lowb) / 2;
            int higha = n - 1;
            int lowa = 0;
            int mida = 0;
            while (lowa <= higha) {
                mida = (higha + lowa) / 2;
                if (mida == n - 1) {
                    break;
                }
                else {
                    if (a[mida] < b[midb] && b[midb] < a[mida + 1]) {
                        break;
                    }
                    else if (a[mida] > b[midb]) {
                        higha = mida - 1;
                        if (mida == 0) {
                            mida--;
                        }
                    }
                    else {
                        lowa = mida + 1;
                    }
                }
            }
            if (mida + midb + 2 == n) {
                printf("%d\n", b[midb]);
                found = true;
                break;
            }
            else if (mida + midb + 2 > n) {
                highb = midb - 1;
            }
            else {
                lowb = midb + 1;
            }
        }
    }
    return 0;
}