#include <iostream> 
#include <cstdio>
#include <vector>

using namespace std;

void fix_little_heap(vector<int>& a, int p) {
    int l = 2 * p + 1;
    int r = 2 * p + 2;
    int next = p;
    if (l < a.size() && a[l] < a[p]) {
        next = l;
    }
    if (r < a.size() && a[r] < a[p] && a[r] < a[l]) {
        next = r;
    }
    if (next != p) {
        int temp = a[p];
        a[p] = a[next];
        a[next] = temp;
        fix_little_heap(a, next);
    }
}


void fix_big_heap(vector<int>& a, int p) {
    int l = 2 * p + 1;
    int r = 2 * p + 2;
    int next = p;
    if (l<a.size() && a[l]>a[p]) {
        next = l;
    }
    if (r<a.size() && a[r]>a[p] && a[r] > a[l]) {
        next = r;
    }
    if (next != p) {
        int temp = a[p];
        a[p] = a[next];
        a[next] = temp;
        fix_big_heap(a, next);
    }
}

void up_little_heap(vector<int>& a) {
    int n = a.size() - 1;
    while (n > 0) {
        if (a[n] < a[int((n - 1) / 2)]) {
            int temp = a[int((n - 1) / 2)];
            a[int((n - 1) / 2)] = a[n];
            a[n] = temp;
            n = int((n - 1) / 2);
        }
        else {
            break;
        }
    }
}


void up_big_heap(vector<int>& a) {
    int n = a.size() - 1;
    while (n > 0) {
        if (a[n] > a[int((n - 1) / 2)]) {
            int temp = a[int((n - 1) / 2)];
            a[int((n - 1) / 2)] = a[n];
            a[n] = temp;
            n = int((n - 1) / 2);
        }
        else {
            break;
        }
    }
}


int main() {
    int num = 0;
    vector<int> littleHeap;
    vector<int> bigHeap;
    scanf("%d", &num);
    bigHeap.emplace_back(num);
    printf("%d ", num);
    while (scanf("%d", &num) == 1) {
        if (num < bigHeap[0]) {
            if (bigHeap.size() > littleHeap.size()) {
                littleHeap.emplace_back(bigHeap[0]);
                bigHeap[0] = num;
                fix_big_heap(bigHeap, 0);
                up_little_heap(littleHeap);
            }
            else {
                bigHeap.emplace_back(num);
                up_big_heap(bigHeap);
            }
        }
        else {
            if (bigHeap.size() > littleHeap.size()) {
                littleHeap.emplace_back(num);
                up_little_heap(littleHeap);
            }
            else {
                if (num <= littleHeap[0]) {
                    bigHeap.emplace_back(num);
                    up_big_heap(bigHeap);
                }
                else {
                    bigHeap.emplace_back(littleHeap[0]);
                    littleHeap[0] = num;
                    fix_little_heap(littleHeap, 0);
                    up_big_heap(bigHeap);
                }
            }
        }
        printf("%d ", bigHeap[0]);

    }
    return 0;
}