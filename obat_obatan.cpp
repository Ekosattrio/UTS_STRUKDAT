#include <iostream>
#include <string>
using namespace std;

// Struct untuk merepresentasikan obat jenis pil
struct ObatPil {
    string nama;
    int harga;
};

// Struct untuk merepresentasikan obat jenis sirup
struct ObatSirup {
    string nama;
    int harga;
};

// Class untuk linked list yang menyimpan daftar obat jenis sirup
class LinkedList {
private:
    struct Node {
        ObatSirup data;
        Node* next;
    };
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void tambahObat(string nama, int harga) {
        ObatSirup obat = {nama, harga};
        Node* baru = new Node {obat, nullptr};
        if (head == nullptr) {
            head = baru;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = baru;
        }
    }

    void tampilkanDaftarObat() {
        Node* temp = head;
        int i = 1;
        while (temp != nullptr) {
            cout << i << ". " << temp->data.nama << " - Rp" << temp->data.harga << endl;
            temp = temp->next;
            i++;
        }
    }

    ObatSirup* getObatSirupByIndex(int index) {
        Node* temp = head;
        int i = 1;
        while (temp != nullptr && i < index) {
            temp = temp->next;
            i++;
        }
        if (temp == nullptr) {
            return nullptr;
        } else {
            return &(temp->data);
        }
    }
};

int main() {
    ObatPil obatPil[3] = {{"Paracetamol", 5000}, {"Amoxicillin", 10000}, {"Omeprazole", 7000}};
    
    LinkedList daftarObatSirup;
    daftarObatSirup.tambahObat("Cetirizine", 8000);
    daftarObatSirup.tambahObat("Ambroxol", 6000);
    daftarObatSirup.tambahObat("Loperamide", 9000);

    int pilihanJenisObat;
    cout << "Pilih jenis obat:\n";
    cout << "1. Pil\n";
    cout << "2. Sirup\n";
    cout << "Pilihan: ";
    cin >> pilihanJenisObat;

    if (pilihanJenisObat == 1) {
        cout << "Daftar Obat Pil:\n";
        for (int i = 0; i < 3; ++i) {
            cout << i + 1 << ". " << obatPil[i].nama << " - Rp" << obatPil[i].harga << endl;
        }

        int pilihanObat;
        cout << "Pilih nomor obat yang ingin dibeli: ";
        cin >> pilihanObat;

        int jumlah;
        cout << "Masukkan jumlah obat yang ingin dibeli: ";
        cin >> jumlah;

        int totalHarga = obatPil[pilihanObat - 1].harga * jumlah;
        cout << "Total harga obat yang dibeli: Rp" << totalHarga << endl;

    } else if (pilihanJenisObat == 2) {
        cout << "Daftar Obat Sirup:\n";
        daftarObatSirup.tampilkanDaftarObat();

        int pilihanObat;
        cout << "Pilih nomor obat yang ingin dibeli: ";
        cin >> pilihanObat;

        int jumlah;
        cout << "Masukkan jumlah obat yang ingin dibeli: ";
        cin >> jumlah;

        ObatSirup* obatDipilih = daftarObatSirup.getObatSirupByIndex(pilihanObat);

        if (obatDipilih != nullptr) {
            int totalHarga = obatDipilih->harga * jumlah;
            cout << "Total harga obat yang dibeli: Rp" << totalHarga << endl;
        } else {
            cout << "Pilihan tidak valid." << endl;
            return 1;
        }
    } else {
        cout << "Pilihan tidak valid.\n";
        return 1;
    }

    return 0;
}
