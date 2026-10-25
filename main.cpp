
#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);

    int jumlah;
    cout << "Jumlah kendaraan: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData kendaraan ke-" << i + 1 << endl;

        Kendaraan K;
        cout << "Nomor Polisi : ";
        cin >> K.nopol;

        cout << "Warna        : ";
        cin >> K.warna;

        cout << "Tahun Buat   : ";
        cin >> K.thnbuat;

        insertLast(L, alokasi(K));
    }

    printInfo(L);

    string cari;
    cout << "\nMasukkan nomor polisi yang dicari: ";
    cin >> cari;

    address P = findElm(L, cari);

    if (P != nullptr) {
        cout << "\nData kendaraan ditemukan!" << endl;
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun Buat   : " << P->info.thnbuat << endl;

        char pilihan;
        cout << "\nHapus kendaraan ini? (y/n): ";
        cin >> pilihan;

        if (pilihan == 'y' || pilihan == 'Y') {
            deleteElm(L, P);
            cout << "Data berhasil dihapus." << endl;
        }
    } else {
        cout << "Nomor polisi tidak ditemukan." << endl;
    }

    printInfo(L);

    // Menghapus semua elemen sebelum program selesai
    while (L.first != nullptr) {
        address Hapus;
        deleteFirst(L, Hapus);
        dealokasi(Hapus);
    }

    return 0;
}
