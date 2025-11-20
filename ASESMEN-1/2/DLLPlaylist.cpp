#include "DLLPlaylist.h"


float hitungPopularityScore(Song S) {
    return 0.8 * S.PlayCount + 20.0 * S.Rating;
}

address allocate(Song S) {
    address newNode = new Node;
    newNode->info = S;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void createList(List &L) {
    L.head = nullptr;
    L.tail = nullptr;
}

void insertFirst(List& L, Node* P) {
}


void insertLast(List &L, address P) {
    if (L.head == nullptr) {
        L.head = P;
        L.tail = P;
    } else {
        P->prev = L.tail;
        L.tail->next = P;
        L.tail = P;
    }
}

void deleteLast(List &L, address &P) {
    if (L.tail != nullptr) {
        P = L.tail;
        if (L.head == L.tail) { 
            L.head = nullptr;
            L.tail = nullptr;
        } else {
            L.tail = L.tail->prev;
            L.tail->next = nullptr;
        }
        P->prev = nullptr;
        P->next = nullptr; 
    } else {
        P = nullptr;
    }
}

address findNodeByPosition(List L, int posisi) {
    if (posisi <= 0) return nullptr;
    address current = L.head;
    int count = 1;
    while (current != nullptr && count < posisi) {
        current = current->next;
        count++;
    }
    return current;
}

void updateAtPosition(List &L, int posisi, Song info) {
    address current = findNodeByPosition(L, posisi);
    if (current != nullptr) {
        current->info = info; 
        cout << "Node pada posisi ke-" << posisi << " berhasil diupdate." << endl;
    } else {
        cout << "Posisi tidak valid atau list kosong." << endl;
    }
}

void viewList(List L) {
    address p = L.head;
    int index = 1;
    cout << "--- DLL Playlist Lagu ---" << endl;
    cout << left << setw(5) << "Idx" << setw(20) << "Title" << setw(15) << "Artist"
        << setw(10) << "Dur(s)" << setw(10) << "PlayCnt" << setw(10) << "Rating"
        << setw(15) << "Popularity" << endl;
    cout << string(85, '-') << endl;

    while (p != nullptr) {
        float score = hitungPopularityScore(p->info);
        cout << left << setw(5) << index
            << setw(20) << p->info.Title
            << setw(15) << p->info.Artist
            << setw(10) << p->info.DurationSec
            << setw(10) << p->info.PlayCount
            << setw(10) << fixed << setprecision(1) << p->info.Rating
            << setw(15) << fixed << setprecision(1) << score << endl;
        p = p->next;
        index++;
    }
    if (L.head == nullptr) {
        cout << "List kosong." << endl;
    }
    cout << string(85, '-') << endl;
}

void insertBefore(List &L, address P, address Q) {
    if (Q == nullptr) return; 

    if (Q == L.head) {
        insertFirst(L, P);
    } else {
        P->prev = Q->prev;
        P->next = Q;
        Q->prev->next = P;
        Q->prev = P;
    }
}

void updateBefore(List &L, address Q, Song info) {
    if (Q != nullptr && Q->prev != nullptr) {
        Q->prev->info = info;
        cout << "Node sebelum '" << Q->info.Title << "' berhasil diupdate." << endl;
    } else if (Q == L.head) {
        cout << "Node tidak memiliki predecessor." << endl;
    } else {
        cout << "Node tidak ditemukan atau list kosong." << endl;
    }
}

void deleteBefore(List &L, address &P, address Q) {
    P = nullptr;
    if (Q != nullptr && Q->prev != nullptr) {
        P = Q->prev;
        if (P == L.head) { 
            deleteFirst(L, P);
        } else {
            P->prev->next = Q;
            Q->prev = P->prev;
            P->next = nullptr;
            P->prev = nullptr;
        }
    }
}

void deleteFirst(List &L, address &P) {
    if (L.head != nullptr) {
        P = L.head;
        L.head = L.head->next;
        if (L.head != nullptr) {
            L.head->prev = nullptr;
        } else {
            L.tail = nullptr;
        }
        P->next = nullptr;
        P->prev = nullptr;
    } else {
        P = nullptr;
    }
}

void searchByPopularityRange(List L, float minScore, float maxScore) {
    address p = L.head;
    int index = 1;
    bool found = false;

    cout << "\n--- Hasil Pencarian Popularity Score [" << fixed << setprecision(1) << minScore << " - " << maxScore << "] ---" << endl;
    cout << left << setw(5) << "Idx" << setw(20) << "Title" << setw(15) << "Popularity" << endl;
    cout << string(40, '-') << endl;

    while (p != nullptr) {
        float score = hitungPopularityScore(p->info);
        if (score >= minScore && score <= maxScore) {
            cout << left << setw(5) << index
                << setw(20) << p->info.Title
                << setw(15) << fixed << setprecision(1) << score << endl;
            found = true;
        }
        p = p->next;
        index++;
    }
    if (!found) {
        cout << "Tidak ada lagu yang ditemukan dalam rentang Popularity Score tersebut." << endl;
    }
    cout << string(40, '-') << endl;
}


int main() {
    List L;
    address P_del, Q;


    // 1. 
    createList(L);
    cout << "1. List kosong dibuat." << endl;

    // 2. 
    cout << "\n2. masukan 3 lagu:" << endl;
    Song s1 = {"Senja di Kota", "Nona Band", 210, 150, 4.2};
    insertLast(L, allocate(s1));
    Song s2 = {"Langkahmu", "Delta", 185, 320, 4.8};
    insertLast(L, allocate(s2));
    Song s3 = {"Hujan Minggu", "Arka", 240, 90, 3.9};
    insertLast(L, allocate(s3));
    cout << "   - 3 data berhasil ditambahkan di akhir list." << endl;

    // 3. 
    cout << "\n3. list awal:" << endl;
    viewList(L);

    // 4. 
    deleteLast(L, P_del);
    if (P_del != nullptr) {
        cout << "\n4. deleteLast 1x: Lagu '" << P_del->info.Title << "' dihapus." << endl;
    } else {
        cout << "\n4. Gagal deleteLast: List kosong." << endl;
    }

    // 5. 
    Song sUpdate = {"Pelita", "Luna", 200, 260, 4.5};
    cout << "\n5. Update node dengan data baru:" << endl;
    updateAtPosition(L, 2, sUpdate);

    // 6.
    cout << "\n6. list setelah update:" << endl;
    viewList(L);

    // 7. 
    Q = findNodeByPosition(L, 2); 

    // 7.a. 
    Song sInsertBefore = {"Senandung", "Mira", 175, 120, 4.0};
    cout << "\n7.a. insertBefore pada node posisi 2 ('" << (Q ? Q->info.Title : "N/A") << "'):" << endl;
    insertBefore(L, allocate(sInsertBefore), Q);
    cout << "   - Lagu '" << sInsertBefore.Title << "' berhasil ditambahkan." << endl;
    cout << "   - list setelah insertBefore:" << endl;
    viewList(L); 

    // 7.b. 
    Q = findNodeByPosition(L, 2); 
    Song sUpdateBefore = {"Bebas Baru", "Artis B", 300, 500, 5.0};
    cout << "\n7.b. updateBefore pada node posisi 2 ('" << (Q ? Q->info.Title : "N/A") << "'):" << endl;
    updateBefore(L, Q, sUpdateBefore); 
    cout << "   - list setelah updateBefore:" << endl;
    viewList(L); 

    // 7.c. 
    Q = findNodeByPosition(L, 3); 
    cout << "\n7.c. deleteBefore pada node posisi 3 ('" << (Q ? Q->info.Title : "N/A") << "'):" << endl;
    deleteBefore(L, P_del, Q); 
    if (P_del != nullptr) {
        cout << "   - Lagu '" << P_del->info.Title << "' dihapus." << endl;
    } else {
        cout << "   - Gagal deleteBefore." << endl;
    }
    cout << "   - list setelah deleteBefore:" << endl;
    viewList(L); 

    // 8. 
    cout << "\n8. Searching berdasarkan PopularityScore (min=150.0, max=300.0):" << endl;
    searchByPopularityRange(L, 150.0, 300.0);

    return 0;
}