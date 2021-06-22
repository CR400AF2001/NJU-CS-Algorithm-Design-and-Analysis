#include <iostream> 
#include <vector> 
#include <string.h>
using namespace std;

void merge(vector<string>& a, int p, int q, int r, long long* result) {
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<string> left(n1 + 1);
    vector<string> right(n2 + 1);
    for (int i = 0; i < n1; ++i) {
        left[i] = a[p + i];
    }
    for (int j = 0; j < n2; ++j) {
        right[j] = a[q + j + 1];
    }
    left[n1] = "zzzzzzzzzzzz";
    right[n2] = "zzzzzzzzzzzz";
    int i = 0, j = 0;
    for (int k = p; k <= r; ++k) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        }
        else {
            a[k] = right[j];
            *result += ((long long)(n1)-(long long)(i));
            j++;
        }
    }
}

void merge_sort(vector<string>& a, int p, int r, long long* result) {
    if (p < r) {
        int q = int((p + r) / 2);
        merge_sort(a, p, q, result);
        merge_sort(a, q + 1, r, result);
        merge(a, p, q, r, result);
    }
}

int main() {
    int n;
    long long result = 0;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    merge_sort(a, 0, n - 1, &result);
    cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
    cout << result << endl;
    return 0;
}