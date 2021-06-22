#include <iostream> 
#include <vector>
#include <queue>
#include <string>

using namespace std;

void fix_little_heap(pair<int, int>* a, int p, int size, int* index) {
    int l = 2 * p + 1;
    int r = 2 * p + 2;
    int next = p;
    if (l < size && a[l] < a[p]) {
        next = l;
    }
    if (r < size && a[r] < a[next]) {
        next = r;
    }
    if (next != p) {
        pair<int, int> temp = a[p];
        a[p] = a[next];
        a[next] = temp;
        index[a[p].second] = p;
        index[a[next].second] = next;
        fix_little_heap(a, next, size, index);
    }
}

void up_little_heap(pair<int, int>* a, int n, int* index) {
    while (n > 0) {
        if (a[n] < a[int((n - 1) / 2)]) {
            pair<int, int> temp = a[int((n - 1) / 2)];
            a[int((n - 1) / 2)] = a[n];
            a[n] = temp;
            index[a[int((n - 1) / 2)].second] = int((n - 1) / 2);
            index[a[n].second] = n;
            n = int((n - 1) / 2);
        }
        else {
            break;
        }
    }
}

int main() {
    int n = 0;
    cin >> n;
    vector<pair<int, int>>* line = new vector<pair<int, int>>[n];
    int a = 0, b = 0, c = 0;
    while (cin >> a && cin >> b && cin >> c) {
        line[a].emplace_back(pair<int, int>(c, b));
        line[b].emplace_back(pair<int, int>(c, a));
    }
    pair<int, int> *nodeque = new pair<int, int>[n];
    int* seen = new int[n];
    int* index = new int[n];
    for (int i = 0; i < n; ++i) {
        seen[i] = 0;
        index[i] = -1;
    }
    int mst = 0;
    int size = 0;
    nodeque[size] = pair<int, int>(0, 0);
    size++;
    seen[0] = 1;
    index[0] = 0;
    while (size != 0) {
        int v = nodeque[0].second;
        mst += nodeque[0].first;
        seen[v] = 2;
        index[nodeque[0].second] = -1;
        nodeque[0] = nodeque[size - 1];
        index[nodeque[0].second] = 0;
        size--;
        fix_little_heap(nodeque, 0, size, index);
        for (int i = 0; i < line[v].size(); ++i) {
            int newweight = line[v][i].first;
            if (seen[line[v][i].second] == 0) {
                seen[line[v][i].second] = 1;
                nodeque[size] = pair<int, int>(newweight, line[v][i].second);
                index[line[v][i].second] = size;
                size++;
                up_little_heap(nodeque, size - 1, index);
            }
            else if (seen[line[v][i].second] == 1) {
                if (newweight < nodeque[index[line[v][i].second]].first) {
                    nodeque[index[line[v][i].second]].first = newweight;
                    up_little_heap(nodeque, index[line[v][i].second], index);
                }
            }
        }
    }
    cout << mst << endl;
    return 0;
}