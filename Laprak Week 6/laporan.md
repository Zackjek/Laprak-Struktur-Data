# **LAPORAN PRAKTIKUM STRUKTUR DATA**

## **1. Nama, NIM, Kelas**

  - **Nama**: Muhammad Zaky Mubarok
  - **NIM**: 103112400073
  - **Kelas**: IF-12-05

## **2. Motivasi Belajar Struktur Data**

Karena aku pengin bisa ngoding sampe tingkat lanjut, makanya aku semangat belajar.

## **3. Dasar Teori**

Praktikum ini membahas struktur data dinamis yang dikenal sebagai **Doubly Linked List (DLL)**. Berbeda dengan array yang statis, linked list memungkinkan alokasi memori yang fleksibel.

  - **Node (Simpul)**: Merupakan elemen dasar dari sebuah linked list. Setiap *node* tidak hanya menyimpan data (*info*), tetapi juga menyimpan alamat memori dari *node* lain.

  - **Pointer**: Adalah variabel yang menyimpan alamat memori. Dalam konteks DLL, setiap *node* memiliki dua pointer:

      - **`next`**: Menyimpan alamat *node* berikutnya dalam urutan.
      - **`prev`**: Menyimpan alamat *node* sebelumnya. Adanya pointer `prev` inilah yang membedakan DLL dari *Singly Linked List* dan memungkinkan penelusuran data secara dua arah (maju dan mundur).

  - **List (First & Last)**: Merupakan sebuah objek atau struct yang bertindak sebagai "kepala" dari keseluruhan rantai *node*. Ia biasanya memiliki dua pointer utama:

      - **`first`** (atau *head*): Menunjuk ke *node* pertama.
      - **`last`** (atau *tail*): Menunjuk ke *node* terakhir. Ini memudahkan operasi penambahan atau penghapusan data di akhir list.

-----

## **4. Guided**

### **4.1 Guided 1: Dasar Operasi Insert**

Program ini adalah kode dasar yang diberikan untuk operasi penyisipan pada Doubly Linked List. Program ini berisi fungsi-fungsi esensial seperti `alokasi`, `insertFirst`, `insertLast`, dan `insertAfter`. Kode ini menjadi fondasi untuk mengerjakan **Unguided 1**.

**Source Code:**

```cpp
#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype; // mendefinisikan data infotype sebagai int
typedef struct elmlist *address; // mendefinisikan tipe address sebagai pointer ke struct elmlist

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void insertFirst(List &L, address P) {
    P -> next = L.first;
    P -> prev = Nil;
    if (L.first != Nil) L.first -> prev = P;
    else L.last = P;
    L.first = P;
}

void insertLast(List &L, address P) {
    P->prev = L.last;
    P->next = Nil;
    if (L.last != Nil) L.last -> next = P;
    else L.first = P;
    L.last = P;
}

void insertAfter(List &L, address P, address R){
    P -> next = R -> next;
    P -> prev = R;
    if (R -> next != Nil) R -> next -> prev = P;
    else L.last = P;
    R -> next = P;
}

address alokasi(infotype x){ // Definisi fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P -> info = x;
    P -> next = Nil;
    P -> prev = Nil;
    return P;
}

void printInfo(List L){
    address P = L.first;
    while (P != Nil) {
        cout << P -> info << " ";
        P = P -> next;
    }
    cout << endl;
}

int main (){
    List L;
    L.first = Nil;
    L.last = Nil;
    address P1 = alokasi(1);
    insertFirst(L, P1);
    address P2 = alokasi(2);
    insertLast(L, P2);
    address P3 = alokasi(3);
    insertAfter(L, P3, P2);
    printInfo(L);
    return 0;
}
```

**Cara Kerja:**
Program ini mendefinisikan struktur dasar dari DLL dan menyediakan fungsi-fungsi untuk menambahkan elemen baru di awal, di akhir, atau setelah elemen tertentu. Fungsi `main` mendemonstrasikan pembuatan list sederhana `1 -> 2 -> 3`.

**Output :**
![alt text](<Screenshot 2025-10-25 201452.png>)

### **4.2 Guided 2: Dasar Operasi Delete**

Program ini adalah kode dasar untuk operasi penghapusan pada Doubly Linked List. Kode ini menyediakan fungsi-fungsi seperti `deleteFirst`, `deleteLast`, dan `deleteAfter` yang menjadi dasar untuk pengerjaan **Unguided 2**.

**Source Code:**

```cpp
#include <iostream>
using namespace std;
#define Nil NULL

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

address alokasi(infotype x) {
    address P = new elmlist;
    P -> info = x;
    P -> next = Nil;
    P -> prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    P -> next = L.first;
    P -> prev = Nil;
    if (L.first != Nil) L.first -> prev = P;
    else L.last = P;
    L.first = P;
}

void printInfo(List L){
    address P = L.first;
    while (P != Nil) {
        cout << P -> info << " ";
        P = P -> next;
    }
}

void deleteFirst(List &L, address &P){
    P = L.first;
    L.first = L.first -> next;
    if (L.first != Nil) L.first -> prev = Nil;
    else L.last = Nil;
    P -> next = Nil;
    P -> prev = Nil;
}

void deleteLast(List &L, address &P) {
    P = L.last;
    L.last = L.last -> prev;
    if (L.last != Nil) L.last -> next = Nil; 
    else L.first = Nil;
    P -> prev = Nil;
    P -> next = Nil;
}

void deleteAfter(List &L, address &P, address R) {
    P = R -> next;
    R -> next = P -> next;
    if (P -> next != Nil) P -> next -> prev = R;
    else L.last = R;
    P -> prev = Nil;
    P -> next = Nil;
}

int main (){
    List L;
    L.first = Nil;
    L.last = Nil;
    insertFirst(L, alokasi(1));
    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(3));
    printInfo(L);
    address P;
    deleteFirst(L, P);
    dealokasi(P);
    deleteAfter(L, P, L.first);
    dealokasi(P);
    printInfo(L);
    return 0;
}

```

**Cara Kerja:**
Program ini mendefinisikan fungsi-fungsi untuk menghapus elemen dari awal, akhir, atau setelah elemen tertentu, serta fungsi `dealokasi` untuk melepaskan memori yang sudah tidak terpakai. Fungsi `main` mendemonstrasikan pembuatan list dan beberapa operasi hapus.

**Output :**

![alt text](<Screenshot 2025-10-25 201503.png>)
-----

## **5. Unguided**

### **5.1 Unguided 1: Menambahkan `insertBefore` dan `printReverse`**

Tugas ini adalah memodifikasi kode **Guided 1** untuk menambahkan fungsi `insertBefore` (menyisipkan elemen sebelum elemen lain) dan `printReverse` (mencetak list dari belakang).

**Source Code:**

```cpp
#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};


address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    P->prev = Nil;
    if (L.first != Nil) {
        L.first->prev = P;
    } else {
        L.last = P;
    }
    L.first = P;
}

void insertLast(List &L, address P) {
    P->prev = L.last;
    P->next = Nil;
    if (L.last != Nil) {
        L.last->next = P;
    } else {
        L.first = P;
    }
    L.last = P;
}

void insertAfter(List &L, address P, address R) {
    P->next = R->next;
    P->prev = R;
    if (R->next != Nil) {
        R->next->prev = P;
    } else {
        L.last = P;
    }
    R->next = P;
}

void insertBefore(List &L, address P, address R) {
    if (R == L.first) {
        insertFirst(L, P); // Jika R adalah elemen pertama, sama saja dengan insertFirst
    } else {
        P->next = R;
        P->prev = R->prev;
        R->prev->next = P;
        R->prev = P;
    }
}


void printReverse(List L) {
    address P = L.last;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->prev;
    }
    cout << endl;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

int main() {
    List L;
    L.first = Nil;
    L.last = Nil;

    // Membuat list awal: 1 -> 3 -> 2
    address p1 = alokasi(1);
    insertFirst(L, p1);
    address p3 = alokasi(3);
    insertAfter(L, p3, p1);
    address p2 = alokasi(2);
    insertLast(L, p2);

    cout << "TASK 1: INSERT OPERATIONS" << endl;
    cout << "List awal:" << endl;
    cout << "Forward: ";
    printInfo(L);
    cout << "Backward: ";
    printReverse(L);

    // Menyisipkan 4 sebelum 2
    insertBefore(L, alokasi(4), p2);
    cout << "Berhasil insert 4 sebelum 2" << endl;

    // Menyisipkan 5 sebelum 1
    insertBefore(L, alokasi(5), p1);
    cout << "Berhasil insert 5 sebelum 1" << endl;

    cout << "List setelah insertBefore:" << endl;
    cout << "Forward: ";
    printInfo(L);
    cout << "Backward: ";
    printReverse(L);

    return 0;
}
```

**Cara Kerja:**

1.  Fungsi `insertBefore` ditambahkan untuk menangani logika penyisipan sebelum node target dengan cara menyambungkan ulang pointer `next` dan `prev` dari node di sekitarnya.
2.  Fungsi `printReverse` dibuat untuk melakukan traversal dari `L.last` ke `L.first` menggunakan pointer `prev`.
3.  Fungsi `main` mendemonstrasikan kedua fungsi tersebut untuk menghasilkan output yang sesuai dengan ekspektasi.

**Output:**

![alt text](<Screenshot 2025-10-25 194610.png>)

### **5.2 Unguided 2: Menambahkan `deleteByValue` dan `deleteAll`**

Tugas ini adalah memodifikasi kode **Guided 2** dengan menambahkan fungsi `deleteByValue` (menghapus elemen pertama dengan nilai tertentu) dan `deleteAll` (menghapus semua elemen).

**Source Code:**

```cpp
#include <iostream>
using namespace std;
#define Nil NULL

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};


address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    P->prev = Nil;
    if (L.first != Nil) L.first->prev = P;
    else L.last = P;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
}

void deleteFirst(List &L, address &P) {
    P = L.first;
    L.first = L.first->next;
    if (L.first != Nil) L.first->prev = Nil;
    else L.last = Nil;
    P->next = Nil;
    P->prev = Nil;
}

void deleteLast(List &L, address &P) {
    P = L.last;
    L.last = L.last->prev;
    if (L.last != Nil) L.last->next = Nil;
    else L.first = Nil;
    P->prev = Nil;
    P->next = Nil;
}

void deleteAfter(List &L, address &P, address Prec) {
    P = Prec->next;
    Prec->next = P->next;
    if (P->next != Nil) P->next->prev = Prec;
    else L.last = Prec;
    P->prev = Nil;
    P->next = Nil;
}


address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}


void deleteByValue(List &L, infotype x) {
    address target = findElm(L, x);
    if (target == Nil) {
        cout << "Nilai " << x << " tidak ditemukan" << endl;
        return;
    }

    address P;
    if (target == L.first) {
        deleteFirst(L, P);
    } else if (target == L.last) {
        deleteLast(L, P);
    } else {
        deleteAfter(L, P, target->prev);
    }
    dealokasi(P);
    cout << "Nilai " << x << " berhasil dihapus" << endl;
}


void deleteAll(List &L) {
    int count = 0;
    address P;
    while (L.first != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
        count++;
    }
    cout << "Semua elemen (" << count << ") berhasil dihapus" << endl;
}


int main() {
    List L;
    L.first = Nil;
    L.last = Nil;

    // Membuat list awal: 2 -> 3 -> 2 -> 1
    insertFirst(L, alokasi(1));
    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(3));
    insertFirst(L, alokasi(2));

    cout << "TASK 1: DELETE OPERATIONS" << endl; // Salah ketik di PDF, seharusnya TASK 2
    cout << "List awal: ";
    printInfo(L);
    cout << endl;

    // Menghapus nilai 2 (kemunculan pertama)
    deleteByValue(L, 2);
    cout << "Setelah deleteByValue(2): ";
    printInfo(L);
    cout << endl;

    // Mencoba menghapus nilai yang tidak ada
    deleteByValue(L, 5);
    cout << "List tetap: ";
    printInfo(L);
    cout << endl;

    // Menghapus semua elemen yang tersisa
    deleteAll(L);

    // Mengisi list lagi untuk demo deleteAll
    cout << "List setelah tambah data: ";
    insertFirst(L, alokasi(1));
    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(3));
    insertFirst(L, alokasi(4));
    insertFirst(L, alokasi(5));
    printInfo(L);
    cout << endl;
    deleteAll(L);

    return 0;
}
```

**Cara Kerja:**

1.  Fungsi `findElm` dibuat sebagai helper untuk mencari alamat node berdasarkan nilainya.
2.  Fungsi `deleteByValue` menggunakan `findElm` untuk menemukan target. Setelah ditemukan, ia memanggil fungsi hapus yang sesuai (`deleteFirst`, `deleteLast`, atau `deleteAfter`) untuk menghapus node.
3.  Fungsi `deleteAll` melakukan loop untuk memanggil `deleteFirst` berulang kali sampai list menjadi kosong.
4.  Fungsi `main` mendemonstrasikan kasus di mana nilai ditemukan, tidak ditemukan, dan penghapusan total.

**Output:**
![alt text](<Screenshot 2025-10-25 195117.png>)

### **5.3 Unguided 3: Operasi Lanjutan (`smartInsert` dan `conditionalDelete`)**

Tugas ini mengimplementasikan fungsi yang lebih kompleks: `smartInsert` dengan aturan penyisipan kondisional dan `conditionalDelete` untuk menghapus elemen berdasarkan kriteria tertentu.

**Source Code:**

```cpp
#include <iostream>
#include <string>
using namespace std;
#define Nil NULL

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

// --- FUNGSI DASAR ---
address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    P->prev = Nil;
    if (L.first != Nil) L.first->prev = P;
    else L.last = P;
    L.first = P;
}

void insertLast(List &L, address P) {
    P->prev = L.last;
    P->next = Nil;
    if (L.last != Nil) L.last->next = P;
    else L.first = P;
    L.last = P;
}

void insertAfter(List &L, address P, address R) {
    P->next = R->next;
    P->prev = R;
    if (R->next != Nil) R->next->prev = P;
    else L.last = P;
    R->next = P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
}

void printReverse(List L) {
    address P = L.last;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->prev;
    }
}

void deleteFirst(List &L, address &P) {
    P = L.first;
    L.first = L.first->next;
    if (L.first != Nil) L.first->prev = Nil;
    else L.last = Nil;
    P->next = Nil;
    P->prev = Nil;
}

void deleteLast(List &L, address &P) {
    P = L.last;
    L.last = L.last->prev;
    if (L.last != Nil) L.last->next = Nil;
    else L.first = Nil;
    P->prev = Nil;
    P->next = Nil;
}

void deleteAfter(List &L, address &P, address Prec) {
    P = Prec->next;
    Prec->next = P->next;
    if (P->next != Nil) P->next->prev = Prec;
    else L.last = Prec;
    P->prev = Nil;
    P->next = Nil;
}

void deleteAll(List &L, bool silent = false) {
    int count = 0;
    address P;
    while (L.first != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
        count++;
    }
    if (!silent) {
       cout << "Semua elemen (" << count << ") berhasil dihapus" << endl;
    }
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) { if (P->info == x) return P; P = P->next; }
    return Nil;
}

void deleteByValue(List &L, infotype x, bool silent = false) {
    address target = findElm(L, x);
    if (target == Nil) {
        if (!silent) cout << "Nilai " << x << " tidak ditemukan" << endl;
        return;
    }
    address P;
    if (target == L.first) deleteFirst(L, P);
    else if (target == L.last) deleteLast(L, P);
    else deleteAfter(L, P, target->prev);
    dealokasi(P);
    if (!silent) cout << "Nilai " << x << " berhasil dihapus" << endl;
}

// --- FUNGSI UNGUIDED (DIPERBAIKI) ---

void smartInsert(List &L, infotype x) {
    address P = alokasi(x);
    if (L.first == Nil) {
        insertFirst(L, P);
        cout << "Smart Insert: List kosong, insert " << x << " di first" << endl;
    } else if (x < L.first->info) {
        insertFirst(L, P);
        cout << "Smart Insert: " << x << " < first, insert di first" << endl;
    } else if (x % 2 == 0) {
        insertLast(L, P);
        cout << "Smart Insert: " << x << " genap, insert di last" << endl;
    } else {
        address R = L.first;
        while (R->next != Nil && R->next->info < x && R->next->info % 2 != 0) {
            R = R->next;
        }
        
        // FIX: Simpan info node selanjutnya SEBELUM insertAfter mengubah struktur list
        string nextInfo = (R->next != Nil) ? to_string(R->next->info) : "last";
        
        insertAfter(L, P, R);
        cout << "Smart Insert: " << x << " di antara " << R->info << " dan " << nextInfo << endl;
    }
}

void conditionalDelete(List &L) {
    int count = 0;
    address P = L.first;
    while (P != Nil) {
        address nextNode = P->next;
        if (P->info % 2 != 0) {
            deleteByValue(L, P->info, true);
            count++;
        }
        P = nextNode;
    }
    cout << "Conditional Delete: " << count << " elemen ganjil dihapus" << endl;
}

int main() {
    List L;
    L.first = Nil;
    L.last = Nil;

    cout << "ADVANCED OPERATIONS" << endl;
    cout << "SMART INSERT DEMO" << endl;
    smartInsert(L, 5);
    smartInsert(L, 3);
    smartInsert(L, 8);
    smartInsert(L, 6);
    smartInsert(L, 4);
    smartInsert(L, 7);
    
    cout << "\nHasil Smart Insert:" << endl;
    cout << "Forward: "; printInfo(L); cout << endl;
    cout << "Backward: "; printReverse(L); cout << endl;

    cout << "\nCONDITIONAL DELETE" << endl;
    cout << "Sebelum Conditional Delete: "; printInfo(L); cout << endl;
    conditionalDelete(L);
    cout << "Setelah Conditional Delete: "; printInfo(L); cout << endl;

    cout << "\nDELETE BY VALUE DEMO" << endl;
    deleteByValue(L, 6);
    deleteByValue(L, 10);
    cout << "List akhir: "; printInfo(L); cout << endl;
    
    cout << "\nDELETE ALL DEMO" << endl;
    deleteAll(L);

    return 0;
}
```

**Cara Kerja:**

1.  Fungsi `smartInsert` memiliki 4 blok `if-else` untuk menangani berbagai kondisi penyisipan sesuai aturan yang diberikan.
2.  Fungsi `conditionalDelete` melakukan traversal pada list. Di setiap node, ia memeriksa apakah nilainya ganjil. Jika ya, ia memanggil `deleteByValue` untuk menghapus node tersebut.
3.  Penting untuk menyimpan `P->next` ke variabel `nextNode` sebelum menghapus, agar traversal tidak terputus.
4.  Fungsi `main` mendemonstrasikan alur lengkap: membangun list dengan `smartInsert`, memfilternya dengan `conditionalDelete`, dan membersihkannya dengan fungsi hapus lainnya.

**Output:**
![alt text](<Screenshot 2025-10-28 160152.png>)

## 

## **6. Kesimpulan**

Kesimpulannya, praktikum ini memberikan pemahaman mendalam tentang implementasi dan manipulasi **Doubly Linked List**. Latihan *guided* menyediakan fondasi kode dasar, sementara latihan *unguided* menunjukkan bagaimana kode tersebut dapat dimodifikasi dan dikembangkan untuk menyelesaikan tiga tugas spesifik. Implementasi fungsi `insertBefore`, `deleteByValue`, `smartInsert`, dan `conditionalDelete` membuktikan bahwa penguasaan pointer `next` dan `prev` adalah kunci untuk membangun struktur data yang dinamis, fleksibel, dan efisien dalam mengelola data.

## **7. Referensi**

  - https://www-geeksforgeeks-org.translate.goog/dsa/difference-between-singly-linked-list-and-doubly-linked-list/?_x_tr_sl=en&_x_tr_tl=id&_x_tr_hl=id&_x_tr_pto=tc
  - Modul Praktikum Struktur Data Telkom University
  - https://www.mahirkoding.com/struktur-data-double-linked-list-dengan-bahasa-c/