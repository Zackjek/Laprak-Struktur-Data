#include <iostream>


using namespace std;

int main() {
    
    float bilangan1, bilangan2, hasil_penjumlahan, hasil_pengurangan, hasil_perkalian, hasil_pembagian; 
    cout << "Masukkan bilangan pertama: ";
    cin >> bilangan1;
    cout << "Masukkan bilangan kedua: ";
    cin >> bilangan2;

    hasil_penjumlahan = bilangan1 + bilangan2;
    hasil_pengurangan = bilangan1 - bilangan2;
    hasil_perkalian = bilangan1 * bilangan2; 
    cout << endl;
    cout << "Outputnya Dibawah Cuyy  " << endl;
    cout<< endl;
    cout << "Penjumlahan : " << hasil_penjumlahan << endl;
    cout << "Pengurangan : " << hasil_pengurangan << endl;
    cout << "Perkalian   : " << hasil_perkalian << endl;
    
    //Aturan pembagian Biar ga eror,soalnya semua angka tidak bisa dibagi 0 
    if (bilangan2 != 0) {
        hasil_pembagian = bilangan1 / bilangan2;
        cout << "Pembagian   : " << hasil_pembagian << endl;
    } else {
        cout << "Pembagian tu gabisa dibagi dengan 0 cik, jadi tolong ganti bilangan kedua selain 0" << endl;
    }

    return 0;
}

//Nama : Muhammad Zaky Mubarok
//NIM  : 103112400073