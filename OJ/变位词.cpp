#include <iostream> 
#include <vector> 
#include <map>
#include <string>
#include <algorithm>

using namespace std;

void merge(vector<string>& a, int p, int q, int r) {
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
            j++;
        }
    }
}

void merge_sort(vector<string>& a, int p, int r) {
    if (p < r) {
        int q = int((p + r) / 2);
        merge_sort(a, p, q);
        merge_sort(a, q + 1, r);
        merge(a, p, q, r);
    }
}

int main() {
    int n;
    cin >> n;
    map<string, pair<string, int>> savedInformations;
    string temp;
    string save;
    int num = 0;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        save = temp;
        sort(temp.begin(), temp.end());
        map<string, pair<string, int>>::iterator it = savedInformations.find(temp);
        if (it != savedInformations.end()) {
            savedInformations[temp].second++;
            if (save < savedInformations[temp].first) {
                savedInformations[temp].first = save;
            }
            if (savedInformations[temp].second == 2) {
                num++;
            }
        }
        else {
            savedInformations[temp].first = save;
            savedInformations[temp].second = 1;
        }
    }
    cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
    cout << num << endl;
    vector<string> result;
    for (map<string, pair<string, int>>::iterator i = savedInformations.begin(); i != savedInformations.end(); i++) {
        if (i->second.second >= 2) {
            result.push_back(i->second.first);
        }
    }
    merge_sort(result, 0, num - 1);
    for (int i = 0; i < num; ++i) {
        cout << result[i] << endl;
    }
    return 0;
}