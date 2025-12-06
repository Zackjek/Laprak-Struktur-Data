# Laporan Praktikum Struktur Data

## 1. Nama, NIM, Kelas
- **Nama**: Muhammad Zaky Mubarok
- **NIM**: 103112400073
- **Kelas**: IF-12-05

## 2. Motivasi Belajar Struktur Data
Karena aku pengin bisa ngoding sampe tingkat lanjut, makanya aku semangat belajar.

## 3. Dasar Teori
Pada praktikum kali ini, gw mempelajari struktur data yang lebih kompleks, yaitu **Multi-linked List**.

### 3.1 Multi-linked List (List of Lists)
Multi-linked list adalah struktur data di mana setiap node dalam list dapat memiliki pointer yang menunjuk ke list lain. Struktur ini sangat berguna untuk merepresentasikan hubungan hierarkis atau relasi "satu-ke-banyak" (one-to-many).
- **Relasi Induk-Anak**: Contoh umum adalah data Mahasiswa (Induk) yang mengambil banyak Mata Kuliah (Anak), atau Daerah (Induk) yang memiliki banyak Penduduk (Anak).
- **Struktur**: 
    - List Induk biasanya diimplementasikan sebagai *Doubly Linked List* (memiliki `next` dan `prev`).
    - Setiap node Induk memiliki komponen khusus (biasanya struct `list_anak` atau pointer `head_anak`) yang menjadi titik masuk ke List Anak.
    - List Anak juga merupakan linked list yang berdiri sendiri namun terikat pada satu node Induk tertentu.

## 4. Guided
Bagian Guided ini mengimplementasikan struktur data **Multilist** sederhana menggunakan tipe data integer. Implementasi ini mencakup pembuatan list, alokasi node Induk dan Anak, penyisipan data di akhir list (Insert Last), serta pencetakan data secara hierarkis.

### 4.1 `multilist.h`
File ini berisi definisi tipe data dan prototipe fungsi.
* **Struktur Data**: Terdapat `struct list_induk` dan `struct list_anak`. Yang menarik adalah di dalam `struct elemen_induk`, terdapat variabel `list_anak anak`. Ini yang membuat hubungan "Induk memiliki daftar Anak".
* **Pointer**: Menggunakan `next` dan `prev` (Doubly Linked List) untuk navigasi dua arah.

```cpp
#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED
#define Nil NULL

typedef int infotype;
typedef struct elemen_induk *address_induk;
typedef struct elemen_anak *address_anak;

struct elemen_anak {
    infotype info;
    address_anak next, prev;
};

struct list_anak {
    address_anak first, last;
};

struct elemen_induk {
    infotype info;
    list_anak anak;
    address_induk next, prev;
};

struct list_induk {
    address_induk first, last;
};

void createList(list_induk &L);
address_induk alokasi(infotype x);
void insertLastInduk(list_induk &L, address_induk P);
address_induk findInduk(list_induk L, infotype x);
void insertLastAnak(list_anak &LA, address_anak PA);
address_anak alokasiAnak(infotype x);
void printInfo(list_induk L);

#endif
````

### 4.2 `multilist.cpp` (Implementasi Induk)

File ini menangani logika untuk **List Induk**.

  * **`createList`**: Menginisialisasi pointer `first` dan `last` dari list induk menjadi `Nil` (kosong).
  * **`alokasi`**: Membuat node induk baru. Penting diperhatikan bahwa saat induk dibuat, list anaknya (`P->anak.first` dan `P->anak.last`) juga langsung diinisialisasi menjadi `Nil` agar siap digunakan.
  * **`insertLastInduk`**: Menambahkan node induk baru ke bagian paling belakang. Jika list kosong, node baru jadi `first` dan `last`. Jika tidak, node baru disambungkan setelah `last` yang lama.

<!-- end list -->

```cpp
#include "multilist.h"
#include <iostream>
using namespace std;

void createList(list_induk &L) {
    L.first = Nil;
    L.last = Nil;
}

address_induk alokasi(infotype x) {
    address_induk P = new elemen_induk;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    P->anak.first = Nil;
    P->anak.last = Nil;
    return P;
}

void insertLastInduk(list_induk &L, address_induk P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

address_induk findInduk(list_induk L, infotype x) {
    address_induk P = L.first;
    while (P != Nil) {
        if (P->info == x) return P;
        P = P->next;
    }
    return Nil;
}
```

### 4.3 `multilist_anak.cpp` (Implementasi Anak & Print)

File ini menangani logika untuk **List Anak** dan fungsi cetak.

  * **`insertLastAnak`**: Logikanya mirip dengan `insertLastInduk`, tetapi parameternya adalah `list_anak`. Fungsi ini menyambungkan node anak baru ke akhir list anak milik induk tertentu.
  * **`printInfo`**: Fungsi ini menggunakan **Nested Loop** (perulangan bersarang).
      * \*Loop Luar (`while (PI != Nil)`) \*: Menelusuri setiap node Induk satu per satu.
      * \*Loop Dalam (`while (PA != Nil)`) \*: Di setiap Induk, ia menelusuri list Anaknya (`PI->anak.first`) sampai habis.
      * Hasilnya adalah tampilan hierarkis: Data Induk dicetak, diikuti oleh semua Data Anak di bawahnya.


```cpp
#include "multilist.h"
#include <iostream>
using namespace std;

address_anak alokasiAnak(infotype x) {
    address_anak P = new elemen_anak;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void insertLastAnak(list_anak &LA, address_anak PA) {
    if (LA.first == Nil) {
        LA.first = PA;
        LA.last = PA;
    } else {
        LA.last->next = PA;
        PA->prev = LA.last;
        LA.last = PA;
    }
}

void printInfo(list_induk L) {
    address_induk PI = L.first;
    while (PI != Nil) {
        cout << "Induk: " << PI->info << endl;
        address_anak PA = PI->anak.first;
        while (PA != Nil) {
            cout << "  Anak: " << PA->info << endl;
            PA = PA->next;
        }
        PI = PI->next;
    }
}
```

### 4.4 `main.cpp`

File utama untuk menjalankan program.

  * Pertama, membuat list induk `L`.
  * Kemudian, membuat Induk dengan nilai `1` (`P1`) dan memasukkannya ke list.
  * Langsung menambahkan Anak bernilai `10` ke dalam list anak milik Induk 1 (`P1->anak`).
  * Proses diulang untuk Induk bernilai `2` (`P2`) dengan Anak bernilai `20`.
  * Akhirnya, `printInfo` dipanggil untuk menampilkan strukturnya.



```cpp
#include "multilist.h"
#include <iostream>
using namespace std;

int main() {
    list_induk L;
    createList(L);

    address_induk P1 = alokasi(1);
    insertLastInduk(L, P1);

    address_anak PA1 = alokasiAnak(10);
    insertLastAnak(P1->anak, PA1);

    address_induk P2 = alokasi(2);
    insertLastInduk(L, P2);

    address_anak PA2 = alokasiAnak(20);
    insertLastAnak(P2->anak, PA2);

    printInfo(L);
    return 0;
}
```
***Output:***
![alt text](<Screenshot 2025-12-06 220534.png>)

## 5. Unguided

### 5.1 Unguided 1 (Multilist: Delete Anak & Induk)

Pada Unguided 1 ini, kita mengimplementasikan struktur data Multilist yang serupa dengan Guided, namun dengan skenario pengujian yang lebih kompleks di `main.cpp`. Kode ini memisahkan implementasi menjadi 4 file: header, implementasi induk, implementasi anak, dan driver utama.

**Penjelasan Kode:**
1.  **Struktur Data (`multilist.h`)**:
    * Menggunakan tipe data `int` untuk baik `infotypeinduk` maupun `infotypeanak`.
    * Struktur List Induk dan List Anak sama-sama menggunakan **Doubly Linked List** (`next` dan `prev`).
    * Setiap `elemen_list_induk` memiliki field `lanak` yang bertipe `list_anak` sebagai penghubung ke data anaknya.

2.  **Logika Induk (`multilist.cpp`)**:
    * Fungsi `alokasi` secara otomatis menginisialisasi list anak (`createListAnak`) saat node induk dibuat.
    * Fungsi `deleteP` (Hapus Induk) memiliki mekanisme keamanan: sebelum menghapus node induk, ia akan menelusuri dan menghapus seluruh node anak yang terhubung dengannya terlebih dahulu menggunakan `deleteFirstAnak` dan `dealokasiAnak`.

3.  **Logika Anak (`multilist_anak.cpp`)**:
    * Berisi operasi standar list (Insert/Delete First/Last) khusus untuk struktur `list_anak`.
    * Fungsi `deletePAnak` digunakan untuk mencari nilai anak tertentu dalam suatu list anak, lalu menghapusnya dan menyambungkan kembali pointer `next` dan `prev` node tetangganya.

4.  **Alur Program (`main.cpp`)**:
    * Membuat 4 Induk dengan nilai 1, 2, 3, dan 4.
    * Menambahkan data anak yang spesifik ke induk tertentu (contoh: Anak 20, 21, 22 ke Induk 2).
    * Melakukan operasi **penghapusan anak spesifik** (menghapus anak 21 dari Induk 2).
    * Melakukan operasi **penghapusan induk** (menghapus Induk 1), yang secara otomatis juga menghapus anak-anaknya (10 dan 11).

#### `multilist.h`
```cpp
#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define anak(P) P->lanak

// TIPE DATA DIUBAH JADI INT (SESUAI PDF HAL 96)
typedef int infotypeinduk;
typedef int infotypeanak;

typedef struct elemen_list_induk *address_induk;
typedef struct elemen_list_anak *address_anak;

// Struktur List Anak
struct elemen_list_anak {
    infotypeanak info;
    address_anak next;
    address_anak prev;
};

struct list_anak {
    address_anak first;
    address_anak last;
};

// Struktur List Induk
struct elemen_list_induk {
    infotypeinduk info;
    list_anak lanak;
    address_induk next;
    address_induk prev;
};

struct list_induk {
    address_induk first;
    address_induk last;
};

// Prototype
void createList(list_induk &L);
address_induk alokasi(infotypeinduk x);
void dealokasi(address_induk P);
void insertFirst(list_induk &L, address_induk P);
void insertLast(list_induk &L, address_induk P);
void deleteFirst(list_induk &L, address_induk &P);
void deleteLast(list_induk &L, address_induk &P);
void deleteP(list_induk &L, infotypeinduk x);
address_induk findElm(list_induk L, infotypeinduk x);
void printInfo(list_induk L);

// Prototype Anak
void createListAnak(list_anak &L);
address_anak alokasiAnak(infotypeanak x);
void dealokasiAnak(address_anak P);
void insertFirstAnak(list_anak &L, address_anak P);
void insertLastAnak(list_anak &L, address_anak P);
void deleteFirstAnak(list_anak &L, address_anak &P);
void deleteLastAnak(list_anak &L, address_anak &P);
void deletePAnak(list_anak &L, infotypeanak x);

#endif
````

#### `multilist.cpp`

```cpp
#include "multilist.h"

void createList(list_induk &L) {
    first(L) = Nil;
    last(L) = Nil;
}

address_induk alokasi(infotypeinduk x) {
    address_induk P = new elemen_list_induk;
    info(P) = x;
    next(P) = Nil;
    prev(P) = Nil;
    //Panggil fungsi create anak yang ada di multilist_anak.cpp
    createListAnak(anak(P)); 
    return P;
}

void dealokasi(address_induk P) {
    delete P;
}

void insertFirst(list_induk &L, address_induk P) {
    if (first(L) == Nil) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(list_induk &L, address_induk P) {
    if (first(L) == Nil) {
        insertFirst(L, P);
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void deleteFirst(list_induk &L, address_induk &P) {
    if (first(L) == Nil) {
        P = Nil;
    } else if (first(L) == last(L)) {
        P = first(L);
        first(L) = Nil;
        last(L) = Nil;
    } else {
        P = first(L);
        first(L) = next(P);
        prev(first(L)) = Nil;
        next(P) = Nil;
    }
}

void deleteLast(list_induk &L, address_induk &P) {
    if (first(L) == Nil) {
        P = Nil;
    } else if (first(L) == last(L)) {
        deleteFirst(L, P);
    } else {
        P = last(L);
        last(L) = prev(P);
        next(last(L)) = Nil;
        prev(P) = Nil;
    }
}

// Menghapus Induk X 
void deleteP(list_induk &L, infotypeinduk x) {
    address_induk P = findElm(L, x);
    if (P != Nil) {
        // 1. Hapus semua anak dari P terlebih dahulu
        // (Memanggil fungsi dari multilist_anak.cpp)
        address_anak anakHapus;
        while (first(anak(P)) != Nil) {
            deleteFirstAnak(anak(P), anakHapus);
            dealokasiAnak(anakHapus);
        }
        
        // 2. Hapus Node Induk P dari List L
        if (P == first(L)) {
            deleteFirst(L, P);
        } else if (P == last(L)) {
            deleteLast(L, P);
        } else {
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
            next(P) = Nil;
            prev(P) = Nil;
        }
        dealokasi(P);
    }
}

address_induk findElm(list_induk L, infotypeinduk x) {
    address_induk P = first(L);
    while (P != Nil) {
        if (info(P) == x) return P;
        P = next(P);
    }
    return Nil;
}

void printInfo(list_induk L) {
    address_induk P = first(L);
    if (P == Nil) {
        cout << "List Kosong" << endl;
    } else {
        while (P != Nil) {
            cout << "[INDUK] : " << info(P) << endl;
            // Akses list anak untuk dicetak
            address_anak Q = first(anak(P));
            if (Q == Nil) {
                cout << "    (Tidak ada anak)" << endl;
            } else {
                while (Q != Nil) {
                    cout << "    -> [ANAK] : " << info(Q) << endl;
                    Q = next(Q);
                }
            }
            P = next(P);
            cout << "------------------------" << endl;
        }
    }
}
```

#### `multilist_anak.cpp`

```cpp
#include "multilist.h"

void createListAnak(list_anak &L) {
    first(L) = Nil;
    last(L) = Nil;
}

address_anak alokasiAnak(infotypeanak x) {
    address_anak P = new elemen_list_anak;
    info(P) = x;
    next(P) = Nil;
    prev(P) = Nil;
    return P;
}

void dealokasiAnak(address_anak P) {
    delete P;
}

void insertFirstAnak(list_anak &L, address_anak P) {
    if (first(L) == Nil) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLastAnak(list_anak &L, address_anak P) {
    if (first(L) == Nil) {
        insertFirstAnak(L, P);
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void deleteFirstAnak(list_anak &L, address_anak &P) {
    if (first(L) == Nil) {
        P = Nil;
    } else if (first(L) == last(L)) {
        P = first(L);
        first(L) = Nil;
        last(L) = Nil;
    } else {
        P = first(L);
        first(L) = next(P);
        prev(first(L)) = Nil;
        next(P) = Nil;
    }
}

void deleteLastAnak(list_anak &L, address_anak &P) {
    if (first(L) == Nil) {
        P = Nil;
    } else if (first(L) == last(L)) {
        deleteFirstAnak(L, P);
    } else {
        P = last(L);
        last(L) = prev(P);
        next(last(L)) = Nil;
        prev(P) = Nil;
    }
}

void deletePAnak(list_anak &L, infotypeanak x) {
    address_anak P = first(L);
    while (P != Nil && info(P) != x) {
        P = next(P);
    }

    if (P != Nil) {
        address_anak hapus;
        if (P == first(L)) {
            deleteFirstAnak(L, hapus);
        } else if (P == last(L)) {
            deleteLastAnak(L, hapus);
        } else {
            hapus = P;
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
            next(P) = Nil;
            prev(P) = Nil;
        }
        dealokasiAnak(hapus);
    }
}
```

#### `main.cpp`

```cpp
#include "multilist.h"
#include <iostream>
using namespace std;

int main() {
    list_induk L;
    createList(L);

    // 1. Masukkan Data Induk (Angka 1, 2, 3, 4)
    // Mirip seperti guided: alokasi -> insert
    address_induk P1 = alokasi(1);
    insertLast(L, P1);

    address_induk P2 = alokasi(2);
    insertLast(L, P2);
    
    address_induk P3 = alokasi(3);
    insertLast(L, P3);
    
    address_induk P4 = alokasi(4);
    insertLast(L, P4);

    // 2. Masukkan Data Anak ke Induk 1 (Anak: 10, 11)
    // P1 menunjuk ke Induk 1, kita isi anaknya
    insertLastAnak(anak(P1), alokasiAnak(10));
    insertLastAnak(anak(P1), alokasiAnak(11));

    // 3. Masukkan Data Anak ke Induk 2 (Anak: 20, 21, 22)
    insertLastAnak(anak(P2), alokasiAnak(20));
    insertLastAnak(anak(P2), alokasiAnak(21));
    insertLastAnak(anak(P2), alokasiAnak(22));
    
    // 4. Masukkan Data Anak ke Induk 4 (Anak: 40)
    insertLastAnak(anak(P4), alokasiAnak(40));

    cout << "KONDISI AWAL" << endl;
    printInfo(L);
    
    // 5. Tes Delete Anak (Hapus angka 21 dari Induk 2)
    cout << "\nDELETE ANAK 21 DARI INDUK 2" << endl;
    address_induk cari = findElm(L, 2); // Cari induk angka 2
    if (cari != Nil) {
        deletePAnak(anak(cari), 21);
    }
    printInfo(L);

    // 6. Tes Delete Induk (Hapus Induk 1 beserta semua anaknya)
    cout << "\nDELETE INDUK 1 (BESERTA ANAKNYA)" << endl;
    deleteP(L, 1);
    printInfo(L);

    return 0;
}
```

***Output :***
![alt text](<Screenshot 2025-12-06 202719.png>)



### 5.2 Unguided 2 (Circular Doubly Linked List - Mahasiswa)

Bagian ini mengimplementasikan **Circular Doubly Linked List** untuk menyimpan data Mahasiswa (Nama, NIM, L/P, IPK).

**Penjelasan Kode:**
1.  **Struktur Data (`circularlist.h`)**:
    * Menggunakan struct `mahasiswa` sebagai tipe data `infotype` yang kompleks.
    * Node list (`elmlist`) memiliki pointer `next` dan `prev` yang akan membentuk lingkaran.
2.  **Operasi Circular (`circularlist.cpp`)**:
    * **Insert First/Last**: Menangani penyisipan dengan memastikan `next` dari elemen terakhir menunjuk ke `first`, dan `prev` dari `first` menunjuk ke elemen terakhir. Jika list kosong, elemen menunjuk ke dirinya sendiri.
    * **Insert After**: Menyisipkan elemen di antara dua node dengan memanipulasi 4 arah pointer agar rantai lingkaran tidak putus.
3.  **Traversal & Pencarian (`main.cpp`)**:
    * Fungsi `printInfo` dan `findElm` menggunakan perulangan `do-while` untuk menelusuri list tepat satu putaran penuh.
    * `main.cpp` mendemonstrasikan penyisipan data mahasiswa dengan berbagai metode (First, Last, After) untuk membentuk urutan data tertentu.

#### `circularlist.h`
```cpp
#ifndef CIRCULARLIST_H_INCLUDED
#define CIRCULARLIST_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define nil NULL

struct mahasiswa {
    string nama;
    string nim;
    char jenis_kelamin; 
    float ipk;
};

typedef mahasiswa infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct list {
    address first;
};

void createList(list &L);
address alokasi(infotype x);
void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void insertAfter(list &L, address Prec, address P);
address findElm(list L, string nim);
void printInfo(list L);

#endif
````

#### `circularlist.cpp`

```cpp
#include "circularlist.h"

void createList(list &L) { first(L) = nil; }

address alokasi(infotype x) {
    address P = new elmlist;
    info(P) = x; next(P) = nil; prev(P) = nil;
    return P;
}

void insertFirst(list &L, address P) {
    if (first(L) == nil) {
        first(L) = P; next(P) = P; prev(P) = P;
    } else {
        address last = prev(first(L));
        next(P) = first(L); prev(P) = last;
        prev(first(L)) = P; next(last) = P;
        first(L) = P;
    }
}

void insertLast(list &L, address P) {
    if (first(L) == nil) { insertFirst(L, P); }
    else {
        address last = prev(first(L));
        next(P) = first(L); prev(P) = last;
        next(last) = P; prev(first(L)) = P;
    }
}

void insertAfter(list &L, address Prec, address P) {
    if (Prec != nil) {
        next(P) = next(Prec); prev(P) = Prec;
        prev(next(Prec)) = P; next(Prec) = P;
    }
}

address findElm(list L, string nim) {
    address P = first(L);
    if (P == nil) return nil;
    do {
        if (info(P).nim == nim) return P;
        P = next(P);
    } while (P != first(L));
    return nil;
}

void printInfo(list L) {
    address P = first(L);
    if (P == nil) return;
    do {
        cout << "Nama : " << info(P).nama << endl;
        cout << "NIM  : " << info(P).nim << endl;
        cout << "L/P  : " << info(P).jenis_kelamin << endl; 
        cout << "IPK  : " << info(P).ipk << endl;
        cout << endl; 
        P = next(P);
    } while (P != first(L));
}
```

#### `main.cpp`

```cpp
#include <iostream>
#include "circularlist.h"

using namespace std;

address createData(string nama, string nim, char jenis_kelamin, float ipk) {
    infotype x;
    address P;
    x.nama = nama; x.nim = nim; x.jenis_kelamin = jenis_kelamin; x.ipk = ipk;
    P = alokasi(x);
    return P;
}

int main() {
    list L;
    createList(L);
    address P, Prec;

    cout << "coba insert first, last, dan after" << endl;

    
    
    // 1. Mulai dengan Danu (04)
    P = createData("Danu", "04", '1', 4.0);
    insertFirst(L, P); // List: [Danu]

    // 2. Insert Ali (01) di Depan (First)
    P = createData("Ali", "01", '1', 3.3);
    insertFirst(L, P); // List: [Ali, Danu]

    // 3. Insert Bobi (02) Setelah Ali (After)
    Prec = findElm(L, "01");
    P = createData("Bobi", "02", '1', 3.71);
    insertAfter(L, Prec, P); // List: [Ali, Bobi, Danu]

    // 4. Insert Cindi (03) Setelah Bobi (After)
    Prec = findElm(L, "02");
    P = createData("Cindi", "03", 'p', 3.5);
    insertAfter(L, Prec, P); // List: [Ali, Bobi, Cindi, Danu]

    // 5. Insert Fahmi (06) di Belakang (Last)
    P = createData("Fahmi", "06", '1', 3.45);
    insertLast(L, P); // List: [Ali, Bobi, Cindi, Danu, Fahmi]

    // 6. Insert Eli (05) Setelah Danu (After)
    Prec = findElm(L, "04");
    P = createData("Eli", "05", 'p', 3.4);
    insertAfter(L, Prec, P); // List: [Ali, Bobi, Cindi, Danu, Eli, Fahmi]

    // 7. Insert Hilmi (08) di Belakang (Last)
    P = createData("Hilmi", "08", '1', 3.3);
    insertLast(L, P); // List: [Ali ... Fahmi, Hilmi]

    // 8. Insert Gita (07) Setelah Fahmi (After)
    Prec = findElm(L, "06");
    P = createData("Gita", "07", 'p', 3.75);
    insertAfter(L, Prec, P); // List: [Ali ... Fahmi, Gita, Hilmi]

    
    printInfo(L);

    return 0;
}
```
***Output :***
![alt text](<Screenshot 2025-12-06 202731.png>)


6. Kesimpulan

Praktikum ini berhasil mendemonstrasikan implementasi dua struktur data tingkat lanjut:

    Multilist: Menggunakan pointer di dalam struct untuk menghubungkan List Induk dengan List Anak. Hal ini memungkinkan representasi data hierarkis. Mekanisme penghapusan juga telah diimplementasikan dengan benar, di mana menghapus elemen Induk secara otomatis membersihkan elemen Anak yang terkait untuk menjaga integritas memori.

    Circular Doubly Linked List: Menggunakan pointer next dan prev yang saling terhubung membentuk lingkaran. Implementasi ini diuji dengan berbagai operasi penyisipan (InsertFirst, InsertLast, InsertAfter) menggunakan data mahasiswa yang kompleks, membuktikan fleksibilitas struktur ini dalam menangani data yang dinamis.

7. Referensi

    Draft Modul Struktur Data SE Ganjil-2526. Telkom University.
    https://www.slideshare.net/slideshow/8-multi-list-struktur-data/114941552
    https://www.geeksforgeeks.org/cpp/circular-linked-list-in-cpp/

