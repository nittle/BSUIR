#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* new = malloc(sizeof(Node));
    if(!new) {
        printf("Memory allocation failed");
        exit(0);
    }

    new->data = data;
    new->next = NULL;
    return new;
}

void printList(Node* pNode) {
    while (pNode) {
        printf("%d ", pNode->data);

        pNode = pNode->next;
    }
    printf('end\n');
}

int main() {
    Node* node1 = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);
    Node* node4 = createNode(40);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    printList(node1);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    return 0;
}