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