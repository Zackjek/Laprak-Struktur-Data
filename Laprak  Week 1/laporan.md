# LAPORAN PRAKTIKUM STRUKTUR DATA

## 1. Nama, NIM, Kelas
- **Nama**: Muhammad Zaky Mubarok
- **NIM**: 103112400073
- **Kelas**: IF-12-05

## 2. Motivasi Belajar Struktur Data
Karena aku pengin bisa ngoding sampe tingkat lanjut, makanya aku semangat belajar.

## 3. Dasar Teori
Struktur data adalah cara untuk menyimpan dan mengorganisir data dalam komputer agar dapat digunakan secara efisien. Dalam praktikum ini, beberapa konsep dasar pemrograman C++ digunakan sebagai fondasi untuk membangun program yang lebih kompleks. Konsep-konsep tersebut antara lain:

- **Variabel dan Tipe Data**: Variabel adalah penampung nilai di dalam memori. Tipe data menentukan jenis nilai yang bisa ditampung, seperti `int` untuk bilangan bulat, `float` atau `double` untuk bilangan desimal, dan `char` untuk karakter.
- **Input/Output Stream**: Di C++, `iostream` adalah *library* yang digunakan untuk operasi input dan output. `cout` digunakan untuk menampilkan data ke layar (output), sedangkan `cin` digunakan untuk menerima masukan dari pengguna (input).
- **Operator**:
    - **Aritmatika**: Operator seperti penjumlahan (`+`), pengurangan (`-`), perkalian (`*`), dan pembagian (`/`) digunakan untuk melakukan operasi matematis.
    - **Increment**: Operator seperti *pre-increment* (`++variabel`) digunakan untuk menaikkan nilai variabel sebanyak 1 sebelum variabel tersebut diproses dalam sebuah ekspresi.
- **Struktur Kontrol Keputusan (Conditional Statements)**: Struktur seperti `if`, `else if`, dan `else` memungkinkan program untuk menjalankan blok kode yang berbeda berdasarkan kondisi tertentu. Ini memberikan alur logika pada program, misalnya untuk mengecek suatu syarat sebelum melakukan aksi.
- **Struktur Kontrol Perulangan (Looping)**: Struktur `for` digunakan untuk mengeksekusi blok kode secara berulang-ulang selama kondisi tertentu terpenuhi. Perulangan bersarang (*nested loop*) memungkinkan pembuatan pola atau iterasi yang lebih kompleks.
- **Array**: Array adalah kumpulan elemen dengan tipe data yang sama yang disimpan dalam lokasi memori yang berurutan. Array sangat efisien untuk menyimpan dan mengakses daftar data, seperti daftar nama angka dalam program konversi.

## 4. Guided
Bagian ini terdiri dari increment,konversisuhu, If else. latihan tersebut akan dijelaskan sbb:

### 4.1 Guided 1
Program ini mendemonstrasikan penggunaan operator *pre-increment*. Operator `++r` akan menaikkan nilai `r` dari 20 menjadi 21 terlebih dahulu, kemudian hasil penjumlahan `20 + 21` akan disimpan ke dalam variabel `s`.

**Source Code:**
```cpp
#include <iostream>

using namespace std;

int main() {
    int r = 20;
    int s;

    s = 20 + ++r;
    cout << "Nilai r saat ini " << r << endl; // Output: 21
    cout << "Nilai s saat ini " << s << endl; // Output: 41
    return 0;
}
````

**Output:**

```
Nilai r saat ini 21
Nilai s saat ini 41
```

Cara kerjanya adalah `r` (20) di-increment menjadi 21. Kemudian, `s` dihitung sebagai `20 + 21`, yang menghasilkan 41.

### 4.2 Guided 2

Program ini berfungsi sebagai konverter suhu dari Celcius ke Fahrenheit. Program meminta pengguna memasukkan suhu dalam Celcius, kemudian menghitung dan menampilkan hasilnya dalam Fahrenheit menggunakan rumus matematika yang sesuai.

**Source Code:**

```cpp
#include<iostream>
using namespace std;

int main(){
    float celcius, fahrenheit;
    cout << "Tulis sedingin apa gebetan lu : ";
    cin >> celcius;
    fahrenheit = (9.0/5.0) * celcius + 32;
    cout << "Kalau di fahrenheit itu " << fahrenheit << " derajat" << endl;
    cout << "Itu dingin banget sih, buruan peluk biar hangat :v" << endl;
    return 0;
}
```

Program ini membaca input `celcius`, lalu mengalikannya dengan `9.0/5.0` (digunakan `float` agar hasilnya presisi) dan menambahkannya dengan 32 untuk mendapatkan nilai `fahrenheit`.

### 4.3 Guided 3

Program ini adalah contoh sederhana penggunaan struktur `if-else` untuk memberikan diskon berdasarkan total pembelian. Jika total pembelian lebih dari atau sama dengan 30.000, maka program akan menghitung dan menampilkan diskon sebesar 10%. Jika tidak, program akan menampilkan pesan lain.

**Source Code:**

```cpp
#include<iostream>
using namespace std;

int main(){
    double total_pembelian, diskon;
    cout << "Berapa Kamu Belanja : Rp.";
    cin >> total_pembelian;
    if (total_pembelian >= 30000) {
        diskon = 0.1 * total_pembelian;
        cout << "Kamu dapat diskon sebesar : " << diskon << " orang kaya lu tong";
    } else {
        cout << "Kamu belanjanya masih dikit, Tambahin lah, biar gua kaya :v";
    }
    return 0;
}
```

Struktur `if(total_pembelian >= 30000)` menjadi penentu alur program. Jika kondisi ini `true`, blok `if` dieksekusi. Jika `false`, blok `else` yang akan dieksekusi.

## 5. Unguided

### 5.1 Unguided 1

Program ini adalah sebuah kalkulator sederhana yang menerima dua buah bilangan sebagai input. Program akan melakukan operasi aritmatika dasar: penjumlahan, pengurangan, perkalian, dan pembagian. Untuk operasi pembagian, terdapat sebuah kondisi `if` untuk mencegah terjadinya *error* akibat pembagian dengan nol.

**Source Code:**

```cpp
#include <iostream>

using namespace std;

int main() {
    float bilangan1, bilangan2, hasil_penjumlahan, hasil_pengurangan, hasil_perkalian, hasil_pembagian; 
    cout << "Masukkan bilangan pertama: ";
    cin >> bilangan1;
    cout << "Masukkan bilangan kedua: ";
    cin >> bilangan2;

    hasil_penjumlahan = bilangan1 + bilangan2;
    hasil_pengurangan = bilangan1 - bilangan2;
    hasil_perkalian = bilangan1 * bilangan2; 
    
    cout << endl;
    cout << "Outputnya Dibawah Cuyy  " << endl;
    cout << endl;
    cout << "Penjumlahan : " << hasil_penjumlahan << endl;
    cout << "Pengurangan : " << hasil_pengurangan << endl;
    cout << "Perkalian   : " << hasil_perkalian << endl;
    
    // Aturan pembagian Biar ga eror,soalnya semua angka tidak bisa dibagi 0 
    if (bilangan2 != 0) {
        hasil_pembagian = bilangan1 / bilangan2;
        cout << "Pembagian   : " << hasil_pembagian << endl;
    } else {
        cout << "Pembagian tu gabisa dibagi dengan 0 cik, jadi tolong ganti bilangan kedua selain 0" << endl;
    }

    return 0;
}
```

Implementasi program ini cukup sederhana, yaitu dengan menampung input ke dalam dua variabel `float`, lalu menghitung hasilnya menggunakan operator aritmatika dan menampilkannya ke layar.

### 5.2 Unguided 2

Program ini berfungsi untuk mengonversi angka antara 0 hingga 100 menjadi bentuk terbilang dalam Bahasa Indonesia. Program menggunakan serangkaian logika `if-else if-else` serta sebuah array untuk menangani kasus-kasus khusus seperti "nol", "sepuluh", "sebelas", angka belasan, dan puluhan.

**Source Code:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    cout << "Output: " << angka << " : ";

    const char* satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};

    if (angka < 0 || angka > 100) {
        cout << "Hanya support (0-100), soalnya disuruh gitu :v";
    } else if (angka == 0) {
        cout << "nol";
    } else if (angka == 100) {
        cout << "seratus";
    } else if (angka == 10) {
        cout << "sepuluh";
    } else if (angka == 11) {
        cout << "sebelas";
    } else if (angka < 10) {
        cout << satuan[angka];
    } else if (angka < 20) {
        cout << satuan[angka % 10] << " belas";
    } else {
        cout << satuan[angka / 10] << " puluh";
        if (angka % 10 != 0) {
            cout << " " << satuan[angka % 10];
        }
    }
    
    cout << endl;
    return 0;
}
```

Cara implementasinya adalah dengan memecah angka menjadi puluhan dan satuan menggunakan operasi modulus (`%`) dan pembagian (`/`). Array `satuan` digunakan untuk memetakan angka 1-9 ke kata yang sesuai.

### 5.3 Unguided 3

Program ini bertujuan untuk mencetak pola piramida angka terbalik yang simetris. Pengguna memasukkan sebuah angka `n` yang menentukan tinggi piramida. Program menggunakan perulangan bersarang (*nested loop*) untuk mengatur spasi, angka di sisi kiri, bintang di tengah, dan angka di sisi kanan.

**Source Code:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;

    cout << "output:\n";

    for (int i = n; i >= 1; --i) {
        // Loop spasi
        for (int spasi = 0; spasi < n - i; ++spasi) {
            cout << " ";
        }
        // Loop angka kiri
        for (int j = i; j >= 1; --j) {
            cout << j;
        }
        // Bintang tengah
        cout << "*";
        // Loop angka kanan
        for (int j = 1; j <= i; ++j) {
            cout << j;
        }
        // Pindah baris
        cout << endl;
    }

    return 0;
}
```

**Output untuk `n = 5`:**

```
54321*12345
 4321*1234
  321*123
   21*12
    1*1
```

Logikanya diatur oleh loop `for` utama yang berjalan dari `n` hingga 1. Di dalamnya, ada tiga loop lagi: satu untuk mencetak spasi (agar rata kanan), satu untuk angka menurun (sisi kiri), dan satu lagi untuk angka menaik (sisi kanan).

## 6. Kesimpulan

Pada praktikum ini,aku telah berhasil mengimplementasikan beberapa konsep dasar pemrograman C++ seperti penggunaan variabel, tipe data, operator, input-output, serta struktur kontrol `if-else` dan perulangan `for`.program-program yang dibuat, mulai dari kalkulator sederhana, konversi angka ke kata, hingga pembuatan pola kompleks, menunjukkan bahwa tujuan praktikum untuk memahami dan menerapkan logika pemrograman dasar telah tercapai.aku jadi lebih paham bagaimana struktur ini bekerja untuk memecahkan masalah-masalah yang diberikan.

## 7. Referensi

https://terapan-ti.vokasi.unesa.ac.id/post/struktur-data-pengertian-fungsi-dan-penerapannya


