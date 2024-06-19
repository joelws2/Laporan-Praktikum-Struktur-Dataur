// Created Joel Wiseda Simanungkalit 23343071
#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n) {
    int min_idx, temp;
    for (int i = 0; i < n-1; i++) {
        min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, choice;
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memori tidak dapat dialokasikan\n");
        return 1;
    }

    printf("Masukkan elemen-elemen array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Pilih metode sorting:\n1. Selection Sort\n2. Merge Sort\nPilihan Anda: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            selectionSort(arr, n);
            printf("Array setelah Selection Sort:\n");
            printArray(arr, n);
            break;
        case 2:
            mergeSort(arr, 0, n - 1);
            printf("Array setelah Merge Sort:\n");
            printArray(arr, n);
            break;
        default:
            printf("Pilihan tidak valid\n");
            break;
    }

    free(arr);
    return 0;
}
