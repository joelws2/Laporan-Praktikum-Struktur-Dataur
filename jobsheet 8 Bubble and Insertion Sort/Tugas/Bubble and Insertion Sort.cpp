// Created by Joel Wiseda Simanungkalit 23343071
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

    printf("Pilih metode sorting:\n1. Bubble Sort\n2. Insertion Sort\nPilihan Anda: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bubbleSort(arr, n);
            printf("Array setelah Bubble Sort:\n");
            printArray(arr, n);
            break;
        case 2:
            insertionSort(arr, n);
            printf("Array setelah Insertion Sort:\n");
            printArray(arr, n);
            break;
        default:
            printf("Pilihan tidak valid\n");
            break;
    }

    free(arr);
    return 0;
}
