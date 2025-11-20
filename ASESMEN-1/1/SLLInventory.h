#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


struct Product {
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen; 
};

typedef struct Node *address;
struct Node {
    Product info;
    address next;
};

struct List {
    address head;
};

bool isEmpty(List L);
void createList(List &L);
address allocate(Product P);
void deallocate(address P);

void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address P, address Q); 

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address &P, address Q);

void updateAtPosition(List &L, int posisi, Product info);
void viewList(List L);
void searchByFinalPrice(List L, float minPrice, float maxPrice);

void MaxHargaAkhir(List L); 

#endif