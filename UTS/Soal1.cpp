//Soal 1 Single Linked List Nama Mahasiswa
//Muhammad Zaky Mubarok
#include<iostream>
#include<string>

using namespace std;

struct Node {
    string Mahasiswa;
    Node* next;
};

Node* head = NULL;

void insert(string mahasiswa_baru) {
    Node* newNode = new Node;
    newNode->Mahasiswa = mahasiswa_baru;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

}

void deleteNama() {
    if (head == NULL) {
        cout << "List kosong, tidak ada yang bisa dihapus." << endl;
        return;
    }

    if (head->next == NULL) {
        cout << "Mahasiswa " << head->Mahasiswa << " (elemen awal) berhasil dihapus." << endl;
        delete head;
        head = NULL;
        return;
    }

    Node* current = head;
    Node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    cout << "Masukkan nama Untuk delete: " ;
    cin >> current->Mahasiswa;
    prev->next = NULL;
    delete current;
}
    

void viewList() {
    if (head == NULL) {
        cout << "List kosong." << endl;
        return;
    }
    Node* current = head;
    while (current != NULL) {
        cout << " " << current->Mahasiswa;
        current = current->next;
    } 
    cout << endl;
}

void HitungGenap() {
    if (head == NULL) {
        cout << "List kosong. " << endl;
        return;
    }

    Node* current = head;
    int count = 0;

    while (current != NULL) {
        if (current->Mahasiswa.length() % 2 == 0) {
            count++;
        }
        current = current->next;
    }

    cout << "Jumlah Nama dengan huruf genap: " << count << endl;
}

int main() {
    int pilihan;
    string nama_mahasiswa;
    while (true) {
        cout << "Menu : " ;
        cout << "1. Insert, " ; 
        cout << "2. Delete, " ;
        cout << "3. View, " ;
        cout << "4. Hitung Genap, " ;
        cout << "0. Exit" << endl;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama: ";
                cin >> nama_mahasiswa;
                insert(nama_mahasiswa);
                break;
            case 2:
                deleteNama();
                break;
            case 3:
                viewList();
                break;
            case 4:
                HitungGenap();
                break;
            case 0:
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }

}