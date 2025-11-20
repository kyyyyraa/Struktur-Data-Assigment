#include "SLLInventory.h"


float hitungHargaAkhir(Product P) {
    return P.HargaSatuan * (1.0 - P.DiskonPersen / 100.0);
}

void MaxHargaAkhir(List L) {
    if (L.head == nullptr) {
        cout << "\nBagian B: List kosong, tidak ada Harga Akhir maksimum." << endl;
        return;
    }
    
    address p = L.head;
    float maxHarga = hitungHargaAkhir(L.head->info);

    while (p != nullptr) {
        float currentHarga = hitungHargaAkhir(p->info);
        if (currentHarga > maxHarga) {
            maxHarga = currentHarga;
        }
        p = p->next;
    }

    cout << "\n--- Bagian B: Produk dengan Harga Akhir Terbesar (Rp " << fixed << setprecision(0) << maxHarga << ") ---" << endl;
    
    p = L.head;
    int currentPosisi = 1;
    bool found = false;
    
    while (p != nullptr) {
        float currentHarga = hitungHargaAkhir(p->info);
        if (currentHarga == maxHarga) {
            if (found) cout << "----------------------------------" << endl;
            cout << "Posisi : " << currentPosisi << endl;
            cout << "Nama   : " << p->info.Nama << endl;
            cout << "SKU    : " << p->info.SKU << endl;
            found = true;
        }
        p = p->next;
        currentPosisi++;
    }
    cout << string(40, '-') << endl;
}

void viewList(List L) {
    address p = L.head;
    int index = 1;
    cout << "--- Daftar Produk Inventaris ---" << endl;
    cout << left << setw(5) << "Idx" << setw(20) << "Nama" << setw(10) << "SKU"
        << setw(10) << "Jumlah" << setw(15) << "Harga Satuan" << setw(10) << "Diskon"
        << setw(15) << "Harga Akhir" << endl;
    cout << string(85, '-') << endl;

    while (p != nullptr) {
        float hargaAkhir = hitungHargaAkhir(p->info);
        cout << left << setw(5) << index
            << setw(20) << p->info.Nama
            << setw(10) << p->info.SKU
            << setw(10) << p->info.Jumlah
            << setw(15) << fixed << setprecision(0) << p->info.HargaSatuan
            << setw(10) << fixed << setprecision(1) << p->info.DiskonPersen
            
            << setw(15) << fixed << setprecision(0) << hargaAkhir 
            
            << endl;
        p = p->next;
        index++;
    }
    if (L.head == nullptr) {
        cout << "List kosong." << endl;
    }
    cout << string(85, '-') << endl;
}

address allocate(Product P) {
    address newNode = new Node;
    newNode->info = P;
    newNode->next = nullptr;
    return newNode;
}

void createList(List &L) {
    L.head = nullptr;
}

void insertLast(List &L, address P) {
    if (L.head == nullptr) {
        L.head = P;
    } else {
        address current = L.head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.head != nullptr) {
        P = L.head;
        L.head = L.head->next;
        P->next = nullptr; 
    } else {
        P = nullptr;
    }
}

void updateAtPosition(List &L, int posisi, Product info) {
    if (posisi <= 0) return;

    address current = L.head;
    int count = 1;
    while (current != nullptr && count < posisi) {
        current = current->next;
        count++;
    }

    if (current != nullptr && count == posisi) {
        current->info = info; 
        cout << "Node pada posisi ke-" << posisi << " berhasil diupdate." << endl;
    } else {
        cout << "Posisi tidak valid atau list kosong." << endl;
    }
}


void searchByFinalPrice(List L, float minPrice, float maxPrice) {
    address p = L.head;
    int index = 1;
    bool found = false;

    cout << "\n--- Hasil Pencarian Harga Akhir [" << fixed << setprecision(0) << minPrice << " - " << maxPrice << "] ---" << endl;
    cout << left << setw(5) << "Idx" << setw(20) << "Nama" << setw(15) << "Harga Akhir" << endl;
    cout << string(40, '-') << endl;

    while (p != nullptr) {
        float hargaAkhir = hitungHargaAkhir(p->info);
        if (hargaAkhir >= minPrice && hargaAkhir <= maxPrice) {
            cout << left << setw(5) << index
                << setw(20) << p->info.Nama
                << setw(15) << fixed << setprecision(0) << hargaAkhir << endl;
            found = true;
        }
        p = p->next;
        index++;
    }
    if (!found) {
        cout << "Tidak ada produk yang ditemukan dalam rentang harga tersebut." << endl;
    }
    cout << string(40, '-') << endl;
}


int main() {
    List L;
    address P_del;

    //1
    createList(L);
    cout << "1. List kosong berhasil dibuat." << endl;

    //2
    cout << "\n2. Masukan 3 data:" << endl;
    Product data1 = {"Pulpen", "A001", 20, 2500.0, 0.0};
    insertLast(L, allocate(data1));
    Product data2 = {"Buku Tulis", "A002", 15, 5000.0, 10.0};
    insertLast(L, allocate(data2));
    Product data3 = {"Penghapus", "A003", 30, 1500.0, 0.0};
    insertLast(L, allocate(data3));
    cout << "   - 3 data berhasil ditambahkan di akhir list." << endl;

    //3
    cout << "\n3. list awal:" << endl;
    viewList(L);

    //4
    deleteFirst(L, P_del);
    if (P_del != nullptr) {
        cout << "\n4. deleteFirst 1x: Produk '" << P_del->info.Nama << "' dihapus." << endl;
    } else {
        cout << "\n4. Gagal deleteFirst: List kosong." << endl;
    }

    //5
    cout << "\n5. list setelah deleteFirst:" << endl;
    viewList(L);

    //6
    Product dataUpdate = {"Stabilo", "A010", 10, 9000.0, 5.0};
    cout << "\n6. Update node dengan data baru:" << endl;
    updateAtPosition(L, 2, dataUpdate);

    //7
    cout << "\n7. list setelah update:" << endl;
    viewList(L);

    //8
    searchByFinalPrice(L, 2000.0, 7000.0);

    MaxHargaAkhir(L);

    return 0;
}