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