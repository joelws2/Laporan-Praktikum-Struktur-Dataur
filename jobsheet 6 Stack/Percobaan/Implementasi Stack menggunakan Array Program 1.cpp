// C program untuk implementasi stack menggunakan array
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Struktur untuk merepresentasikan stack
struct Stack {
    int atas;
    unsigned kapasitas;
    int* array;
};

// Fungsi untuk membuat stack berdasarkan kapasitas yang diberikan. Hal ini menginisialisasi ukuran stack sebagai 0
struct Stack* buatStack(unsigned kapasitas) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->kapasitas = kapasitas;
    stack->atas = -1;
    stack->array = (int*)malloc(stack->kapasitas * sizeof(int));
    return stack;
}

// Stack penuh ketika atas sama dengan indeks terakhir
int isFull(struct Stack* stack) {
    return stack->atas == stack->kapasitas - 1;
}

// Stack kosong ketika atas sama dengan -1
int isEmpty(struct Stack* stack) {
    return stack->atas == -1;
}

// Fungsi push (dorong) untuk menambahkan item ke stack. Hal ini menaikkan atas sebesar 1
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack penuh, tidak bisa menambahkan item: %d\n", item);
        return;
    }
    stack->array[++stack->atas] = item;
    printf("%d di push atau ditambahkan ke stack\n", item);
}

// Fungsi pop (melepaskan/hapus) sebuah item dari stack. Hal ini menurunkan atas sebesar 1
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong, tidak bisa melepaskan item\n");
        return INT_MIN;
    }
    return stack->array[stack->atas--];
}

// Fungsi untuk mengembalikan bagian atas (top) dari stack tanpa melepasnya
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong, tidak bisa mengintip item\n");
        return INT_MIN;
    }
    return stack->array[stack->atas];
}

// Driver program untuk mengetes fungsi-fungsi diatas
int main() {
    struct Stack* stack = buatStack(100);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("%d dilepaskan/dihapus dari stack\n", pop(stack));
    printf("Item teratas pada stack adalah: %d\n", peek(stack));

    free(stack->array);
    free(stack);

    return 0;
}
