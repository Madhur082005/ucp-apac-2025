// Technique Used: Inorder DFS range validation
// Time Complexity: O(n)
// Space Complexity: O(h)
// Time Spent: 24 minutes 10 seconds

#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int v) : key(v), left(nullptr), right(nullptr) {}
};

bool check(Node* root, long long minVal, long long maxVal) {
    if (!root) return true;

    if (root->key <= minVal || root->key >= maxVal)
        return false;

    return check(root->left, minVal, root->key) &&
           check(root->right, root->key, maxVal);
}

bool isBST(Node* root) {
    return check(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    Node* t1 = new Node(10);
    t1->left = new Node(5);
    t1->right = new Node(20);
    t1->left->left = new Node(3);

    cout << isBST(t1) << endl;

    Node* t2 = new Node(10);
    t2->left = new Node(15);

    cout << isBST(t2) << endl;

    return 0;
}
