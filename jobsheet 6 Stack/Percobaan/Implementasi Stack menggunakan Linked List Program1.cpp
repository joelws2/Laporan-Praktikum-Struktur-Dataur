// C program untuk implementasi stack menggunakan array
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Struktur untuk merepresentasikan stack
struct StackNode {
    int data;
    struct StackNode* next;
};

// Fungsi untuk membuat node baru
struct StackNode* newNode(int data) {
    struct StackNode* stackNode = (struct StackNode*) malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Fungsi untuk mengecek apakah stack kosong
int isEmpty(struct StackNode* root) {
    return !root;
}

// Fungsi untuk menambahkan elemen ke stack
void push(struct StackNode** root, int data) {
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d di push atau ditambahkan ke stack\n", data);
}

// Fungsi untuk menghapus elemen dari stack
int pop(struct StackNode** root) {
    if (isEmpty(*root))
        return INT_MIN;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Fungsi untuk melihat elemen teratas pada stack tanpa menghapusnya
int peek(struct StackNode* root) {
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}

// Driver program untuk mengetes fungsi-fungsi di atas
int main() {
    struct StackNode* root = NULL;
    
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    
    printf("%d dilepaskan/dihapus dari stack\n", pop(&root));
    printf("Elemen atas (Top) adalah %d\n", peek(root));
    
    return 0;
}
