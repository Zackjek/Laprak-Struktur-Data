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