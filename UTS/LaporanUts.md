[UJIAN TENGAH SEMESTER
PRAKTIKUM STRUKTUR DATA
CLO 3]

Identitas Pengumpul

Nama: [Muhammad Zaky Mubarok]

NIM: [103112400073]

Kelas: [Struktur Data IF-12-05]

1. Kode Program

Berikut adalah kode program untuk [jelaskan singkat tujuan kode, misal: "program C++ untuk mengecek bilangan ganjil/genap"].

(Silakan ganti bahasa dan kode di bawah ini sesuai tugas Anda)

```File: main.cpp
 * Author: [Muhammad Zaky Mubarok]
 * NIM: [103112400073]
 * Deskripsi: Program untuk menentukan apakah Mahasiswa mempunyai jumlah huruf nama yang genap atau tidak

//Soal 1 Single Linked List Nama Mahasiswa
//Muhammad Zaky Mubarok
#include<iostream>
#include<string>

using namespace std;

struct Node {
    string Mahasiswa;
    Node* next;
};

Node* head = NULL;

void insert(string mahasiswa_baru) {
    Node* newNode = new Node;
    newNode->Mahasiswa = mahasiswa_baru;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

}

void deleteNama() {
    if (head == NULL) {
        cout << "List kosong, tidak ada yang bisa dihapus." << endl;
        return;
    }

    if (head->next == NULL) {
        cout << "Mahasiswa " << head->Mahasiswa << " (elemen awal) berhasil dihapus." << endl;
        delete head;
        head = NULL;
        return;
    }

    Node* current = head;
    Node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    cout << "Masukkan nama Untuk delete: " ;
    cin >> current->Mahasiswa;
    prev->next = NULL;
    delete current;
}
    

void viewList() {
    if (head == NULL) {
        cout << "List kosong." << endl;
        return;
    }
    Node* current = head;
    while (current != NULL) {
        cout << " " << current->Mahasiswa;
        current = current->next;
    } 
    cout << endl;
}

void HitungGenap() {
    if (head == NULL) {
        cout << "List kosong. " << endl;
        return;
    }

    Node* current = head;
    int count = 0;

    while (current != NULL) {
        if (current->Mahasiswa.length() % 2 == 0) {
            count++;
        }
        current = current->next;
    }

    cout << "Jumlah Nama dengan huruf genap: " << count << endl;
}

int main() {
    int pilihan;
    string nama_mahasiswa;
    while (true) {
        cout << "Menu : " ;
        cout << "1. Insert, " ; 
        cout << "2. Delete, " ;
        cout << "3. View, " ;
        cout << "4. Hitung Genap, " ;
        cout << "0. Exit" << endl;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama: ";
                cin >> nama_mahasiswa;
                insert(nama_mahasiswa);
                break;
            case 2:
                deleteNama();
                break;
            case 3:
                viewList();
                break;
            case 4:
                HitungGenap();
                break;
            case 0:
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }

}
```

2. Penjelasan Kode

Berikut adalah penjelasan alur logika dari kode program di atas:

Header & Struct: Program menggunakan library iostream untuk input/output dan string untuk memanipulasi teks. Struktur data (struct Node) didefinisikan dengan dua komponen: "Mahasiswa" untuk menyimpan nama dan pointer "next" untuk menunjuk ke elemen berikutnya. Variabel global "head" disiapkan sebagai penanda awal list.

Fungsi insert(string mahasiswa_baru): Fungsi ini bertugas menambahkan data baru ke dalam list. Logikanya menggunakan pendekatan Insert Last (menambah di akhir). Jika list kosong, data baru menjadi head. Jika list sudah ada isinya, pointer akan berjalan (looping) sampai node terakhir, lalu menyambungkan node terakhir tersebut ke node baru.

Fungsi deleteNama(): Fungsi ini menghapus elemen dari list. Berdasarkan kode, logikanya adalah menghapus elemen terakhir (tail). Fungsi mencari node sebelum terakhir (prev) dan node terakhir (current). Setelah ditemukan, pointer penghubung diputus (NULL) dan memori node terakhir dihapus.

Fungsi HitungGenap(): Ini adalah fungsi utama untuk menjawab soal. Fungsi ini menelusuri list dari awal sampai akhir. Pada setiap node, program mengambil panjang huruf dari nama mahasiswa menggunakan fungsi .length(). Kemudian dilakukan pengecekan dengan operator modulus: jika panjang nama dibagi 2 sisanya 0, maka dianggap Genap dan hitungan bertambah.

Fungsi main(): Merupakan fungsi utama (entry point) tempat program dieksekusi. Di dalamnya terdapat perulangan while(true) yang berfungsi membuat menu interaktif muncul terus-menerus. Program meminta input angka "pilihan" dari user, lalu menggunakan struktur kontrol switch-case untuk memanggil fungsi yang sesuai (Insert, Delete, View, atau Hitung Genap) atau menghentikan program (return 0) jika user memilih keluar.

3. Output Program

Berikut adalah hasil eksekusi program (output) ketika dijalankan.
```
UTS/Screenshot 2025-11-21 085911.png
```

4. Penjelasan Lanjutan (Analisis Output)

 User memasukkan 1 yang berarti insert dan memasukkan agung, trus insert lagi trus memasukkan rizal, trus insert lagi memasukkan rio dan setelah itu view/lihat jadinya ada agung rizal rio, trus delete rio, tersisa agung rizal, nah trus cek genap / 4, nah dikarenakan agung dan rizal itu hurufnya ganjil makanya 0

5. Kesimpulan

Berdasarkan implementasi dan pengujian kode di atas, dapat disimpulkan bahwa:
single linked list ini gabisa menghapus dari tengah dan soalnya ada sedikit ambigu makanya aku buat codingannya kaya gini

