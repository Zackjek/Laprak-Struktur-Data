#include<iostream>
using namespace std;

int main() {
    float hargaProduk = 50000.0f;

    //deskripsi poimter
    float *ptrHarga;
    ptrHarga = &hargaProduk;

    cout << "Harga produk: " << hargaProduk << endl;
    cout << "Alamat memori harga: " << ptrHarga << endl;

    cout <<"\n...Memberikan diskon 10% melalui pointer..." << endl;
    *ptrHarga = *ptrHarga * 0.9f;

    cout << "Harga produk setelah diskon: Rp. " << hargaProduk << endl;
    return 0;
}