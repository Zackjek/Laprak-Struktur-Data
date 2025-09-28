#include <iostream>
using namespace std;

int main() {
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    cout << "Output: " << angka << " : ";

    //  Logika konversi angka dimulai di sini 
    const char* satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};

    if (angka < 0 || angka > 100) {
        cout << "Hanya support (0-100), soalnya disuruh gitu :v";
    } else if (angka == 0) {
        cout << "nol";
    } else if (angka == 100) {
        cout << "seratus";
    } else if (angka == 10) {
        cout << "sepuluh";
    } else if (angka == 11) {
        cout << "sebelas";
    } else if (angka < 10) {
        cout << satuan[angka];
    } else if (angka < 20) {
        cout << satuan[angka % 10] << " belas";
    } else {
        cout << satuan[angka / 10] << " puluh";
        if (angka % 10 != 0) {
            cout << " " << satuan[angka % 10];
        }
    }
    

    cout << endl;
    return 0;
}
//Muhammad Zaky Mubarok
//103112400073