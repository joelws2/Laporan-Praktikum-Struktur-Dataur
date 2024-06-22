// Created by Joel Wiseda Simanungkalit 23343071
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int *fib, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Masukkan jumlah bilangan Fibonacci yang ingin ditampilkan: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Jumlah bilangan harus lebih besar dari 0\n");
        return 1;
    }

    int *fib = (int *)malloc(n * sizeof(int));

    if (fib == NULL) {
        printf("Memori tidak dapat dialokasikan\n");
        return 1;
    }

    fib[0] = 0;
    if (n > 1) {
        fib[1] = 1;
    }

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("Bilangan Fibonacci pertama hingga ke-%d:\n", n);
    printFibonacci(fib, n);

    free(fib);
    return 0;
}
