// Time Complexity:
// min: O(log n)
// max: O(log n)
// contains: O(log n)
// insert: O(log n)
// delete: O(log n)
//
// Space Complexity: O(1) auxiliary (ignoring recursion stack)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertNode(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->data) node->left = insertNode(node->left, value);
        else if (value > node->data) node->right = insertNode(node->right, value);
        return node;
    }

    bool containsNode(Node* node, int value) {
        if (!node) return false;
        if (value < node->data) return containsNode(node->left, value);
        if (value > node->data) return containsNode(node->right, value);
        return true;
    }

    Node* findMinNode(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int value) {
        if (!node) return nullptr;
        if (value < node->data) node->left = deleteNode(node->left, value);
        else if (value > node->data) node->right = deleteNode(node->right, value);
        else {
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }
            if (!node->left) {
                Node* nextNode = node->right;
                delete node;
                return nextNode;
            }
            if (!node->right) {
                Node* nextNode = node->left;
                delete node;
                return nextNode;
            }
            Node* successor = findMinNode(node->right);
            node->data = successor->data;
            node->right = deleteNode(node->right, successor->data);
        }
        return node;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    int min() {
        Node* current = root;
        while (current && current->left) current = current->left;
        return current ? current->data : -1;
    }

    int max() {
        Node* current = root;
        while (current && current->right) current = current->right;
        return current ? current->data : -1;
    }

    bool contains(int value) {
        return containsNode(root, value);
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }

    void printInorder(Node* node) {
        if (!node) return;
        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    }

    Node* getRoot() {
        return root;
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);

    bst.printInorder(bst.getRoot());
    cout << "\n";

    cout << bst.contains(7) << "\n";
    cout << bst.contains(20) << "\n";

    cout << bst.min() << "\n";
    cout << bst.max() << "\n";

    bst.remove(10);

    bst.printInorder(bst.getRoot());
    cout << "\n";

    return 0;
}
