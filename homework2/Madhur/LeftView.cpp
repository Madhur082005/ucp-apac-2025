// Technique: BFS level tracking (Left View)
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : key(x), left(nullptr), right(nullptr) {}
};

vector<int> getLeftView(TreeNode* root) {
    vector<int> view;
    if (!root) return view;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();

        // first node in current level
        view.push_back(q.front()->key);

        while (sz--) {
            TreeNode* cur = q.front();
            q.pop();

            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
    return view;
}

TreeNode* buildTree(const vector<int>& arr) {
    if (arr.empty()) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int idx = 1;
    while (idx < arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        if (idx < arr.size() && arr[idx] != -1) {
            node->left = new TreeNode(arr[idx]);
            q.push(node->left);
        }
        idx++;

        if (idx < arr.size() && arr[idx] != -1) {
            node->right = new TreeNode(arr[idx]);
            q.push(node->right);
        }
        idx++;
    }
    return root;
}

void printVec(const vector<int>& v) {
    for (int x : v) {
        cout << x;
    }
}

int main() {
    vector<int> t1 = {7, 8, 20, 3, 9, 13, 14, -1, -1, -1, -1, -1, -1, 15};
    TreeNode* r1 = buildTree(t1);
    vector<int> ans1 = getLeftView(r1);
    printVec(ans1);
    cout << endl;

    vector<int> t2 = {7, 20, 4, 15, 6, 8, 11};
    TreeNode* r2 = buildTree(t2);
    vector<int> ans2 = getLeftView(r2);
    printVec(ans2);

    return 0;
}
