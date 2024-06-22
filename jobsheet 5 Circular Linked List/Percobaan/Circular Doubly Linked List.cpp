#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    struct node *next;
    int data;
};

struct node *head = NULL;

void tambahAwal();
void tambahAkhir();
void hapusAwal();
void hapusAkhir();
void tampilkan();
void cari();

int main() {
    int choice = 0;
    while (choice != 7) {
        printf("\n*********Main Menu*********\n");
        printf("Silakan pilih salah satu dari menu berikut ...\n");
        printf("===============================================\n");
        printf("1. Masukan data di awal\n");
        printf("2. Masukan data di akhir\n");
        printf("3. Hapus dari awal\n");
        printf("4. Hapus dari akhir\n");
        printf("5. Cari sebuah elemen\n");
        printf("6. Tampilkan\n");
        printf("7. Exit\n");
        printf("Masukan pilihanmu? \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                tambahAwal();
                break;
            case 2:
                tambahAkhir();
                break;
            case 3:
                hapusAwal();
                break;
            case 4:
                hapusAkhir();
                break;
            case 5:
                cari();
                break;
            case 6:
                tampilkan();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Mohon masukan pilihan yang sesuai menu..\n");
        }
    }
    return 0;
}

void tambahAwal() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
    } else {
        printf("Masukan nilai item: ");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL) {
            head = ptr;
            ptr->next = head;
            ptr->prev = head;
        } else {
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            head->prev = ptr;
            ptr->next = head;
            head = ptr;
        }
        printf("Node inserted\n");
    }
}

void tambahAkhir() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
    } else {
        printf("Masukan nilai: ");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL) {
            head = ptr;
            ptr->next = head;
            ptr->prev = head;
        } else {
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            head->prev = ptr;
            ptr->next = head;
        }
        printf("Node ditambahkan\n");
    }
}

void hapusAwal() {
    struct node *temp;
    if (head == NULL) {
        printf("\nUNDERFLOW\n");
    } else if (head->next == head) {
        free(head);
        head = NULL;
        printf("Node dihapus\n");
    } else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        head->next->prev = temp;
        free(head);
        head = temp->next;
        printf("Node dihapus\n");
    }
}

void hapusAkhir() {
    struct node *ptr;
    if (head == NULL) {
        printf("\nUNDERFLOW\n");
    } else if (head->next == head) {
        free(head);
        head = NULL;
        printf("Node dihapus\n");
    } else {
        ptr = head;
        while (ptr->next != head) {
            ptr = ptr->next;
        }
        ptr->prev->next = head;
        head->prev = ptr->prev;
        free(ptr);
        printf("Node dihapus\n");
    }
}

void tampilkan() {
    struct node *ptr;
    ptr = head;
    if (head == NULL) {
        printf("\nTidak ada item yang bisa ditampilkan\n");
    } else {
        printf("\nMenampilkan nilai ... \n");
        while (ptr->next != head) {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
    }
}

void cari() {
    struct node *ptr;
    int item, i = 0, flag = 1;
    ptr = head;
    if (ptr == NULL) {
        printf("\nList kosong\n");
    } else {
        printf("Masukan item yang ingin kamu cari: ");
        scanf("%d", &item);
        while (ptr->next != head) {
            if (ptr->data == item) {
                printf("Item ditemukan pada lokasi %d\n", i + 1);
                flag = 0;
                break;
            }
            ptr = ptr->next;
            i++;
        }
        if (head->data == item && flag) {
            printf("Item ditemukan pada lokasi %d\n", i + 1);
            flag = 0;
        }
        if (flag != 0) {
            printf("Item tidak ditemukan\n");
        }
    }
}

	}