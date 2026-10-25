
#include "Doublylist.h"

void CreateList(List& L) {
    L.first = nullptr;
    L.last = nullptr;
}

address alokasi(infotype X) {
    address P = new ElmList;
    P->info = X;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(address& P) {
    if (P != nullptr) {
        delete P;
        P = nullptr;
    }
}

void inputData(address P) {
    if (P == nullptr) return;

    cout << "Nomor Polisi : ";
    cin >> P->info.nopol;

    cout << "Warna        : ";
    cin >> P->info.warna;

    cout << "Tahun Buat   : ";
    cin >> P->info.thnbuat;
}

void insertLast(List& L, address P) {
    if (P == nullptr) return;

    P->next = nullptr;
    P->prev = nullptr;

    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void printInfo(List L) {
    address P = L.first;

    if (P == nullptr) {
        cout << "List kosong." << endl;
        return;
    }

    cout << "\n=== DATA KENDARAAN ===" << endl;
    while (P != nullptr) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun Buat   : " << P->info.thnbuat << endl;
        cout << "----------------------" << endl;

        P = P->next;
    }
}

address findElm(List L, string nopol) {
    address P = L.first;

    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }

    return nullptr;
}

void deleteFirst(List& L, address& P) {
    if (L.first == nullptr) {
        P = nullptr;
        return;
    }

    P = L.first;

    if (L.first == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.first = P->next;
        L.first->prev = nullptr;
    }

    P->next = nullptr;
    P->prev = nullptr;
}

void deleteLast(List& L, address& P) {
    if (L.last == nullptr) {
        P = nullptr;
        return;
    }

    P = L.last;

    if (L.first == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.last = P->prev;
        L.last->next = nullptr;
    }

    P->next = nullptr;
    P->prev = nullptr;
}

void deleteAfter(List& L, address Prec, address& P) {
    P = nullptr;

    if (Prec == nullptr || Prec->next == nullptr) {
        return;
    }

    P = Prec->next;
    Prec->next = P->next;

    if (P->next != nullptr) {
        P->next->prev = Prec;
    } else {
        L.last = Prec;
    }

    P->next = nullptr;
    P->prev = nullptr;
}

void deleteElm(List& L, address P) {
    if (P == nullptr) return;

    address Hapus = nullptr;

    if (P == L.first) {
        deleteFirst(L, Hapus);
    } else if (P == L.last) {
        deleteLast(L, Hapus);
    } else {
        deleteAfter(L, P->prev, Hapus);
    }

    dealokasi(Hapus);
}
