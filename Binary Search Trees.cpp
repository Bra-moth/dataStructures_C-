#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* root = nullptr;

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void insertNode(Node* current, int value) {
    if (value < current->data) {
        if (current->left == nullptr) {
            Node* newNode = createNode(value);
            current->left = newNode;
        } else {
            insertNode(current->left, value);
        }
    } else if (value > current->data) {
        if (current->right == nullptr) {
            Node* newNode = createNode(value);
            current->right = newNode;
        } else {
            insertNode(current->right, value);
        }
    }
}

void preOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void InOrder(Node* root) {
	if(root == NULL) return;
	
	
}	


void PostOrder(Node* root) {
	
}
	

int main() {
    int value;

    cout << "Enter the value for the root node: ";
    cin >> value;
    root = createNode(value);

    while (true) {
        cout << "Enter a value to insert (or -1 to stop): ";
        cin >> value;
        if (value == -1) break;
        insertNode(root, value);
    }

    cout << "Pre-order traversal: ";
    preOrder(root);
    cout << endl;

    return 0;
}
