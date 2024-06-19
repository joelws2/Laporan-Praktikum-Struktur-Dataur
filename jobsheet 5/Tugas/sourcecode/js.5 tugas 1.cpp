// Created by Joel Wiseda Simanungkalit 23343071
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk node
struct Buku {
    char judul[100];
    char pengarang[100];
    int tahun;
    struct Buku *next;
    struct Buku *prev;
};

// Fungsi untuk membuat node baru
struct Buku* buatNodeBaru(char *judul, char *pengarang, int tahun) {
    struct Buku *baru = (struct Buku*)malloc(sizeof(struct Buku));
    strcpy(baru->judul, judul);
    strcpy(baru->pengarang, pengarang);
    baru->tahun = tahun;
    baru->next = NULL;
    baru->prev = NULL;
    return baru;
}

// Fungsi untuk menambahkan node di akhir list
void tambahBuku(struct Buku** kepala, char *judul, char *pengarang, int tahun) {
    struct Buku *baru = buatNodeBaru(judul, pengarang, tahun);
    if (*kepala == NULL) {
        *kepala = baru;
        return;
    }
    struct Buku *temp = *kepala;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = baru;
    baru->prev = temp;
}

// Fungsi untuk menghapus buku berdasarkan judul
void hapusBuku(struct Buku** kepala, char *judul) {
    struct Buku *temp = *kepala;
    while (temp != NULL && strcmp(temp->judul, judul) != 0) {
        temp = temp->next;
    }
    if (temp == NULL) return; // Buku tidak ditemukan

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *kepala = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

// Fungsi untuk mencetak list
void cetakList(struct Buku* node) {
    while (node != NULL) {
        printf("Judul Buku: %s, Pengarang: %s, Tahun: %d\n", node->judul, node->pengarang, node->tahun);
        node = node->next;
    }
}

int main() {
    struct Buku* kepala = NULL;
    tambahBuku(&kepala, "Buku A", "Pengarang A", 2000);
    tambahBuku(&kepala, "Buku B", "Pengarang B", 2001);
    tambahBuku(&kepala, "Buku C", "Pengarang C", 2002);

    printf("List Awal:\n");
    cetakList(kepala);

    hapusBuku(&kepala, "Buku B");

    printf("\nList Setelah Penghapusan:\n");
    cetakList(kepala);

    // Contoh menambahkan buku baru
    tambahBuku(&kepala, "Buku D", "Pengarang D", 2003);
    printf("\nList Setelah Penambahan:\n");
    cetakList(kepala);

    return 0;
}
