# Laporan Praktikum Struktur Data

## 1. Nama, NIM, Kelas
- **Nama**: Muhammad Zaky Mubarok
- **NIM**: 103112400073
- **Kelas**: IF-12-05

## 2. Motivasi Belajar Struktur Data
Karena aku pengin bisa ngoding sampe tingkat lanjut, makanya aku semangat belajar.

## 3. Dasar Teori
Struktur data adalah cara untuk menyimpan dan mengorganisir data dalam komputer agar dapat digunakan secara efisien. Praktikum ini berfokus pada implementasi **Stack** menggunakan array.

- **Stack**: Merupakan struktur data linear yang mengikuti prinsip **LIFO (Last-In, First-Out)**. Artinya, elemen yang terakhir dimasukkan adalah elemen yang pertama kali akan dikeluarkan. Analogi yang sering digunakan adalah tumpukkan pirinh, piring yang terakhir diletakkan di atas tumpukan adalah piring pertama yang akan diambil.
- **Header File (.h)**: Berfungsi sebagai "cetak biru" atau deklarasi. Di sini, kita mendefinisikan struktur data (`struct Stack`) dan mendaftarkan prototipe dari semua fungsi yang akan digunakan.
- **Implementation File (.cpp)**: Berisi "mesin" atau definisi dari setiap fungsi yang telah dideklarasikan di file header. Semua logika untuk operasi seperti `Push` dan `Pop` ditulis di sini.
- **Driver File (main.cpp/unguided.cpp)**: File utama yang berisi fungsi `main()`. File ini digunakan untuk menjalankan program, menguji fungsi-fungsi yang telah dibuat, dan melihat hasilnya.

## 4. Guided
Bagian ini adalah implementasi dasar dari ADT Stack yang diberikan sebagai contoh terbimbing dalam praktikum. Kode dibagi menjadi tiga file: `stack.h` untuk deklarasi, `stack.cpp` untuk implementasi fungsi, dan `main.cpp` untuk menjalankan program.

#### **`stack.h`**
```cpp
#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack {
    infotype info[MaxEl]; // Array untuk menyimpan elemen stack
    int TOP;
};

void CreateStack(Stack &S);
bool IsEmpty(Stack S);
bool IsFull(Stack S);
void Push(Stack &S, infotype X); // Menambahkan elemen ke stack
infotype Pop(Stack &S); // Mengambil elemen teratas dari stack
void printInfo(Stack S); 
void balikStack(Stack &S); // Membalik urutan elemen dalam stack

#endif
````

-----

#### **`stack.cpp`**

```cpp
#include "stack.h" // mengimport header file stack.h

using namespace std;

// fungsi untuk membuat stack baru dengan inisialisasi TOP = Nil
void CreateStack(Stack &S) {
    S.TOP = Nil; // inisiasi TOP dengan Nil (biasanya -1) untuk menandakan stack kosong
}

// fungsi untuk mengecek apakah stack kosong
bool IsEmpty(Stack S) {
    return S.TOP == Nil; // stack kosong jika TOP sama dengan Nil
}

// fungsi untuk mengecek apakah stack penuh
bool IsFull(Stack S) {
    return S.TOP == MaxEl - 1; // stack penuh jika TOP mencapai indeks maksimal
}

// Fungsi untuk menambahkan elemen ke stack (Push)
void Push(Stack &S, infotype X) {
    if (!IsFull(S)) { // cek apakah stack tidak penuh
        S.TOP++; // naikkan TOP
        S.info[S.TOP] = X; // tambahkan elemen baru di posisi TOP
    } else {
        cout << "Stack is full. Cannot push " << X << endl; // pesan error jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (Pop)
infotype Pop(Stack &S) {
    infotype X = -999; // variabel untuk menyimpan elemen yang di-pop
    if (!IsEmpty(S)) { // cek apakah stack tidak kosong
        X = S.info[S.TOP]; // ambil elemen di posisi TOP
        S.TOP--; // turunkan TOP
    }else {
        cout << "Stack Kosong. Gabisa pop." << endl; // pesan error jika stack kosong
    }
        return X; // kembalikan elemen yang di-pop
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (IsEmpty(S)) {
        cout << "Stack Kosong" << endl; // pesan jika stack kosong
    } else {
        cout << "[TOP] "; // Tampilkan penanda TOP
        for (int i = S.TOP; i >= 0; i--) { // iterasi dari TOP ke bawah
            cout << S.info[i] << " "; // tampilkan elemen
        }
        cout << endl;
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!IsEmpty(S)) { // Cek apakah stack tidak kosong
        Stack temp1, temp2; // deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2); // inisialisasi kedua stack temporary

        while (!IsEmpty(S)) { // Pindahkan semua elemen dari S ke temp1 (urutan terbalik)
            Push(temp1, Pop(S));
        }

        while (!IsEmpty(temp1)) { // Pindahkan semua elemen dari temp1 ke temp2 (urutan terbalik lagi)
            Push(temp2, Pop(temp1));
        }

        while (!IsEmpty(temp2)) { // Pindahkan semua elemen dari temp2 kembali ke S (urutan sudah benar)
            Push(S, Pop(temp2));
        }

    }
}
```

-----

#### **`main.cpp`**

```cpp
#include "stack.h" // mengimport header file stack.h
#include <iostream>

using namespace std;

int main() {
    Stack S; // deklarasi stack S bertipe Stack
    CreateStack(S); // inisialisasi stack S menjadi stack kosong

    Push(S, 3); // menambahkan elemen 3 ke stack S
    Push(S, 4); // menambahkan elemen 4 ke stack S
    Push(S, 8); // menambahkan elemen 8 ke stack S
    Pop (S);    // menghapus elemen teratas dari stack S (8)
    Push(S, 2); // menambahkan elemen 2 ke stack S
    Push(S, 3); // menambahkan elemen 3 ke stack S
    Pop (S);    // menghapus elemen teratas dari stack S (3)
    Push(S, 9); // menambahkan elemen 9 ke stack S

    cout << "Stack awal: " << endl;
    printInfo(S); // menampilkan isi stack sebelum dibalik

    cout << " Balik Stack: " << endl;
    balikStack(S); // membalik urutan elemen dalam stack S

    cout << "Stack setelah dibalik: " << endl;
    printInfo(S); // menampilkan isi stack setelah dibalik

    return 0; // mengakhiri program
}
```
**Output :**
![alt text](<Screenshot 2025-10-31 085321.png>)
```

## 5\. Unguided

### 5.1 Unguided 1 (ADT Stack Dasar)

Latihan pertama adalah membuat implementasi dasar dari ADT Stack menggunakan array. Ini mencakup fungsi-fungsi esensial seperti `CreateStack`, `Push`, `Pop`, `printInfo`, dan `balikStack`.

#### **`stack.h`**

```cpp
#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int TOP;
};

void CreateStack(Stack &S);
bool IsEmpty(Stack S);
bool IsFull(Stack S);
void Push(Stack &S, infotype X);
infotype Pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```

-----

#### **`stack.cpp`**

```cpp
#include "stack.h"
#include <iostream>
using namespace std;

void CreateStack(Stack &S) { S.TOP = Nil; }
bool IsEmpty(Stack S) { return S.TOP == Nil; }
bool IsFull(Stack S) { return S.TOP == MaxEl - 1; }

void Push(Stack &S, infotype X) {
    if (!IsFull(S)) {
        S.TOP++;
        S.info[S.TOP] = X;
    }
}

infotype Pop(Stack &S) {
    infotype X = -999;
    if (!IsEmpty(S)) {
        X = S.info[S.TOP];
        S.TOP--;
    }
    return X;
}

void printInfo(Stack S) {
    if (IsEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.TOP; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (!IsEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1); CreateStack(temp2);
        while (!IsEmpty(S)) { Push(temp1, Pop(S)); }
        while (!IsEmpty(temp1)) { Push(temp2, Pop(temp1)); }
        while (!IsEmpty(temp2)) { Push(S, Pop(temp2)); }
    }
}
```

-----

#### **`unguided1.cpp`**

```cpp
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);

    Push(S, 3);
    Push(S, 4);
    Push(S, 8);
    Pop(S);
    Push(S, 2);
    Push(S, 3);
    Pop(S);
    Push(S, 9);
    
    printInfo(S);
    
    cout << "balik stack" << endl;
    balikStack(S);
    
    printInfo(S);
    
    return 0;
}
```
**Output :**
![alt text](<Screenshot 2025-10-31 111206.png>)
```

### 5.2 Unguided 2 (Push Ascending)

Latihan kedua adalah menambahkan prosedur `pushAscending` yang memastikan semua elemen di dalam stack selalu terurut dari nilai terkecil (di dasar) hingga terbesar (di puncak).

#### **`stack.h`**

```cpp
#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1
typedef int infotype;
struct Stack {
    infotype info[MaxEl];
    int TOP;
};

void CreateStack(Stack &S);
bool IsEmpty(Stack S);
bool IsFull(Stack S);
void Push(Stack &S, infotype X);
infotype Pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype X); // Ditambahkan

#endif
```

-----

#### **`stack.cpp`**

```cpp
#include "stack.h"
#include <iostream>
using namespace std;

// Fungsi-fungsi dasar dari Soal 1
void CreateStack(Stack &S) { S.TOP = Nil; }
bool IsEmpty(Stack S) { return S.TOP == Nil; }
bool IsFull(Stack S) { return S.TOP == MaxEl - 1; }

void Push(Stack &S, infotype X) {
    if (!IsFull(S)) {
        S.TOP++;
        S.info[S.TOP] = X;
    }
}

infotype Pop(Stack &S) {
    infotype X = -999;
    if (!IsEmpty(S)) {
        X = S.info[S.TOP];
        S.TOP--;
    }
    return X;
}

void printInfo(Stack S) {
    if (IsEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.TOP; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (!IsEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1); CreateStack(temp2);
        while (!IsEmpty(S)) { Push(temp1, Pop(S)); }
        while (!IsEmpty(temp1)) { Push(temp2, Pop(temp1)); }
        while (!IsEmpty(temp2)) { Push(S, Pop(temp2)); }
    }
}

// Fungsi tambahan dari Soal 2
void pushAscending(Stack &S, infotype X) {
    if (IsEmpty(S) || S.info[S.TOP] <= X) {
        Push(S, X);
    } else {
        Stack temp;
        CreateStack(temp);
        while (!IsEmpty(S) && S.info[S.TOP] > X) {
            Push(temp, Pop(S));
        }
        Push(S, X);
        while (!IsEmpty(temp)) {
            Push(S, Pop(temp));
        }
    }
}
```

-----

#### **`unguided2.cpp`**

```cpp
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    
    printInfo(S);
    
    cout << "balik stack" << endl;
    balikStack(S);
    
    printInfo(S);
    
    return 0;
}
```
**Output :**
![alt text](<Screenshot 2025-10-31 111303.png>)
```

### 5.3 Unguided 3 (Get Input Stream)

Latihan ketiga adalah menambahkan prosedur `getInputStream` untuk membaca serangkaian input angka dari pengguna hingga tombol Enter ditekan.

#### **`stack.h`**

```cpp
#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1
typedef int infotype;
struct Stack {
    infotype info[MaxEl];
    int TOP;
};

void CreateStack(Stack &S);
bool IsEmpty(Stack S);
bool IsFull(Stack S);
void Push(Stack &S, infotype X);
infotype Pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype X);
void getInputStream(Stack &S); // Ditambahkan

#endif
```

-----

#### **`stack.cpp`**

```cpp
#include "stack.h"
#include <iostream>
using namespace std;

// Fungsi-fungsi dasar (Soal 1)
void CreateStack(Stack &S) {
    S.TOP = Nil;
}

bool IsEmpty(Stack S) {
    return S.TOP == Nil;
}

bool IsFull(Stack S) {
    return S.TOP == MaxEl - 1;
}

void Push(Stack &S, infotype X) {
    if (!IsFull(S)) {
        S.TOP++;
        S.info[S.TOP] = X;
    }
}

infotype Pop(Stack &S) {
    infotype X = -999;
    if (!IsEmpty(S)) {
        X = S.info[S.TOP];
        S.TOP--;
    }
    return X;
}

void printInfo(Stack S) {
    if (IsEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.TOP; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (!IsEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1); CreateStack(temp2);
        while (!IsEmpty(S)) { Push(temp1, Pop(S)); }
        while (!IsEmpty(temp1)) { Push(temp2, Pop(temp1)); }
        while (!IsEmpty(temp2)) { Push(S, Pop(temp2)); }
    }
}

// Fungsi dari Soal 2
void pushAscending(Stack &S, infotype X) {
    if (IsEmpty(S) || S.info[S.TOP] <= X) {
        Push(S, X);
    } else {
        Stack temp;
        CreateStack(temp);
        while (!IsEmpty(S) && S.info[S.TOP] > X) {
            Push(temp, Pop(S));
        }
        Push(S, X);
        while (!IsEmpty(temp)) {
            Push(S, Pop(temp));
        }
    }
}

// Fungsi tambahan dari Soal 3
void getInputStream(Stack &S) {
    char ch;
    cout << "Masukkan serangkaian angka (akhiri dengan Enter): ";
    while (cin.peek() != '\n') {
        ch = cin.get();
        if (isdigit(ch)) {
            Push(S, ch - '0');
        }
    }
}
```

-----

#### **`unguided3.cpp`**

```cpp
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    
    getInputStream(S);
    
    printInfo(S);
    
    cout << "balik stack" << endl;
    balikStack(S);
    
    printInfo(S);
    
    return 0;
}
```
**Output:**
![alt text](<Screenshot 2025-10-31 111445.png>)
```

## 6. Kesimpulan

Pada praktikum ini, implementasi struktur data **Stack** menggunakan array berhasil dilakukan. Tiga latihan utama telah diselesaikan:

1.  **Pembuatan ADT Dasar**: Fungsi-fungsi esensial seperti `Push`, `Pop`, dan `balikStack` berhasil dibuat dan diuji.
2.  **`pushAscending`**: Fungsi untuk memasukkan elemen secara terurut berhasil diimplementasikan, menunjukkan cara memanipulasi stack dengan bantuan stack temporer.
3.  **`getInputStream`**: Fungsi untuk menerima input stream dari pengguna juga berhasil dibuat, menunjukkan cara menangani input karakter dan mengubahnya menjadi data untuk stack.


## 7. Referensi

1. Modul Struktur Data
2. https://id.jobstreet.com/id/career-advice/article/stack-adalah
3. https://glints.com/id/lowongan/stack-adalah/



```
```