#include <stdio.h>
#define MAXSIZE 8

int stack[MAXSIZE];
int top = -1;

int isempty() {
    return top == -1;
}

int isfull() {
    return top == MAXSIZE - 1;
}

int peek() {
    return stack[top];
}

int pop() {
    if (!isempty()) {
        return stack[top--];
    } else {
        printf("Tidak dapat mengambil data, Stack kosong.\n");
        return -1;
    }
}

void push(int data) {
    if (!isfull()) {
        stack[++top] = data;
    } else {
        printf("Tidak dapat menambahkan data. Stack penuh.\n");
    }
}

int main() {
    // Menambahkan item ke stack
    push(3);
    push(5);
    push(9);
    push(1);
    push(12);
    push(15);

    printf("Elemen teratas pada Stack adalah: %d\n", peek());
    printf("Semua elemennya adalah: \n");

    // Print stack data
    while (!isempty()) {
        printf("%d\n", pop());
    }

    printf("Stack full: %s\n", isfull() ? "true" : "false");
    printf("Stack empty: %s\n", isempty() ? "true" : "false");

    return 0;
}
