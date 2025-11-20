#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating; 
};

typedef struct Node *address;
struct Node {
    Song info;
    address prev;
    address next;
};

struct List {
    address head;
    address tail;
};

bool isEmpty(List L);
void createList(List &L);
address allocate(Song S);
void deallocate(address P);

void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address P, address Q);
void insertBefore(List &L, address P, address Q); 

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address &P, address Q);
void deleteBefore(List &L, address &P, address Q); 

void updateAtPosition(List &L, int posisi, Song info);
void updateBefore(List &L, address Q, Song info); 
void viewList(List L);
void searchByPopularityRange(List L, float minScore, float maxScore);

#endif