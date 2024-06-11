#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Definisi struktur 'gudang'
struct gudang {
    char nama_barang[50];
    int harga;
    struct gudang *next;
    struct gudang *prev;
};

// Fungsi untuk mencetak isi dari daftar gudang
void cetak(struct gudang* head) {
    struct gudang *temp = head;
    printf("\n\nList elemen adalah - \n");
    while(temp != NULL) {
        printf("%s = %d ---> ", temp->nama_barang, temp->harga);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct gudang *head;
    struct gudang *one = NULL;
    struct gudang *two = NULL;
    struct gudang *three = NULL;

    // Alokasi memori
    one = (struct gudang*)malloc(sizeof(struct gudang));
    two = (struct gudang*)malloc(sizeof(struct gudang));
    three = (struct gudang*)malloc(sizeof(struct gudang));

    // Mengisi data
    one->harga = 1000;
    strcpy(one->nama_barang, "obat nyamuk");
    two->harga = 5000;
    strcpy(two->nama_barang, "Gula 1 kilo");
    three->harga = 50000;
    strcpy(three->nama_barang, "Minyak Goreng");

    // Menghubungkan node
    one->next = two;
    one->prev = NULL;
    two->next = three;
    two->prev = one;
    three->next = NULL;
    three->prev = two;

    // Menyimpan alamat node pertama di 'head'
    head = one;

    // Mencetak isi daftar
    cetak(head);

    // Membebaskan memori yang dialokasikan
    struct gudang *current = head;
    struct gudang *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
