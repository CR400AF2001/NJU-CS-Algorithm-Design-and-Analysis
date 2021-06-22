#include <iostream> 
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void dfs(int u, vector<vector<int>>* line, int** num, int* color, int n) {
    color[u] = 1;
    int choose = 0;
    int notchoose = 0;
    for (int i = 1; i < (*line)[u].size(); ++i) {
        if (color[(*line)[u][i]] == 0) {
            dfs((*line)[u][i], line, num, color, n);
        }
        choose += num[(*line)[u][i]][0] <= num[(*line)[u][i]][1] ? num[(*line)[u][i]][0] : num[(*line)[u][i]][1];
        notchoose += num[(*line)[u][i]][0];
    }
    num[u][0] = choose + 1;
    num[u][1] = notchoose;
    color[u] = 2;
}

int main() {
    int n = 0;
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
    int** num = new int*[n];
    int* color = new int[n];
    for (int i = 0; i < n; ++i) {
        num[i] = new int[2];
        color[i] = 0;
    }
    dfs(0, &line, num, color, n);
    cout << "I have read the rules about plagiarism punishment" << endl;
    if (num[0][0] <= num[0][1]) {
        cout << num[0][0] << endl;
    }
    else {
        cout << num[0][1] << endl;
    }
    
	return 0;
}