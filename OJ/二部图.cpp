#include <iostream> 
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n = 0;
    int max = 0;
    int temp = 0;
    int a = 0;
    int line[1000][1000] = { 0 };
    int num = 0;
    while (n <= max) {
        string strtemp;
        getline(cin, strtemp);
        int length = strtemp.length();
        for (int i = 0; i < length; ++i) {
            bool flag = false;
            if (i == 0) {
                a = 0;
                while (strtemp[i] != ' ') {
                    a = 10 * a + int(strtemp[i] - '0');
                    i++;
                }
            }
            else {
                num = 0;
                while (strtemp[i] != ' ') {
                    flag = true;
                    num = 10 * num + int(strtemp[i] - '0');
                    i++;
                }
            }
            if (flag) {
                line[a][num] = 1;
                if (num >= max) {
                    max = num;
                }
            }
        }
        n++;
    }
    queue<int> nodequeue;
    nodequeue.push(0);
    int* color = new int[n];
    color[0] = 1;
    int* group = new int[n];
    group[0] = 1;
    for (int i = 1; i < n; ++i) {
        color[i] = 0;
        group[i] = 0;
    }
    while (!nodequeue.empty()) {
        temp = nodequeue.front();
        nodequeue.pop();
        for (int i = 0; i < n; ++i) {
            if (line[temp][i] == 1) {
                if (color[i] == 0) {
                    color[i] = 1;
                    nodequeue.push(i);
                }
                if (group[temp] == 0) {
                    group[i] = 1;
                }
                else {
                    group[i] = 0;
                }
            }
        }
        color[temp] = 2;
    }
    cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
    for (int i = 0; i < n; ++i) {
        if (group[i] == 1) {
            cout << i << endl;
        }
    }
    return 0;
}