// Technique Used: DFS (recursive copy)
// Time Complexity: O(n)
// Space Complexity: O(h)
// Time Spent: 21 minutes 05 seconds  

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* leftChild;
    Node* rightChild;

    Node(int x) : val(x), leftChild(nullptr), rightChild(nullptr) {}
};

Node* clone(Node* root) {
    if (root == nullptr)
        return nullptr;

    Node* temp = new Node(root->val);

    // clone left then right
    temp->leftChild = clone(root->leftChild);
    temp->rightChild = clone(root->rightChild);

    return temp;
}

void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->leftChild);
    cout << root->val << " ";
    inorder(root->rightChild);
}

int main() {
    Node* root = new Node(10);
    root->leftChild = new Node(5);
    root->rightChild = new Node(20);
    root->leftChild->leftChild = new Node(3);

    Node* newTree = clone(root);

    inorder(root); cout << endl;
    inorder(newTree); cout << endl;

    return 0;
}
