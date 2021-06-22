#include <iostream> 
using namespace std;

int a[5000000];

int partition(int a[], int p, int r) {
    int pivot = a[r];
    int i = p - 1;
    for (int j = p; j < r; ++j) {
        if (a[j] < pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[r];
    a[r] = temp;
    return i + 1;
}

void quick_sort(int a[], int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        quick_sort(a, p, q - 1);
        quick_sort(a, q + 1, r);
    }
}

int main() {
    int k, n;
    cin >> k >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    quick_sort(a, 0, n - 1);
    int mid;
    if (n % 2 == 1) {
        mid = (n - 1) / 2;
    }
    else {
        mid = n / 2 - 1;
    }
    cout << a[mid - k];
    for (int i = mid - k + 1; i <= mid + k; ++i) {
        cout << ' ' << a[i];
    }
    return 0;
}