
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

struct Kendaraan {
    string nopol;
    string warna;
    int thnbuat;
};

using infotype = Kendaraan;

struct ElmList {
    infotype info;
    ElmList* next;
    ElmList* prev;
};

using address = ElmList*;

struct List {
    address first;
    address last;
};

void CreateList(List& L);
address alokasi(infotype X);
void dealokasi(address& P);
void printInfo(List L);
void insertLast(List& L, address P);
void inputData(address P);

address findElm(List L, string nopol);

void deleteFirst(List& L, address& P);
void deleteLast(List& L, address& P);
void deleteAfter(List& L, address Prec, address& P);
void deleteElm(List& L, address P);

#endif
