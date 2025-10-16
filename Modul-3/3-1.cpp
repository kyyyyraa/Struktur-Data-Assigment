#include <iostream>
using namespace std;

// Struktur untuk data mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

// Fungsi untuk menghitung nilai akhir
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mhs[10];   // array maksimal 10 mahasiswa
    int n;

    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> n;

    if (n > 10) n = 10;  // batas maksimal

    // Input data mahasiswa
    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cout << "Nama   : ";
        cin.ignore(); // membersihkan buffer
        getline(cin, mhs[i].nama);
        cout << "NIM    : ";
        getline(cin, mhs[i].nim);
        cout << "UTS    : ";
        cin >> mhs[i].uts;
        cout << "UAS    : ";
        cin >> mhs[i].uas;
        cout << "Tugas  : ";
        cin >> mhs[i].tugas;

        // Hitung nilai akhir menggunakan fungsi
        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    // Tampilkan data mahasiswa
    cout << "\n=========================================\n";
    cout << "Daftar Nilai Mahasiswa\n";
    cout << "=========================================\n";
    cout << "Nama\t\tNIM\t\tNilai Akhir\n";
    cout << "-----------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << mhs[i].nama << "\t\t"
             << mhs[i].nim << "\t\t"
             << mhs[i].nilaiAkhir << endl;
    }

    cout << "=========================================\n";

    return 0;
}
