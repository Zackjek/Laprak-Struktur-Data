#include <iostream>
using namespace std;

int main() {
    int bukuPerHari[7] = {2, 1, 3, 2, 4, 5, 1};
    int totalBuku = 0;

    cout << "Laporan Baca Buku Mingguan" << endl;


    //mengakses setiap elemen array menggunakan loop
    for (int i = 0; i < 7; i++) {
        //mencetak nilai dari elemen pada indeks i
        cout << "Hari ke-" << i + 1 << ": " << bukuPerHari[i] << " buku." << endl;
        totalBuku += bukuPerHari[i];
    }

}