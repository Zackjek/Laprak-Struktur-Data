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