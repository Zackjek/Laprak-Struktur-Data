# Laporan Praktikum Struktur Data

## 1. Nama, NIM, Kelas
- **Nama**: Muhammad Zaky Mubarok
- **NIM**: 103112400073
- **Kelas**: IF-12-05

## 2. Motivasi Belajar Struktur Data
Karena aku pengin bisa ngoding sampe tingkat lanjut, makanya aku semangat belajar.

## 3. Dasar Teori
Pada praktikum kali ini, kita mempelajari struktur data **Graph**.

### 3.1 Pengertian Graph
Graph merupakan himpunan tidak kosong dari node (vertec) dan garis penghubung (edge). Graph digunakan untuk merepresentasikan objek-objek diskrit dan hubungan antara objek-objek tersebut. Contoh sederhananya adalah peta kota, di mana tempat merupakan node dan jalan yang menghubungkannya adalah edge .

### 3.2 Jenis-Jenis Graph
1.  **Graph Berarah (Directed Graph)**: Merupakan graph dimana tiap node memiliki edge yang memiliki arah, kemana node tersebut dihubungkan.
2.  **Graph Tidak Berarah (Undirected Graph)**: Merupakan graph dimana tiap node memiliki edge yang dihubungkan ke node lain tanpa arah. Jika node A terhubung dengan B, maka B juga terhubung dengan A.

### 3.3 Metode Penelusuran (Traversal)
1.  **Breadth First Search (BFS)**: Metode penelusuran yang mengunjungi simpul mulai dari akar (root) atau node awal, kemudian melebar ke seluruh tetangganya di level yang sama sebelum turun ke level kedalaman berikutnya. Algoritma ini menggunakan struktur data **Queue**.
2.  **Depth First Search (DFS)**: Metode penelusuran yang mengunjungi simpul akar, kemudian menelusuri salah satu cabang sedalam mungkin sebelum kembali (backtracking) untuk menelusuri cabang lain. Algoritma ini menggunakan struktur data **Stack**.

---

## 4. Guided

Bagian ini mengimplementasikan **Directed Graph** (Graph Berarah) menggunakan representasi **Adjacency List** dengan tipe data `char`. Implementasi dipecah menjadi beberapa file untuk modularitas.

### 4.1 `graph.h`
```cpp
#ifndef GRAP_H
#define GRAP_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode*adrNode;
typedef struct ElmEdge*adrEdge;

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

//Protoypes
void createGraph(Graph &G);
adrNode allocateNode(infoGraph x);
void insertNode(Graph &G, infoGraph x);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif
````

### 4.2 `graph_init.cpp`

```cpp
#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void insertNode(Graph &G, infoGraph X) {
    adrNode P = allocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
```

### 4.3 `graph_edge.cpp`

```cpp
#include "graph.h"

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) 
            return P;
        
        P = P->next;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge; //Insert First di list edge
        pStart->firstEdge = newEdge;
    }
}
```

### 4.4 `graph_print.cpp`

```cpp
#include "graph.h"

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
```

### 4.5 `main.cpp`

```cpp
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    createGraph(G);

    // Menambahkan Node A, B, C, D
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    // Menghubungkan Node (Sesuai contoh materi)
    connectNode(G, 'A', 'B'); // A ke B
    connectNode(G, 'A', 'C'); // A ke C
    connectNode(G, 'B', 'D'); // B ke D
    connectNode(G, 'C', 'D'); // C ke D

    cout << "Isi Graph:" << endl;
    printGraph(G);

    return 0;
}
```

**Output :**

![alt text](<Screenshot 2025-12-12 145400.png>)

**Penjelasan Guided (Graph Berarah / Directed Graph)**

Pada bagian Guided ini tuh mengimplementasikan Graph Berarah (Directed Graph) menggunakan struktur data Adjacency List (mirip dengan Multilist).

    Konsep: Hubungan antar node memiliki arah yang spesifik (satu arah). Jika Node A terhubung ke Node B, artinya ada jalur dari A menuju B, tetapi belum tentu ada jalur sebaliknya dari B ke A.

    Struktur Data:

        Node : Disimpan dalam Linked List utama. Setiap node berisi informasi (char A, B, C, dst) dan pointer ke list edge.

        Edge: Disimpan sebagai Linked List cabang (anak) di dalam setiap node. List ini berisi daftar node tujuan yang bisa dijangkau dari node tersebut.

    Implementasi: Fokus utama ada di fungsi connectNode. Di sini, edge baru hanya ditambahkan pada list milik node Start yang menunjuk ke node End. Tidak ada penambahan edge sebaliknya (karena sifatnya berarah/satu arah).

-----

## 5. Unguided

### 5.1 Unguided 1 (Implementasi Graph Tidak Berarah)

Pada tugas ini, kita diminta untuk mengimplementasikan **Graph Tidak Berarah (Undirected Graph)**. Perbedaan utamanya terletak pada prosedur `connectNode`. Jika kita menghubungkan node A ke node B, maka secara otomatis node B juga terhubung ke node A (dua arah).

#### `graph.h`

```cpp
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited; 
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void createGraph(Graph &G);
adrNode allocateNode(infoGraph x);
void insertNode(Graph &G, infoGraph x);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif
```

#### `graph.cpp`

```cpp
#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

void insertNode(Graph &G, infoGraph X) {
    if (findNode(G, X) == NULL) { 
        adrNode P = allocateNode(X);
        if (G.first == NULL) {
            G.first = P;
        } else {
            adrNode Q = G.first;
            while (Q->next != NULL) {
                Q = Q->next;
            }
            Q->next = P;
        }
    }
}

// Modifikasi menjadi Undirected (Dua Arah)
void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        // 1. Buat edge dari Start ke End
        adrEdge edge1 = new ElmEdge;
        edge1->node = pEnd;
        edge1->next = pStart->firstEdge;
        pStart->firstEdge = edge1;

        // 2. Buat edge dari End ke Start (Kebalikannya)
        adrEdge edge2 = new ElmEdge;
        edge2->node = pStart;
        edge2->next = pEnd->firstEdge;
        pEnd->firstEdge = edge2;
    }
}

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << ":";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << " -> " << E->node->info;
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
```

#### `main.cpp`

Membentuk graph sesuai dengan modul.

```cpp
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    createGraph(G);

    // 1. Insert Node A sampai H
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');
    insertNode(G, 'F');
    insertNode(G, 'G');
    insertNode(G, 'H');

    // 2. Connect Node (Undirected) 
    
    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');

    
    connectNode(G, 'B', 'D');
    connectNode(G, 'B', 'E');
    connectNode(G, 'C', 'F');
    connectNode(G, 'C', 'G');

    
    connectNode(G, 'D', 'H');
    connectNode(G, 'E', 'H');
    connectNode(G, 'F', 'H');
    connectNode(G, 'G', 'H');

    // Tampilkan Graph
    cout << "=== TAMPILAN GRAPH (Undirected) ===" << endl;
    printGraph(G);

    return 0;
}
```
**Output :**
![alt text](<Screenshot 2025-12-12 143412.png>)

**Penjelasan Unguided 1 (Graph Tidak Berarah)**

Pada bagian ini itu memodifikasi kode Guided agar menjadi Graph Tidak Berarah (Undirected Graph). Perbedaan utamanya ada di logika prosedur connectNode.

    Logika: Jika kita menghubungkan Node A ke Node B, maka secara otomatis Node B juga harus terhubung ke Node A.

    Implementasi: Di dalam fungsi connectNode, kita membuat dua edge sekaligus: satu dari Start ke End, dan satu lagi dari End ke Start. Ini berbeda dengan graph berarah yang hanya membuat satu edge satu arah.

-----

### 5.2 Unguided 2 (Depth First Search)

membuat prosedur untuk menampilkan hasil penelusuran **DFS (Depth First Search)**. Saya menggunakan bantuan library `<stack>` untuk mengimplementasikan algoritma ini.

#### `graph.h`

```cpp
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    bool visited; 
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void createGraph(Graph &G);
adrNode allocateNode(infoGraph x);
void insertNode(Graph &G, infoGraph x);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

// DFS
void resetVisited(Graph &G);
void printDFS(Graph G, adrNode start);

#endif
```

#### `graph.cpp`

```cpp
#include "graph.h"
#include <stack> // Library untuk DFS

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

void insertNode(Graph &G, infoGraph X) {
    if (findNode(G, X) == NULL) {
        adrNode P = allocateNode(X);
        if (G.first == NULL) {
            G.first = P;
        } else {
            adrNode Q = G.first;
            while (Q->next != NULL) {
                Q = Q->next;
            }
            Q->next = P;
        }
    }
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge edge1 = new ElmEdge;
        edge1->node = pEnd;
        edge1->next = pStart->firstEdge;
        pStart->firstEdge = edge1;

        adrEdge edge2 = new ElmEdge;
        edge2->node = pStart;
        edge2->next = pEnd->firstEdge;
        pEnd->firstEdge = edge2;
    }
}

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << ":";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << " -> " << E->node->info;
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

// Implementasi DFS
void resetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = false;
        P = P->next;
    }
}

void printDFS(Graph G, adrNode start) {
    if (start == NULL) return;
    
    resetVisited(G);
    
    stack<adrNode> S;
    S.push(start);
    
    cout << "DFS Traversal: ";
    while (!S.empty()) {
        adrNode curr = S.top();
        S.pop();
        
        if (!curr->visited) {
            curr->visited = true;
            cout << curr->info << " ";
            
            adrEdge E = curr->firstEdge;
            while (E != NULL) {
                if (!E->node->visited) {
                    S.push(E->node);
                }
                E = E->next;
            }
        }
    }
    cout << endl;
}
```

#### `main.cpp`

```cpp
#include "graph.h"

adrNode findNodeMain(Graph G, char x) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == x) return P;
        P = P->next;
    }
    return NULL;
}

int main() {
    Graph G;
    createGraph(G);

    insertNode(G, 'A'); insertNode(G, 'B'); insertNode(G, 'C'); insertNode(G, 'D');
    insertNode(G, 'E'); insertNode(G, 'F'); insertNode(G, 'G'); insertNode(G, 'H');

    connectNode(G, 'A', 'B'); connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D'); connectNode(G, 'B', 'E');
    connectNode(G, 'C', 'F'); connectNode(G, 'C', 'G');
    connectNode(G, 'D', 'H'); connectNode(G, 'E', 'H');
    connectNode(G, 'F', 'H'); connectNode(G, 'G', 'H');

    // DFS dari A
    printDFS(G, findNodeMain(G, 'A'));

    return 0;
}
```

**Output :**

![alt text](<Screenshot 2025-12-12 143429.png>)

**Penjelasan Unguided 2 (Depth First Search - DFS)**

Unguided 2 meminta menampilkan urutan penelusuran menggunakan algoritma DFS.

    Konsep: Penelusuran mendalam. Algoritmanya berjalan dari node awal, lalu menelusuri satu cabang sejauh mungkin ke bawah sampai mentok (tidak ada tetangga baru), baru kemudian mundur (backtracking) ke persimpangan sebelumnya untuk menelusuri cabang lain.

    Implementasi: Menggunakan struktur data bantuan Stack (Tumpukan). Node yang dikunjungi dimasukkan ke stack, dan kita selalu memproses node yang ada di paling atas stack (LIFO - Last In First Out).

-----

### 5.3 Unguided 3 (Breadth First Search)

membuat prosedur untuk menampilkan hasil penelusuran **BFS (Breadth First Search)**. Saya menggunakan bantuan library `<queue>` untuk mengimplementasikan algoritma ini.

#### `graph.h`

```cpp
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void createGraph(Graph &G);
adrNode allocateNode(infoGraph x);
void insertNode(Graph &G, infoGraph x);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

// bfs
void resetVisited(Graph &G);
void printBFS(Graph G, adrNode start);

#endif
```

#### `graph.cpp`

```cpp
#include "graph.h"
#include <queue> // Library untuk BFS

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

void insertNode(Graph &G, infoGraph X) {
    if (findNode(G, X) == NULL) {
        adrNode P = allocateNode(X);
        if (G.first == NULL) {
            G.first = P;
        } else {
            adrNode Q = G.first;
            while (Q->next != NULL) {
                Q = Q->next;
            }
            Q->next = P;
        }
    }
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge edge1 = new ElmEdge;
        edge1->node = pEnd;
        edge1->next = pStart->firstEdge;
        pStart->firstEdge = edge1;

        adrEdge edge2 = new ElmEdge;
        edge2->node = pStart;
        edge2->next = pEnd->firstEdge;
        pEnd->firstEdge = edge2;
    }
}

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << ":";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << " -> " << E->node->info;
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

// Implementasi BFS
void resetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = false;
        P = P->next;
    }
}

void printBFS(Graph G, adrNode start) {
    if (start == NULL) return;
    
    resetVisited(G);
    
    queue<adrNode> Q;
    Q.push(start);
    start->visited = true;
    
    cout << "BFS Traversal: ";
    while (!Q.empty()) {
        adrNode curr = Q.front();
        Q.pop();
        cout << curr->info << " ";
        
        adrEdge E = curr->firstEdge;
        while (E != NULL) {
            if (!E->node->visited) {
                E->node->visited = true;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
    cout << endl;
}
```

#### `main.cpp`

```cpp
#include "graph.h"

adrNode findNodeMain(Graph G, char x) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == x) return P;
        P = P->next;
    }
    return NULL;
}

int main() {
    Graph G;
    createGraph(G);

    insertNode(G, 'A'); insertNode(G, 'B'); insertNode(G, 'C'); insertNode(G, 'D');
    insertNode(G, 'E'); insertNode(G, 'F'); insertNode(G, 'G'); insertNode(G, 'H');

    connectNode(G, 'A', 'B'); connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D'); connectNode(G, 'B', 'E');
    connectNode(G, 'C', 'F'); connectNode(G, 'C', 'G');
    connectNode(G, 'D', 'H'); connectNode(G, 'E', 'H');
    connectNode(G, 'F', 'H'); connectNode(G, 'G', 'H');

    // BFS dari A
    printBFS(G, findNodeMain(G, 'A'));

    return 0;
}
```
**Output :**

![alt text](<Screenshot 2025-12-12 143435.png>)

**Penjelasan Unguided 3 (Breadth First Search - BFS)**

Unguided 3  disuruh menampilkan urutan penelusuran menggunakan algoritma BFS.

    Konsep: Penelusuran melebar. Algoritma ini mengunjungi node awal, lalu mengunjungi semua tetangga langsungnya terlebih dahulu (tetangga level 1), sebelum pindah ke tetangga-tetangga di level berikutnya (level 2, dst).

    Implementasi: Menggunakan struktur data bantuan Queue (Antrean). Node yang dikunjungi dimasukkan ke antrean, dan kita memproses node sesuai urutan kedatangannya (FIFO - First In First Out), sehingga penelusuran terjadi secara merata per level.

## 6. Kesimpulan

Praktikum ini memberikan pemahaman mendalam tentang struktur data Graph.

1.  **Guided**: Mempelajari dasar implementasi Graph Berarah menggunakan adjacency list.
2.  **Unguided 1**: Memodifikasi kode menjadi Graph Tidak Berarah (Undirected), di mana koneksi antar node bersifat dua arah.
3.  **Unguided 2 & 3**: Mengimplementasikan algoritma penelusuran graph. **DFS (Depth First Search)** menelusuri secara mendalam menggunakan Stack, sedangkan **BFS (Breadth First Search)** menelusuri secara melebar menggunakan Queue. Kedua algoritma ini sangat penting dalam pemecahan masalah yang melibatkan jaringan atau pathfinding.

## 7. Referensi

1.  *Draft Modul Struktur Data SE Ganjil-2526*. Telkom University.
2.  https://www-geeksforgeeks-org.translate.goog/dsa/difference-between-bfs-and-dfs/?_x_tr_sl=en&_x_tr_tl=id&_x_tr_hl=id&_x_tr_pto=tc
3.  https://fikti.umsu.ac.id/graph-pengertian-fungsi-dan-jenisnya/


