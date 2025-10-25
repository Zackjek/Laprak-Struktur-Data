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
