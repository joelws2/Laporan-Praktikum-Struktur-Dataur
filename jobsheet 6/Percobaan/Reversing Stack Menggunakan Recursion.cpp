// C Program untuk membalikkan stack menggunakan rekursi
#include <stdio.h>
#include <stdlib.h>

#define bool int

// Struktur node dari Stack
struct sNode {
    int data;
    struct sNode* next;
};

// Fungsi Prototype
void push(struct sNode** top_ref, int new_data);
int pop(struct sNode** top_ref);
bool isEmpty(struct sNode* top);
void print(struct sNode* top);

// Fungsi rekursif untuk menyisipkan elemen di bagian bawah stack
void insertAtBottom(struct sNode** top_ref, int item) {
    if (isEmpty(*top_ref))
        push(top_ref, item);
    else {
        int temp = pop(top_ref);
        insertAtBottom(top_ref, item);
        push(top_ref, temp);
    }
}

// Fungsi rekursif untuk membalikkan stack menggunakan insertAtBottom()
void reverse(struct sNode** top_ref) {
    if (!isEmpty(*top_ref)) {
        int temp = pop(top_ref);
        reverse(top_ref);
        insertAtBottom(top_ref, temp);
    }
}

// Program utama
int main() {
    struct sNode* s = NULL;
    push(&s, 4);
    push(&s, 3);
    push(&s, 2);
    push(&s, 1);
    
    printf("\n Stack Awal: ");
    print(s);
    
    reverse(&s);
    
    printf("\n Stack yang dibalikkan: ");
    print(s);
    
    return 0;
}

// Fungsi untuk mengecek apakah Stack kosong
bool isEmpty(struct sNode* top) {
    return (top == NULL) ? 1 : 0;
}

// Fungsi untuk menambahkan item ke stack
void push(struct sNode** top_ref, int new_data) {
    struct sNode* new_node = (struct sNode*) malloc(sizeof(struct sNode));
    if (new_node == NULL) {
        printf("Stack overflow \n");
        exit(0);
    }
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

// Fungsi untuk mengeluarkan item dari stack
int pop(struct sNode** top_ref) {
    int res;
    struct sNode* top;
    if (*top_ref == NULL) {
        printf("Stack underflow \n");
        exit(0);
    }
    else {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

// Fungsi untuk menampilkan isi stack
void print(struct sNode* top) {
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}
