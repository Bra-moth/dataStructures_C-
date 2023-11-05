#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* root = nullptr; // Use nullptr instead of NULL

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr; // Use nullptr instead of NULL
    newNode->right = nullptr; // Use nullptr instead of NULL
    return newNode;
}

void addNodeLeft(Node* current) {
    int value;
    cout << "Enter a value: ";
    cin >> value;

    Node* leftNode = createNode(value);
    current->left = leftNode;
}

void addNodeRight(Node* current) {
    int value;
    cout << "Enter a value: ";
    cin >> value;

    Node* rightNode = createNode(value);
    current->right = rightNode;
}

void preOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << endl;
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    root = createNode(1); // Create the root node

    addNodeLeft(root); // Add left child for the root
    addNodeRight(root); // Add right child for the root

    Node* leftNode = root->left;
    Node* rightNode = root->right;

    addNodeLeft(leftNode); // Add left child for the left child of the root
    addNodeRight(leftNode); // Add right child for the left child of the root

    addNodeLeft(rightNode); // Add left child for the right child of the root
    addNodeRight(rightNode); // Add right child for the right child of the root

    preOrder(root);

    return 0;
}
