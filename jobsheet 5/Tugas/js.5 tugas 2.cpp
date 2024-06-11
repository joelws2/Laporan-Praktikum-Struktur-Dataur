#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk node
struct Mobil {
    char no_plat[10];
    char merk[50];
    char nama_pemilik[50];
    struct Mobil *next;
    struct Mobil *prev;
};

// Fungsi untuk membuat node baru
struct Mobil* buatNodeBaru(char *no_plat, char *merk, char *nama_pemilik) {
    struct Mobil *baru = (struct Mobil*)malloc(sizeof(struct Mobil));
    strcpy(baru->no_plat, no_plat);
    strcpy(baru->merk, merk);
    strcpy(baru->nama_pemilik, nama_pemilik);
    baru->next = NULL;
    baru->prev = NULL;
    return baru;
}

// Fungsi untuk menambahkan mobil ke antrian parkir
void tambahMobil(struct Mobil** kepala, char *no_plat, char *merk, char *nama_pemilik) {
    struct Mobil *baru = buatNodeBaru(no_plat, merk, nama_pemilik);
    if (*kepala == NULL) {
        *kepala = baru;
        return;
    }
    struct Mobil *temp = *kepala;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = baru;
    baru->prev = temp;
}

// Fungsi untuk menghapus mobil dari antrian parkir berdasarkan nomor plat
void hapusMobil(struct Mobil** kepala, char *no_plat) {
    struct Mobil *temp = *kepala;
    while (temp != NULL && strcmp(temp->no_plat, no_plat) != 0) {
        temp = temp->next;
    }
    if (temp == NULL) return; // Mobil tidak ditemukan

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

// Fungsi untuk mencetak antrian mobil
void cetakAntrian(struct Mobil* node) {
    while (node != NULL) {
        printf("No Plat: %s, Merk: %s, Pemilik: %s\n", node->no_plat, node->merk, node->nama_pemilik);
        node = node->next;
    }
}

int main() {
    struct Mobil* kepala = NULL;
    tambahMobil(&kepala, "B1234CD", "Toyota", "Andi");
    tambahMobil(&kepala, "A4321BC", "Honda", "Budi");
    tambahMobil(&kepala, "D5678EF", "Suzuki", "Cici");

    printf("Antrian Parkir Awal:\n");
    cetakAntrian(kepala);

    hapusMobil(&kepala, "A4321BC");

    printf("\nAntrian Parkir Setelah Penghapusan:\n");
    cetakAntrian(kepala);

    return 0;
}
