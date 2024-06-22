// Created by Joel Wiseda Simanungkalit
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk menyimpan data mahasiswa
typedef struct {
    int NIM;
    char nama[50];
    char TTL[50];
    float IPK;
} Mahasiswa;

// Fungsi untuk menambahkan data mahasiswa
void tambahMahasiswa(Mahasiswa mahasiswa[], int* jumlah) {
    printf("Masukkan NIM: ");
    scanf("%d", &mahasiswa[*jumlah].NIM);
    printf("Masukkan Nama: ");
    scanf(" %[^\n]%*c", mahasiswa[*jumlah].nama);  // Menggunakan scanf untuk input string dengan spasi
    printf("Masukkan TTL: ");
    scanf(" %[^\n]%*c", mahasiswa[*jumlah].TTL);
    printf("Masukkan IPK: ");
    scanf("%f", &mahasiswa[*jumlah].IPK);
    (*jumlah)++;
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanMahasiswa(Mahasiswa mahasiswa[], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        printf("NIM: %d\n", mahasiswa[i].NIM);
        printf("Nama: %s\n", mahasiswa[i].nama);
        printf("TTL: %s\n", mahasiswa[i].TTL);
        printf("IPK: %.2f\n\n", mahasiswa[i].IPK);
    }
}

// Fungsi untuk pencarian sequential berdasarkan NIM
void sequentialSearch(Mahasiswa mahasiswa[], int jumlah, int NIM) {
    for (int i = 0; i < jumlah; i++) {
        if (mahasiswa[i].NIM == NIM) {
            printf("Data ditemukan:\n");
            printf("NIM: %d\n", mahasiswa[i].NIM);
            printf("Nama: %s\n", mahasiswa[i].nama);
            printf("TTL: %s\n", mahasiswa[i].TTL);
            printf("IPK: %.2f\n\n", mahasiswa[i].IPK);
            return;
        }
    }
    printf("Data tidak ditemukan\n");
}

// Fungsi untuk mengurutkan data berdasarkan NIM (untuk binary search)
void sortMahasiswa(Mahasiswa mahasiswa[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (mahasiswa[j].NIM > mahasiswa[j + 1].NIM) {
                Mahasiswa temp = mahasiswa[j];
                mahasiswa[j] = mahasiswa[j + 1];
                mahasiswa[j + 1] = temp;
            }
        }
    }
}

// Fungsi untuk pencarian binary berdasarkan NIM
void binarySearch(Mahasiswa mahasiswa[], int jumlah, int NIM) {
    int left = 0;
    int right = jumlah - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mahasiswa[mid].NIM == NIM) {
            printf("Data ditemukan:\n");
            printf("NIM: %d\n", mahasiswa[mid].NIM);
            printf("Nama: %s\n", mahasiswa[mid].nama);
            printf("TTL: %s\n", mahasiswa[mid].TTL);
            printf("IPK: %.2f\n\n", mahasiswa[mid].IPK);
            return;
        } else if (mahasiswa[mid].NIM < NIM) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Data tidak ditemukan\n");
}

int main() {
    Mahasiswa mahasiswa[100];
    int jumlah = 0;
    int pilihan;
    int NIM;

    do {
        printf("Menu:\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Tampilkan Mahasiswa\n");
        printf("3. Pencarian Sequential\n");
        printf("4. Pencarian Binary\n");
        printf("5. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahMahasiswa(mahasiswa, &jumlah);
                break;
            case 2:
                tampilkanMahasiswa(mahasiswa, jumlah);
                break;
            case 3:
                printf("Masukkan NIM yang dicari: ");
                scanf("%d", &NIM);
                sequentialSearch(mahasiswa, jumlah, NIM);
                break;
            case 4:
                sortMahasiswa(mahasiswa, jumlah);
                printf("Masukkan NIM yang dicari: ");
                scanf("%d", &NIM);
                binarySearch(mahasiswa, jumlah, NIM);
                break;
            case 5:
                printf("Keluar dari program\n");
                break;
            default:
                printf("Pilihan tidak valid\n");
                break;
        }
    } while (pilihan != 5);

    return 0;
}
