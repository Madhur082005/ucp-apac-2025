/*
Technique: BST floor search via iterative traversal

Time Complexity: O(H)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

int getFloor(TreeNode* root, int key) {
    int ans = -1;

    while (root) {
        if (root->data == key) {
            return root->data;
        }

        if (root->data > key) {
            root = root->left;
        } else {
            ans = root->data;
            root = root->right;
        }
    }
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(16);

    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(17);
    root->right->right->right = new TreeNode(20);

    int t1 = 13;
    cout << "Test Case 1 (key=13): " << getFloor(root, t1) << endl;

    int t2 = 15;
    cout << "Test Case 2 (key=15): " << getFloor(root, t2) << endl;

    return 0;
}
