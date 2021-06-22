#include <iostream> 
#include <vector>

using namespace std;

#define max(a,b) (a > b ? a : b)

struct treenode {
    int num;
    treenode* left;
    treenode* right;
};

treenode* create(int pre[], int in[], int highpre, int lowpre, int highin, int lowin) {
    if (highpre < lowpre) {
        return NULL;
    }
    treenode* root = new treenode;
    root->num = pre[lowpre];
    if (highpre == lowpre) {
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    int i = lowin;
    while (in[i] != pre[lowpre]) {
        i++;
    }
    root->left = create(pre, in, lowpre + i - lowin, lowpre + 1, i - 1, lowin);
    root->right = create(pre, in, highpre, lowpre + i - lowin + 1, highin, i + 1);
    return root;
}

int dfs(treenode* root, int& maxlength) {
    int max = 0;
    if (root->left == NULL && root->right == NULL) {
        max = 0;
    }
    else if (root->left == NULL) {
        max = dfs(root->right, maxlength) + 1;
        if (max > maxlength) {
            maxlength = max;
        }
    }
    else if (root->right == NULL) {
        max = dfs(root->left, maxlength) + 1;
        if (max > maxlength) {
            maxlength = max;
        }
    }
    else {
        int leftlen = dfs(root->left, maxlength);
        int rightlen = dfs(root->right, maxlength);
        max = max(leftlen, rightlen) + 1;
        if (leftlen + rightlen + 2 > maxlength) {
            maxlength = leftlen + rightlen + 2;
        }
    }
    return max;
}


int main() {
    int n = 0;
    cin >> n;
    int* pre = new int[n];
    int* in = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> pre[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
    }
    treenode* root = create(pre, in, n - 1, 0, n - 1, 0);
    int maxdepth = 0;
    int maxlength = 0;
    maxdepth = dfs(root, maxlength);
    cout << "I have read the rules about plagiarism punishment" << endl;
    cout << maxdepth << endl;
    cout << maxlength << endl;
    return 0;
}