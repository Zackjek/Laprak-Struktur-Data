#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;

    cout << "output:\n";

    
    for (int i = n; i >= 1; --i) {
        
        // Loop spasi
        for (int spasi = 0; spasi < n - i; ++spasi) {
            cout << " ";
        }

        // Loop angka kiri
        for (int j = i; j >= 1; --j) {
            cout << j;
        }

        // Bintang tengah
        cout << "*";

        // Loop angka kanan
        for (int j = 1; j <= i; ++j) {
            cout << j;
        }

        // Pindah baris
        cout << endl;
    }
   

    return 0;
}
//Muhammad Zaky Mubarok
//103112400073