// Created Joel Wiseda Simanungkalit 23343071
#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk melakukan Shell Sort
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Fungsi untuk melakukan Quick Sort
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    printf("Pilih metode sorting:\n1. Shell Sort\n2. Quick Sort\nPilihan Anda: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            shellSort(arr, n);
            printf("Array setelah Shell Sort:\n");
            printArray(arr, n);
            break;
        case 2:
            quickSort(arr, 0, n - 1);
            printf("Array setelah Quick Sort:\n");
            printArray(arr, n);
            break;
        default:
            printf("Pilihan tidak valid\n");
            break;
    }

    free(arr);
    return 0;
}
