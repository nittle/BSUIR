#include "utils.h"
#include "avl.h"


// Root left right
void preOrderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }

    print(node->info, ' ');
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

// Left root right
void inOrderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }

    inOrderTraversal(node->left);
    print(node->info, ' ');
    inOrderTraversal(node->right);
}

// Left right root
void postOrderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }

    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    print(node->info, ' ');
}

void freeMemory(Node* node) {
    if (node == nullptr) return;

    freeMemory(node->left);
    freeMemory(node->right);
    delete node;
}

int getHeight(Node* node) {
    if (node == nullptr) return 0;

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    int max = leftHeight > rightHeight ? leftHeight : rightHeight;

    return 1 + max;
}

int getBalance(Node* node) {
    if (node == nullptr)
        return 0;

    return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    return x; // Return new root
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    return y; // Return new root
}

Node* insert(Node* node, int info) {
    if (node == nullptr) {
        Node* newNode = new Node();
        newNode->info = info;
        return newNode;
    }

    if (info < node->info) {
        node->left = insert(node->left, info);
    }
    else if (info > node->info) {
        node->right = insert(node->right, info);
    }
    else {
        return node;
    }

    // Balancing
    int balance = getBalance(node);

    // Left left
    if (balance > 1 && getBalance(node->left) >= 0) {
        return rightRotate(node);
    }
    // Left right
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right right
    if (balance < -1 && getBalance(node->right) <= 0) {
        return leftRotate(node);
    }
    // Right left
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// find the node with the minimum value
Node* getMinValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->info)
        root->left = deleteNode(root->left, key);
    else if (key > root->info)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == nullptr) { // No child case
                temp = root;
                root = nullptr;
            }
            else { // One child case
                *root = *temp; // Copy contents
            }
            delete temp;
        }
        else {
            Node* temp = getMinValueNode(root->right);
            root->info = temp->info;
            root->right = deleteNode(root->right, temp->info);
        }
    }

    if (root == nullptr) return root;

    // Rebalancing (Same logic as insert)
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}