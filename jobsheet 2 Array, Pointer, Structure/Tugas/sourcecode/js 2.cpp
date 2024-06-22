// Created by Joel Wiseda Simanungkalit 23343071
#include <stdio.h>
#include <string.h>

// Definisi struct untuk data mahasiswa
typedef struct {
    char NIM[15];
    char Nama[50];
    char TanggalLahir[15]; // Format YYYY-MM-DD
    float IPK;
} Mahasiswa;

// Fungsi untuk input data mahasiswa
void inputMahasiswa(Mahasiswa *m) {
    printf("Masukkan NIM: ");
    scanf("%s", m->NIM);
    printf("Masukkan Nama: ");
    getchar(); // Mengonsumsi newline karakter dari input sebelumnya
    fgets(m->Nama, 50, stdin);
    m->Nama[strcspn(m->Nama, "\n")] = 0; // Menghapus newline karakter
    printf("Masukkan Tanggal Lahir (YYYY-MM-DD): ");
    scanf("%s", m->TanggalLahir);
    printf("Masukkan IPK: ");
    scanf("%f", &m->IPK);
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanMahasiswa(Mahasiswa m) {
    printf("NIM: %s\n", m.NIM);
    printf("Nama: %s\n", m.Nama);
    printf("Tanggal Lahir: %s\n", m.TanggalLahir);
    printf("IPK: %.2f\n", m.IPK);
}

int main() {
    Mahasiswa mhs;

    // Memanggil fungsi input dan tampilkan data mahasiswa
    inputMahasiswa(&mhs);
    tampilkanMahasiswa(mhs);

    return 0;
}
