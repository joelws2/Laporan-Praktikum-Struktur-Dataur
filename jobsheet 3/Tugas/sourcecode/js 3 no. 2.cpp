// Created by Joel Wiseda Simanungkalit 23343071
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n, m;
    printf("Masukkan jumlah bilangan prima yang ingin ditampilkan: ");
    scanf("%d", &n);
    printf("Masukkan ukuran memori yang baru (m): ");
    scanf("%d", &m);

    int *primes = (int*) malloc(n * sizeof(int));
    if (primes == NULL) {
        printf("Alokasi memori gagal.\n");
        return 1;
    }

    int count = 0;
    for (int i = 2; count < n; i++) {
        if (isPrime(i)) {
            primes[count++] = i;
        }
    }

    primes = (int*) realloc(primes, m * sizeof(int));
    if (primes == NULL) {
        printf("Realokasi memori gagal.\n");
        free(primes);
        return 1;
    }

    printf("Bilangan prima pertama hingga ke-%d:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    free(primes);
    return 0;
}
