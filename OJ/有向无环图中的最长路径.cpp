#include <iostream> 
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int no;

void dfs(int u, vector<pair<int, int>>** line, int* num, int* color, int n) {
    color[u] = 1;
    for (int i = 0; i < (*line)[u].size(); ++i) {
        if (color[(*line)[u][i].first] == 0) {
            dfs((*line)[u][i].first, line, num, color, n);
        }
    }
    num[no] = u;
    no--;
    color[u] = 2;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    vector<pair<int, int>>* line = new vector<pair<int, int>>[n];
    int a = 0, b = 0, c = 0;
    while (scanf("%d %d %d", &a, &b, &c) == 3) {
        line[a].emplace_back(pair<int, int>(b, c));
    }
    int* num = new int[n];
    int* len = new int[n];
    int* color = new int[n];
    for (int i = 0; i < n; ++i) {
        color[i] = 0;
        len[i] = 0;
    }
    no = n - 1;
    dfs(0, &line, num, color, n);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < line[num[i]].size(); ++j) {
            if (len[num[i]] + line[num[i]][j].second > len[line[num[i]][j].first]) {
                len[line[num[i]][j].first] = len[num[i]] + line[num[i]][j].second;
            }
        }
    }
    cout << "I have read the rules about plagiarism punishment" << endl;   
    for (int i = 1; i < n; ++i) {
        cout << len[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    return 0;
}