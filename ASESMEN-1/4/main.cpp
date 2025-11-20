#include "QueuePengiriman.h"

void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1; 
    Q.Tail = -1;
}

bool isEmpty(QueueEkspedisi Q) {
    return Q.Head == -1;
}

bool isFull(QueueEkspedisi Q) {
    return Q.Tail == MAX - 1; 
}

void enQueue(QueueEkspedisi &Q, Paket data) {
    if (isFull(Q)) {
        cout << "Gagal enQueue: Queue sudah penuh (MAX=" << MAX << ")." << endl;
    } else {
        if (isEmpty(Q)) {
            Q.Head = 0; 
        }
        Q.Tail++;
        Q.dataPaket[Q.Tail] = data;
        cout << "Paket '" << data.KodeResi << "' berhasil di-enQueue." << endl;
    }
}

void deQueue(QueueEkspedisi &Q, Paket &data) {
    if (isEmpty(Q)) {
        data = {"", "", 0, ""};
        cout << "Gagal deQueue: Queue kosong." << endl;
    } else {
        data = Q.dataPaket[Q.Head];

        for (int i = Q.Head; i < Q.Tail; i++) {
            Q.dataPaket[i] = Q.dataPaket[i+1];
        }
        Q.Tail--;

        if (Q.Tail == -1) { 
            Q.Head = -1;
        }

        cout << "Paket '" << data.KodeResi << "' berhasil di-deQueue." << endl;
    }
}

void viewQueue(QueueEkspedisi Q) {
    cout << "\n--- Tampilan Queue Paket ---" << endl;
    cout << left << setw(5) << "Idx" << setw(15) << "Kode Resi" << setw(15) << "Pengirim"
        << setw(10) << "Berat(kg)" << setw(15) << "Tujuan" << endl;
    cout << string(60, '-') << endl;

    if (isEmpty(Q)) {
        cout << "Queue kosong." << endl;
    } else {
        for (int i = Q.Head; i <= Q.Tail; i++) {
            cout << left << setw(5) << i
                << setw(15) << Q.dataPaket[i].KodeResi
                << setw(15) << Q.dataPaket[i].NamaPengirim
                << setw(10) << Q.dataPaket[i].BeratBarang
                << setw(15) << Q.dataPaket[i].Tujuan << endl;
        }
    }
    cout << string(60, '-') << endl;
    cout << "Head: " << Q.Head << ", Tail: " << Q.Tail << endl;
}

int TotalBiayaPengiriman(QueueEkspedisi Q) {
    int totalBerat = 0;
    int biayaPerKg = 8250;

    for (int i = Q.Head; i <= Q.Tail; i++) {
        totalBerat += Q.dataPaket[i].BeratBarang;
    }

    return totalBerat * biayaPerKg;
}


int main() {
    QueueEkspedisi Q;
    Paket p_deq;
    int choice = 0;


    // 1. 
    createQueue(Q);
    cout << "1. Queue kosong berhasil dibuat." << endl;

    // Menu
    while (choice != 5) {
        cout << "\n=== Komanilya Ekspres ===" << endl;
        cout << "1. Input Data Paket " << endl;
        cout << "2. Hapus Data Paket " << endl;
        cout << "3. Tampilkan Queue" << endl;
        cout << "4. Hitung Total Biaya Pengiriman" << endl; 
        cout << "5. Keluar" << endl;
        cout << "Pilihan anda (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: { 
                cout << "\n--- Input Data Paket ---" << endl;
                Paket p1 = {"123456", "Hutao", 14, "Fontaine"}; enQueue(Q, p1);
                Paket p2 = {"234567", "Ayaka", 10, "Sumeru"}; enQueue(Q, p2);
                Paket p3 = {"345678", "Bennet", 7, "Natlan"}; enQueue(Q, p3);
                Paket p4 = {"456789", "Furina", 16, "Liyue"}; enQueue(Q, p4);
                Paket p5 = {"567890", "Nefer", 9, "Inazuma"}; enQueue(Q, p5); // MAX = 5
                break;
            }
            case 2: { 
                cout << "\n--- Hapus Data Paket ---" << endl;
                deQueue(Q, p_deq);
                break;
            }
            case 3: { 
                viewQueue(Q);
                break;
            }
            case 4: { 
                int totalBiaya = TotalBiayaPengiriman(Q);
                cout << "\n--- Total Biaya Pengiriman ---" << endl;
                cout << "Total Biaya Pengiriman semua paket dalam Queue: Rp " << totalBiaya << endl;
                break;
            }
            case 5: {
                cout << "Terima kasih!" << endl;
                break;
            }
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}