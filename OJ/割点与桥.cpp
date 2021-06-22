#include <iostream> 
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct node {
    int num;
    int color;
    int discovertime;
    int back;
    int parent;
};

int newtime = 0;

void articulation_point_dfs(int now, int n, vector<int>* line, vector<int>& point, node* list) {
    list[now].color = 1;
    newtime++;
    list[now].discovertime = newtime;
    list[now].back = list[now].discovertime;
    for (int i = 0; i < (int)line[now].size(); ++i) {
        if (list[line[now][i]].color == 0) {
            list[line[now][i]].parent = now;
            articulation_point_dfs(line[now][i], n, line, point, list);
            if (now != 0 && list[line[now][i]].back >= list[now].discovertime) {
                point.push_back(now);
            }
            if (list[line[now][i]].back < list[now].back) {
                list[now].back = list[line[now][i]].back;
            }
        }
        else {
            if (list[line[now][i]].color == 1 && list[now].parent != line[now][i]) {
                if (list[line[now][i]].discovertime < list[now].back) {
                    list[now].back = list[line[now][i]].discovertime;
                }
            }
        }
    }
}

void root_articulation_point_dfs(int now, int n, vector<int>* line, vector<int>& point, node* list) {
    list[now].color = 1;
    newtime++;
    list[now].discovertime = newtime;
    list[now].back = list[now].discovertime;
    for (int i = 0; i < (int)line[now].size(); ++i) {
        if (list[line[now][i]].color == 0) {
            list[line[now][i]].parent = now;
            root_articulation_point_dfs(line[now][i], n, line, point, list);
            if (now == 0 && list[line[now][i]].back >= list[now].discovertime) {
                point.push_back(now);
            }
            if (list[line[now][i]].back < list[now].back) {
                list[now].back = list[line[now][i]].back;
            }
        }
        else {
            if (list[line[now][i]].color == 1 && list[now].parent != line[now][i]) {
                if (list[line[now][i]].discovertime < list[now].back) {
                    list[now].back = list[line[now][i]].discovertime;
                }
            }
        }
    }
}

void bridge_dfs(int now, int n, vector<int>* line, vector<pair<int, int>>& bridge, node* list) {
    list[now].color = 1;
    newtime++;
    list[now].discovertime = newtime;
    list[now].back = list[now].discovertime;
    for (int i = 0; i < (int)line[now].size(); ++i) {
        if (list[line[now][i]].color == 0) {
            list[line[now][i]].parent = now;
            bridge_dfs(line[now][i], n, line, bridge, list);
            if (list[line[now][i]].back < list[now].back) {
                list[now].back = list[line[now][i]].back;
            }
            if (list[line[now][i]].back > list[now].discovertime) {
                if (now <= line[now][i]) {
                    bridge.push_back(pair<int, int>(now, line[now][i]));
                }
                else {
                    bridge.push_back(pair<int, int>(line[now][i], now));
                }
            }
        }
        else {
            if (list[line[now][i]].color == 1 && list[now].parent != line[now][i]) {
                if (list[line[now][i]].discovertime < list[now].back) {
                    list[now].back = list[line[now][i]].discovertime;
                }
            }
        }
    }
}

int main() {
    int n = 0;
    cin >> n;
    vector<int>* line = new vector<int>[n];
    node* list = new node[n];
    for (int i = 0; i < n; ++i) {
        list[i].num = i;
        list[i].color = 0;
    }
    int a = 0, b = 0;
    while (cin >> a && cin >> b) {
        line[a].push_back(b);
        line[b].push_back(a);
    }
    vector<int> point;
    newtime = 0;
    list[0].parent = -1;
    articulation_point_dfs(0, n, line, point, list);
    for (int i = 0; i < n; ++i) {
        list[i].color = 0;
    }
    list[1].parent = -1;
    newtime = 0;
    root_articulation_point_dfs(1, n, line, point, list);
    for (int i = 0; i < (int)point.size(); ++i) {
        for (int j = 0; j < (int)point.size() - 1; ++j) {
            if (point[j] > point[j + 1]) {
                int temppoint = point[j];
                point[j] = point[j + 1];
                point[j + 1] = temppoint;
            }
        }
    }
    newtime = 0;
    for (int i = 0; i < n; ++i) {
        list[i].color = 0;
    }
    vector<pair<int, int>> bridge;
    list[0].parent = -1;
    bridge_dfs(0, n, line, bridge, list);
    for (int i = 0; i < (int)bridge.size(); ++i) {
        for (int j = 0; j < (int)bridge.size() - 1; ++j) {
            if (bridge[j].first < bridge[j + 1].first) {
                continue;
            }
            else if (bridge[j].first == bridge[j + 1].first) {
                if (bridge[j].second <= bridge[j + 1].second) {
                    continue;
                }
            }
            pair<int, int> temppair = bridge[j];
            bridge[j] = bridge[j + 1];
            bridge[j + 1] = temppair;
        }
    }
    cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
    for (int i = 0; i < (int)point.size(); ++i) {
        cout << point[i] << endl;
    }
    for (int i = 0; i < (int)bridge.size(); ++i) {
        cout << bridge[i].first << " " << bridge[i].second << endl;
    }
    return 0;
}