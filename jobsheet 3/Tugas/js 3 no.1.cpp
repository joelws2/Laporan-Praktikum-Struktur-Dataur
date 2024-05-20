// Created by Joel Wiseda Simanungkalit 23343071
#include <stdio.h>
#include <stdlib.h>

int* alokasiFibonacci(int n) {
    int* fib = (int*)malloc(n * sizeof(int));
    if (fib == NULL) {
        printf("Memori tidak berhasil dialokasikan.\n");
        exit(1);
    }
    return fib;
}

void tampilkanFibonacci(int* fib, int n) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Masukkan jumlah bilangan Fibonacci yang ingin ditampilkan: ");
    scanf("%d", &n);
    int* fibonacci = alokasiFibonacci(n);
    tampilkanFibonacci(fibonacci, n);
    free(fibonacci);
    return 0;
}
