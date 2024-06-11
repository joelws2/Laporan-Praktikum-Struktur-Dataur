#include<stdio.h>
#include<stdlib.h>

// Definisi struktur node
struct node {
    int no_pol;
    struct node *next;
};

// Fungsi untuk menampilkan daftar
void display(struct node* head) {
    struct node *temp = head;
    printf("\n\nUrutan parkiran:\n");
    while(temp != NULL) {
        printf("%d ---> ", temp->no_pol);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Fungsi untuk memasukkan node baru di depan
void insertAtFront(struct node** headRef, int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->no_pol = value;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Fungsi utama
int main() {
    struct node *head = NULL;

    // Membuat node
    struct node *avanza = (struct node*)malloc(sizeof(struct node));
    struct node *hilux = (struct node*)malloc(sizeof(struct node));
    struct node *kijangF1 = (struct node*)malloc(sizeof(struct node));

    // Menginisialisasi node
    avanza->no_pol = 1234;
    hilux->no_pol = 2345;
    kijangF1->no_pol = 3456;

    // Menghubungkan node
    avanza->next = hilux;
    hilux->next = kijangF1;
    kijangF1->next = NULL;

    // Menyimpan alamat node pertama di head
    head = avanza;

    // Memasukkan node baru di depan
    insertAtFront(&head, 46543);

    // Menampilkan daftar
    display(head);

    // Membebaskan memori yang dialokasikan
    struct node *current = head;
    struct node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
