#include <stdio.h> 

#define ukuran 6 
int queue[ukuran]; // deklarasi array
int front = -1; 
int rear = -1; 

// fungsi untuk menambahkan elemen pada circular queue
void enqueue(int element) {
    if ((rear + 1) % ukuran == front) { // kondisi untuk mengecek apakah queue penuh
        printf("Antrian telah penuh..\n");
    } else {
        if (front == -1) { // kondisi untuk mengecek apakah queue kosong
            front = 0;
        }
        rear = (rear + 1) % ukuran; // posisi rear bertambah
        queue[rear] = element; // memberikan nilai pada queue
        printf("Elemen %d ditambahkan ke antrian.\n", element);
    }
}

// fungsi untuk menghapus elemen dari queue
void dequeue() {
    if (front == -1) { // kondisi untuk mengecek apakah queue kosong
        printf("\nQueue kosong..\n");
    } else {
        printf("\nElemen yang di-dequeue adalah %d\n", queue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % ukuran;
        }
    }
}

// fungsi untuk menampilkan elemen queue
void display() {
    if (front == -1) {
        printf("\nQueue kosong!!..\n");
    } else {
        printf("\nElemen pada queue adalah: ");
        for (int i = front; i != rear; i = (i + 1) % ukuran) {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[rear]); // Menampilkan elemen terakhir
    }
}

int main() { 
    int menu = 1, x; // deklarasi variabel
    
    while (menu >= 1 && menu <= 3) { // looping menggunakan while
        printf("\n****************Circular Queue********************\n"); 
        printf("\n==================================================\n"); 
        printf("\n1: Tambah sebuah elemen"); 
        printf("\n2: Hapus sebuah elemen"); 
        printf("\n3: Tampilkan sebuah elemen"); 
        printf("\nMasukan pilihanmu! "); 
        scanf("%d", &menu); 
        
        switch(menu) { 
            case 1: 
                printf("Silakan masukan elemen yang ingin kamu tambah: "); 
                scanf("%d", &x); 
                enqueue(x); 
                break; 
            case 2: 
                dequeue(); 
                break; 
            case 3: 
                display(); 
                break; 
            default:
                printf("\nPilihan tidak valid. Silakan masukan pilihan yang benar.\n");
        }
    } 
    return 0; 
}
