#include <iostream> 
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

void dfs(int now, vector<vector<int>> *line, int* color, stack<int> *nodestack) {
    color[now] = 1;
    for (int i = 0; i < (*line)[now].size(); ++i) {
        if (color[(*line)[now][i]] == 0) {
            dfs((*line)[now][i], line, color, nodestack);
        }
    }
    (*nodestack).push(now);
    color[now] = 2;
}

void second_dfs(int now, vector<int>* line, int* color, int num) {
    color[now] = 1;
    for (int i = 0; i < line[now].size(); ++i) {
        if (color[line[now][i]] == 0) {
            second_dfs(line[now][i], line, color, num);
        }
    }
    color[now] = num;
}

void third_dfs(int now, vector<vector<int>> *line, int* color, int num) {
    color[now] = 1;
    for (int i = 0; i < (*line)[now].size(); ++i) {
        if (color[(*line)[now][i]] == 0) {
            third_dfs((*line)[now][i], line, color, num);
        }
    }
    color[now] = num;
}

int main() {
    int n = 0;
    int max = 0;
    vector<vector<int>> line;
    int a = 0;
    string input;
    while (getline(cin, input)) {
        vector<int> templist;
        stringstream input_stream(input);
        int a = 0;
        while (input_stream >> a) {
            templist.push_back(a);
        }
        line.push_back(templist);
        n++;
    }
    stack<int> nodestack;
    int* color = new int[n];
    for (int i = 0; i < n; ++i) {
        color[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            dfs(i, &line, color, &nodestack);
        }
    }
    vector<int>* transpose = new vector<int>[n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < line[i].size(); ++j) {
            transpose[line[i][j]].push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        color[i] = 0;
    }
    int num = 1;
    vector<int> condensation;
    while (!nodestack.empty()) {
        int v = nodestack.top();
        nodestack.pop();
        if (color[v] == 0) {
            num++;
            condensation.push_back(v);
            second_dfs(v, transpose, color, num);
        }
    }
    int* newcolor = new int[n];
    vector<int> resultnode;
    for (int i = 0; i < condensation.size(); ++i) {
        for (int j = 0; j < n; ++j) {
            newcolor[j] = 0;
        }
        third_dfs(condensation[i], &line, newcolor, 2);
        int tempsum = 0;
        for (int j = 0; j < n; ++j) {
            if (newcolor[j] == 2) {
                tempsum++;
            }
        }
        if (tempsum > max) {
            max = tempsum;
            resultnode.clear();
            resultnode.push_back(condensation[i]);
        }
        else if (tempsum == max) {
            resultnode.push_back(condensation[i]);
        }
    }
    max--;
    cout << "I have read the rules about plagiarism punishment" << endl;
    cout << max << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < resultnode.size(); ++j) {
            if (color[i] == color[resultnode[j]]) {
                cout << i << " ";
                break;
            }
        }
    }
    cout << endl;
    return 0;
}