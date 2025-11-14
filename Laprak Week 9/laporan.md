# Laporan Praktikum Struktur Data

## 1. Nama, NIM, Kelas
- **Nama**: Muhammad Zaky Mubarok
- **NIM**: 103112400073
- **Kelas**: IF-12-05

## 2. Motivasi Belajar Struktur Data
Karena aku pengin bisa ngoding sampe tingkat lanjut, makanya aku semangat belajar.

## 3. Dasar Teori
Struktur data adalah cara untuk menyimpan dan mengorganisir data dalam komputer agar dapat digunakan secara efisien. Praktikum ini berfokus pada **Queue (Antrean)**.

- **Queue**: Merupakan struktur data linear yang mengikuti prinsip **FIFO (First-In, First-Out)**. Berbeda dengan Stack (LIFO), elemen yang pertama kali dimasukkan ke Queue adalah elemen yang pertama kali akan dikeluarkan. Analogi di dunia nyata adalah antrean loket; orang yang pertama datang akan dilayani pertama kali.
- **Head**: Penanda untuk elemen terdepan (yang akan keluar).
- **Tail**: Penanda untuk elemen terakhir (atau posisi di mana elemen baru akan masuk).
- **Implementasi Array**: Queue dapat diimplementasikan menggunakan array dengan beberapa alternatif:
    1.  **Alternatif 1 (Head Diam)**: `head` selalu di indeks 0. `enqueue` menambahkan data di belakang, `dequeue` mengambil data dari `head` dan menggeser semua elemen lain ke depan. Ini tidak efisien.
    2.  **Alternatif 2 (Head & Tail Bergerak Lurus)**: `head` dan `tail` bergerak ke kanan. `dequeue` lebih cepat (O(1)), tapi slot kosong di awal array tidak bisa dipakai lagi, menyebabkan "penuh semu" (boros memori).
    3.  **Alternatif 3 (Circular Queue)**: Implementasi paling efisien. `head` dan `tail` bergerak dan bisa "berputar" kembali ke indeks 0 menggunakan operator modulo (`%`). Ini memaksimalkan penggunaan array.

## 4. Guided
Bagian *guided* ini menunjukkan implementasi **Circular Queue** (Alternatif 3) yang paling modern dan efisien. Logika ini menggunakan variabel `count` untuk melacak jumlah elemen secara akurat, sehingga `head` dan `tail` bisa dimulai dari `0` tanpa kebingungan.

------

#### **`queue.h`**
```cpp
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 30

struct Queue {
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count; 
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif 
````

-----

#### **`queue.cpp`**

```cpp
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = 0;
    Q.count = 0; // Set count to 0
}

bool isEmpty(Queue Q) {
    return Q.count == 0; // Cek pakai count
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Cek pakai count
}

void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) {
        Q.info[Q.tail] = x; 
        Q.tail = (Q.tail + 1) % MAX_QUEUE; // Update tail secara melingkar
        Q.count++; // Increment count
    } else {
        cout << "Antrean Penuh!" << endl; 
    }
}

int dequeue(Queue &Q) {
    if (!isEmpty(Q)) {
        int x = Q.info[Q.head]; 
        Q.head = (Q.head + 1) % MAX_QUEUE; // Update head secara melingkar
        Q.count--; // Decrement count
        return x; 
    } else {
        cout << "Antrean Kosong!" << endl; 
        return -1; 
    }
}

void printInfo(Queue Q) {
    cout << "Isi Queue: [";
    if(!isEmpty (Q)){
        int i = Q.head; 
        int n = 0; 
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen 
            cout << Q.info[i]; 
            i = (i + 1) % MAX_QUEUE; 
            n++;
            if (n < Q.count) cout << " "; // Pemisah spasi
    }
 }
    cout << "]" << endl;
}
```

-----

#### **`main.cpp`**

```cpp
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue Q;
    createQueue(Q);

    printInfo(Q); // Tampilkan antrian kosong

    cout << "\n Enqueue 3 Elemen" << endl;
    enqueue(Q,5);
    printInfo(Q);
    enqueue(Q,2);
    printInfo(Q);
    enqueue(Q,7);
    printInfo(Q);

    cout << "\n Dequeue 1 Elemen" << endl;
    cout << "Elemen keluar:" << dequeue(Q) << endl;
    printInfo(Q);

    cout << "\n Enqueue 1 Elemen" << endl;
    enqueue(Q,4);
    printInfo(Q);

    cout << "\n Dequeue 2 Elemen" << endl;
    cout << "Elemen keluar:" << dequeue(Q) << endl;
    printInfo(Q);
    return 0;
}
```
**Output:**
![alt text](<Screenshot 2025-11-14 161044.png>)



## 5. Unguided

Bagian *unguided* meminta implementasi tiga alternatif Queue sesuai spesifikasi soal (Array[5], `head`, `tail`). `main.cpp` yang digunakan sesuai dengan "Gambar 8-18" dan alur output "Gambar 8-17".

### 5.1 Unguided 1 (Alternatif 1: Head Diam)

Implementasi ini lambat karena `dequeue` harus menggeser semua elemen (O(n)). `CreateQueue` diubah ke `-1` agar outputnya sesuai dengan gambar di soal.

#### **`queue.h`**

```cpp
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5 
typedef int infotype;

struct Queue {
    infotype info[MAX_QUEUE];
    int head;
    int tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif 
```

-----

#### **`queue.cpp`**

```cpp
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q) {
    // Di-set -1 agar sesuai output di gambar soal
    Q.head = -1; 
    Q.tail = -1; 
}

bool isEmptyQueue(Queue Q) {
    return (Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX_QUEUE - 1); 
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Antrean Penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0; // Kasus khusus: head jadi 0 saat elemen pertama masuk
        }
        Q.tail++; // Tail bergerak
        Q.info[Q.tail] = x;
    }
}

int dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Antrean Kosong!" << endl;
        return -1;
    } else {
        int x = Q.info[Q.head]; // Ambil elemen dari head (indeks 0)
        
        // Geser semua elemen lain ke depan
        for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail--; // Mundurkan tail
        
        // Kasus khusus: jika tail jadi -1 (kosong), head juga di-reset
        if (Q.tail == -1) {
            Q.head = -1;
        }
        return x;
    }
}

void printInfo(Queue Q) {
    
    if (Q.head >= 0) {
        cout << " ";
    }
    cout << Q.head << " -- ";

   
    if (Q.tail >= 0) {
        cout << " ";
    }
    cout << Q.tail << " | ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << (i == Q.tail ? "" : " ");
        }
        cout << endl;
    }
}
```

-----

#### **`unguided1.cpp` (main.cpp)**

```cpp
#include <iostream>
#include "queue.h" 
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    CreateQueue(Q);

    cout << "-----------------------------------" << endl;
    cout << " H --  T | Queue Info" << endl; 
    cout << "-----------------------------------" << endl;
    
    printInfo(Q); 

    enqueue(Q, 5); printInfo(Q); 
    enqueue(Q, 2); printInfo(Q); 
    enqueue(Q, 7); printInfo(Q); 
    
    
    dequeue(Q); printInfo(Q); 
    dequeue(Q); printInfo(Q); 
    
    enqueue(Q, 4); printInfo(Q); 
    
    dequeue(Q); printInfo(Q); 
    dequeue(Q); printInfo(Q); 

    return 0; 
}
```
**Output :** 
![alt text](<Screenshot 2025-11-14 155045.png>)





### 5.2 Unguided 2 (Alternatif 2: Head & Tail Bergerak Lurus)

Implementasi ini cepat untuk `dequeue` (O(1)), tapi boros memori karena tidak bisa berputar. Kode ini akan menghasilkan output yang berbeda dari Gambar soal.

#### **`queue.h`**

```cpp
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5 
typedef int infotype;
struct Queue {
    infotype info[MAX_QUEUE];
    int head;
    int tail;
};
void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif 
```

-----

#### **`queue.cpp`**

```cpp
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX_QUEUE - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (!isFullQueue(Q)) {
        if (isEmptyQueue(Q)) {
            Q.head = 0; 
        }
        Q.tail++; 
        Q.info[Q.tail] = x;
    } else {
        cout << "Antrean Penuh!" << endl;
    }
}

int dequeue(Queue &Q) {
    if (!isEmptyQueue(Q)) {
        int x = Q.info[Q.head]; 
        Q.head++; 
        
        if (Q.head > Q.tail) {
            CreateQueue(Q); 
        }
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

void printInfo(Queue Q) {
    if (Q.head >= 0) {
        cout << " ";
    }
    cout << Q.head << " -- ";

    if (Q.tail >= 0) {
        cout << " ";
    }
    cout << Q.tail << " | ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << (i == Q.tail ? "" : " ");
        }
        cout << endl;
    }
}
```

-----

#### **`unguided2.cpp` (main.cpp)**

```cpp
#include <iostream>
#include "queue.h" 
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    CreateQueue(Q);

    cout << "-----------------------------------" << endl;
    cout << " H --  T | Queue Info" << endl; 
    cout << "-----------------------------------" << endl;
    
    printInfo(Q); 

    enqueue(Q, 5); printInfo(Q); 
    enqueue(Q, 2); printInfo(Q); 
    enqueue(Q, 7); printInfo(Q); 
    
    
    dequeue(Q); printInfo(Q); 
    enqueue(Q, 4); printInfo(Q); 
    
    dequeue(Q); printInfo(Q); 
    
    dequeue(Q); printInfo(Q); 
    dequeue(Q); printInfo(Q); 

    return 0; 
}
```

**Output:**
![alt text](<Screenshot 2025-11-14 155059.png>)
```



### 5.3 Unguided 3 (Alternatif 3: Circular)

Implementasi **Circular Queue** yang menggunakan `count`, persis seperti di *guided*. Ini adalah cara yang paling efisien dan modern.

#### **`queue.h`**

```cpp
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5 
typedef int infotype;

struct Queue {
    infotype info[MAX_QUEUE];
    int head;
    int tail;
    int count; 
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif 
```

-----

#### **`queue.cpp`**

```cpp
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = 0;
    Q.count = 0; 
}

bool isEmptyQueue(Queue Q) {
    return Q.count == 0; 
}

bool isFullQueue(Queue Q) {
    return Q.count == MAX_QUEUE; 
}

void enqueue(Queue &Q, infotype x) {
    if (!isFullQueue(Q)) {
        Q.info[Q.tail] = x;
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; 
    } else {
        cout << "Antrean Penuh!" << endl;
    }
}

int dequeue(Queue &Q) {
    if (!isEmptyQueue(Q)) {
        int x = Q.info[Q.head];
        Q.head = (Q.head + 1) % MAX_QUEUE; 
        Q.count--; 
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

void printInfo(Queue Q) {
    if (Q.head >= 0) {
        cout << " ";
    }
    cout << Q.head << " -- ";
    
    if (Q.tail >= 0) {
        cout << " ";
    }
    cout << Q.tail << " | ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        int i = Q.head;
        int n = 0;
        while (n < Q.count) { 
            cout << Q.info[i];
            i = (i + 1) % MAX_QUEUE;
            n++;
            if (n < Q.count) cout << " "; 
        }
        cout << endl;
    }
}
```

-----

#### **`unguided3.cpp` (main.cpp)**

```cpp
#include <iostream>
#include "queue.h" 
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    CreateQueue(Q);

    cout << "-----------------------------------" << endl;
    cout << " H --  T | Queue Info" << endl; 
    cout << "-----------------------------------" << endl;
    
    printInfo(Q); 

    enqueue(Q, 5); printInfo(Q); 
    enqueue(Q, 2); printInfo(Q); 
    enqueue(Q, 7); printInfo(Q); 
    
    dequeue(Q); printInfo(Q); 
    enqueue(Q, 4); printInfo(Q); 
    
    dequeue(Q); printInfo(Q); 
    
    dequeue(Q); printInfo(Q); 
    dequeue(Q); printInfo(Q); 

    return 0; 
}
```
**Output:**
![alt text](<Screenshot 2025-11-14 155113.png>)



## 6. Kesimpulan

Praktikum ini berhasil mengimplementasikan tiga alternatif Queue menggunakan array.

1.  **Unguided 1 (Head Diam)** terbukti paling tidak efisien karena `dequeue` harus menggeser semua elemen (O(n)).
2.  **Unguided 2 (Bergerak Lurus)** lebih efisien untuk `dequeue` (O(1)), tetapi boros memori karena tidak bisa memakai ulang slot (terjadi "penuh semu").
3.  **Unguided 3 (Circular - Sesuai Guided)** adalah implementasi terbaik. Dengan `count` dan logika modulo (`%`), antrean bisa berputar, efisien (O(1) untuk `enqueue` dan `dequeue`), dan memaksimalkan penggunaan memori.

Tujuan praktikum untuk memahami *trade-off* setiap implementasi dan pentingnya **Circular Queue**.

## 7. Referensi

1.  Modul Struktur Data Queue.
2.  https://www.dicoding.com/blog/struktur-data-queue-pengertian-fungsi-dan-jenisnya/
3.  https://course-net.com/blog/struktur-data-queue-pengertian-jenis-contoh-struktur-data-queue-dalam-mengolah-data/



```
```