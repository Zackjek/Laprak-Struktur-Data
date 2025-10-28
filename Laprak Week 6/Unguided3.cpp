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