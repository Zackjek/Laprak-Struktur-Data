# LAPORAN PRAKTIKUM STRUKTUR DATA

## 1. Nama, NIM, Kelas
- **Nama**: Muhammad Zaky Mubarok
- **NIM**: 103112400073
- **Kelas**: IF-12-05

## 2. Motivasi Belajar Struktur Data
Karena aku pengin bisa ngoding sampe tingkat lanjut, makanya aku semangat belajar.

## 3. Dasar Teori
Praktikum ini membahas beberapa konsep fundamental dalam pengelolaan data dan memori menggunakan C++. Berikut adalah landasan teorinya:

- **Array**: Merupakan sebuah struktur data untuk menyimpan kumpulan elemen bertipe sama dalam lokasi memori yang berurutan. Elemen di dalam array diakses melalui `indeks` numerik yang dimulai dari 0.

- **Pointer**: Adalah variabel khusus yang nilainya merupakan alamat memori dari variabel lain. Melalui pointer, data pada suatu variabel dapat dimanipulasi secara tidak langsung. Operasi ini memanfaatkan simbol `&` untuk mendapatkan alamat dan `*` (dereferensi) untuk mengakses nilai di alamat tersebut.

- **Fungsi (Function)**: Adalah sebuah blok kode yang dapat digunakan kembali untuk menjalankan tugas spesifik. Penggunaan fungsi membantu menstrukturkan program menjadi lebih modular, rapi, dan mudah untuk dikelola.

- **Pass-by-Value vs Pass-by-Reference**:
    - **Pass-by-Value**: Dalam metode ini, nilai dari argumen yang dikirim ke fungsi akan disalin. Oleh karena itu, modifikasi pada parameter di dalam fungsi tidak akan memengaruhi variabel asli di luar fungsi.
    - **Pass-by-Reference**: Metode ini mengirimkan referensi (alamat memori) dari argumen asli ke fungsi (menggunakan simbol `&`). Hal ini memungkinkan fungsi untuk mengubah nilai variabel asli secara langsung.

---

## 4. Guided
### 4.1 Guided 1
Program ini mendemonstrasikan penggunaan dasar dari **array**. Sebuah array `bukuPerHari` dibuat untuk menyimpan data jumlah buku. Selanjutnya, sebuah `for loop` digunakan untuk mengakses dan menampilkan setiap elemen dari array tersebut.

**Source Code:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int bukuPerHari[7] = {2, 1, 3, 2, 4, 5, 1};
    int totalBuku = 0;

    cout << "Laporan Baca Buku Mingguan" << endl;

    for (int i = 0; i < 7; i++) {
        cout << "Hari ke-" << i + 1 << ": " << bukuPerHari[i] << " buku." << endl;
        totalBuku += bukuPerHari[i];
    }
}
````

**Cara Kerja:**
Looping `for` dieksekusi dari indeks 0 hingga 6. Pada setiap iterasi, data pada indeks `i` dari array `bukuPerHari` diakses dan ditampilkan.

Output :

![alt text](<Screenshot 2025-10-03 190209.png>)

### 4.2 Guided 2

Bagian ini memperkenalkan konsep **pointer**. Sebuah pointer `ptrHarga` diinisialisasi untuk menunjuk ke alamat memori variabel `hargaProduk`. Program ini menunjukkan bagaimana nilai sebuah variabel dapat diubah melalui pointernya.

**Source Code:**

```cpp
#include<iostream>
using namespace std;

int main() {
    float hargaProduk = 50000.0f;
    float *ptrHarga;
    ptrHarga = &hargaProduk;

    cout << "Harga produk: " << hargaProduk << endl;
    cout << "Alamat memori harga: " << ptrHarga << endl;

    cout <<"\n...Memberikan diskon 10% melalui pointer..." << endl;
    *ptrHarga = *ptrHarga * 0.9f;

    cout << "Harga produk setelah diskon: Rp. " << hargaProduk << endl;
    return 0;
}
```

**Cara Kerja:**
Ekspresi `*ptrHarga = ...` menggunakan operator dereferensi (`*`) untuk mengubah nilai yang tersimpan di alamat yang ditunjuk oleh `ptrHarga`. Karena `ptrHarga` menunjuk ke `hargaProduk`, maka nilai `hargaProduk` juga ikut berubah.

output:

![alt text](<Screenshot 2025-10-03 191038.png>)

### 4.3 Guided 3

Program berikut mengilustrasikan perbedaan antara **pass-by-value** dan **pass-by-reference** melalui penggunaan fungsi. Fungsi `beriNilaiBonus` dirancang dengan *pass-by-reference* (ditandai dengan `&`), sehingga dapat memodifikasi variabel `nilaiAkhir` yang berada di dalam fungsi `main`.

**Source Code:**

```cpp
#include<iostream>
#include<string>
using namespace std;

void beriNilaiBonus(float &nilai){
    nilai += 5.0f;
}

float hitungRataRata(int nilaiTugas, int nilaiUts){
    return (nilaiTugas + nilaiUts) / 2.0f;
}

void cetakProfil(string nama, float nilai){
    cout << "Nama: " << nama << endl;
    cout << "Nilai: " << nilai << endl;
}

int main() {
    string namaSiswa = "Budi";
    int Tugas = 80, uts = 90;
    float nilaiAkhir = hitungRataRata(Tugas, uts);

    cout << "Profil Siswa" << endl;
    cetakProfil(namaSiswa, nilaiAkhir);

    cout << "\nMemberikan nilai bonus..." << endl;
    beriNilaiBonus(nilaiAkhir);

    cout <<"\nProfil Setelah Bonus" << endl;
    cetakProfil(namaSiswa, nilaiAkhir);

    return 0;   
}
```

**Cara Kerja:**
Saat fungsi `beriNilaiBonus(nilaiAkhir)` dipanggil, referensi (alamat) dari `nilaiAkhir` dikirimkan ke fungsi. Akibatnya, operasi `nilai += 5.0f` di dalam fungsi tersebut akan langsung memodifikasi nilai pada variabel `nilaiAkhir` yang asli.

Output:

![alt text](<Screenshot 2025-10-03 191245.png>)
-----

## 5 Unguided

Program ini adalah implementasi terintegrasi dari konsep array, pointer, dan fungsi untuk mengelola data stok buku. Terdapat fungsi untuk mencetak stok, menghitung total, menemukan stok terendah, dan menambahkan bonus pada stok tersebut menggunakan pointer.

**Source Code:**

```cpp
#include <iostream>
using namespace std;

void cetakStok(int arr[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << (i == size - 1 ? "" : ", ");
    }
    cout << " ]" << endl;
}

int hitungTotalStok(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

int* cariStokPalingSedikit(int arr[], int size) {
    int* ptrPalingSedikit = &arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < *ptrPalingSedikit) {
            ptrPalingSedikit = &arr[i];
        }
    }
    return ptrPalingSedikit;
}

void tambahStokBonus(int* ptrStok) {
    *ptrStok += 10;
}

int main() {
    int stokBuku[] = {12, 8, 25, 5, 18};
    int jumlahJenisBuku = 5;

    cout << "Stok Buku Awal:" << endl;
    cetakStok(stokBuku, jumlahJenisBuku);

    int total = hitungTotalStok(stokBuku, jumlahJenisBuku);
    cout << "Total semua stok buku: " << total << endl;

    int* ptrStokRendah = cariStokPalingSedikit(stokBuku, jumlahJenisBuku);
    
    tambahStokBonus(ptrStokRendah);

    cout << "\nStok Buku Setelah Penambahan Bonus:" << endl;
    cetakStok(stokBuku, jumlahJenisBuku);

    return 0;
}
```

**Cara Kerja:**

1.  Array `stokBuku` diinisialisasi di fungsi `main`.
2.  Fungsi `cariStokPalingSedikit` dipanggil untuk menemukan elemen dengan nilai terkecil (yaitu `5`) dan mengembalikan alamat memorinya.
3.  Alamat tersebut disimpan dalam sebuah pointer bernama `ptrStokRendah`.
4.  Pointer ini kemudian dikirim sebagai argumen ke fungsi `tambahStokBonus`.
5.  Fungsi `tambahStokBonus` menggunakan alamat tersebut untuk memodifikasi nilai asli di dalam array `stokBuku`, mengubah `5` menjadi `15`.
6.  Hasil akhir setelah perubahan dicetak ke layar.

Output:

![alt text](<Screenshot 2025-10-03 185949.png>)
-----

## 6 Kesimpulan

Kesimpulannya, praktikum ini memberikan pemahaman mengenai tiga konsep penting dalam C++: **array, pointer, dan fungsi**. Latihan *guided* memperkenalkan setiap konsep secara terpisah, sementara latihan *unguided* menunjukkan bagaimana ketiganya dapat diintegrasikan untuk membangun program yang fungsional. Implementasi ini memperjelas bagaimana pointer dapat digunakan untuk memanipulasi data di dalam array secara efisien melalui fungsi yang berbeda, sebuah dasar yang krusial untuk mempelajari struktur data yang lebih kompleks.

## 7 Referensi

https://saniyatul.lecturer.pens.ac.id/Praktikum%20ASD/01%20Array%20Pointer%20dan%20Struktur.pdf

modul 02 struktur data

```