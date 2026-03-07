#pragma once
struct Node {
    int info;
    Node* left = nullptr;
    Node* right = nullptr;
};

void preOrderTraversal(Node* node);
void inOrderTraversal(Node* node);
void postOrderTraversal(Node* node);
void freeMemory(Node* node);
int getHeight(Node* node);
int getBalance(Node* node);
Node* rightRotate(Node* node);
Node* leftRotate(Node* node);
Node* insert(Node* node, int info);
Node* getMinValueNode(Node* node);
Node* deleteNode(Node* root, int key);