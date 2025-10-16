# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Muhammad Zacky Permana - 103112430228</p>

## Dasar Teori
Abstract Data Type (ADT) adalah sebuah model konseptual yang mendefinisikan sebuah tipe data beserta sekumpulan operasi dasar (primitif) yang dapat dilakukan terhadap tipe data tersebut. Anggap saja ADT sebagai sebuah "cetak biru" yang tidak hanya menjelaskan bentuk data (misalnya, sebuah struct di C++), tetapi juga mendefinisikan semua fungsi yang bisa berinteraksi dengannya. Fungsi-fungsi primitif ini dikelompokkan menjadi beberapa jenis, seperti Konstruktor untuk membuat objek baru, Selector untuk mengakses atau mengambil data di dalamnya (biasanya diawali Get), dan operator lain untuk validasi, input/output, hingga perbandingan.


Dalam implementasinya, konsep ADT diterapkan dengan memisahkan kode menjadi dua file utama untuk mencapai modularitas: sebuah file header (.h) dan sebuah file body (.cpp). File header (.h) berfungsi sebagai spesifikasi atau "wajah publik" dari ADT, berisi deklarasi tipe data (misalnya struct mahasiswa) dan prototipe dari semua fungsi primitifnya. Sementara itu, file body (.cpp) berisi implementasi atau kode program detail dari setiap fungsi yang telah dideklarasikan di header. Program utama (driver) kemudian dapat menggunakan ADT ini hanya dengan mengimpor file header (.h), memungkinkan pemisahan yang jelas antara antarmuka (cara penggunaan) dan implementasi (cara kerja).


### 1. ...

```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> n;

    if (n > 10) n = 10;

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cout << "Nama   : ";
        cin.ignore();
        getline(cin, mhs[i].nama);
        cout << "NIM    : ";
        getline(cin, mhs[i].nim);
        cout << "UTS    : ";
        cin >> mhs[i].uts;
        cout << "UAS    : ";
        cin >> mhs[i].uas;
        cout << "Tugas  : ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

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

```
Penjelasan singkat 1
Program pertama dibuat untuk menyimpan data maksimal 10 mahasiswa menggunakan array struktur. Struktur yang digunakan berisi beberapa field yaitu nama, nim, uts, uas, tugas, dan nilaiAkhir. Nilai akhir mahasiswa dihitung secara otomatis melalui fungsi dengan rumus 03 × uts + 0.4 × uas + 0.3 × tugas. Program meminta input dari pengguna untuk setiap mahasiswa, kemudian menampilkan data dalam bentuk tabel berisi nama, NIM, dan nilai akhir. Tujuan utama program ini adalah untuk melatih penggunaan array of struct, penerapan fungsi, dan perhitungan nilai berbasis struktur data di C++.


### 2. ...

```h

#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaPel, string kodePel);
void tampil_pelajaran(pelajaran pel);

#endif

```

```C++

#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namaPel, string kodePel) {
    pelajaran p;
    p.namaMapel = namaPel;
    p.kodeMapel = kodePel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}

```

```C++

#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namaPel = "Struktur Data";
    string kodePel = "STD";

    pelajaran pel = create_pelajaran(namaPel, kodePel);
    tampil_pelajaran(pel);

    return 0;
}


```
penjelasan singkat 2
Program kedua menerapkan konsep Abstract Data Type (ADT) dengan pembagian kode ke dalam tiga file, yaitu pelajaran.h, pelajaran.cpp, dan main.cpp. File pelajaran.h berisi deklarasi struktur pelajaran dengan atribut namaMapel dan kodeMapel, serta prototipe fungsi create_pelajaran() dan tampil_pelajaran(). File pelajaran.cpp berisi implementasi kedua fungsi tersebut, di mana create_pelajaran() digunakan untuk membuat objek pelajaran berdasarkan parameter nama dan kode, sedangkan tampil_pelajaran() digunakan untuk menampilkan hasilnya. Di file main.cpp, program utama membuat satu objek pelajaran dengan nama “Struktur Data” dan kode “STD”, kemudian menampilkan hasilnya di layar. Program ini menunjukkan penerapan modular programming dan pemisahan logika antar file dalam konsep ADT.

### 3. ...

```C++

#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarElemen(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    int *ptr1, *ptr2;
    ptr1 = &A[1][1];  
    ptr2 = &B[2][2];  
    cout << "Array A sebelum ditukar:\n";
    tampilArray(A);
    cout << "\nArray B sebelum ditukar:\n";
    tampilArray(B);

    tukarElemen(A, B, 0, 0);

    cout << "\nSetelah menukar elemen A[0][0] dengan B[0][0]:\n";
    cout << "Array A:\n";
    tampilArray(A);
    cout << "\nArray B:\n";
    tampilArray(B);

    tukarPointer(ptr1, ptr2);

    cout << "\nSetelah menukar nilai yang ditunjuk pointer:\n";
    cout << "Array A:\n";
    tampilArray(A);
    cout << "\nArray B:\n";
    tampilArray(B);

    return 0;
}




```
penjelasan singkat  3
Program ketiga dibuat untuk mengelola dua buah array 2 dimensi berukuran 3x3 dan dua buah pointer integer. Program ini memiliki beberapa fungsi penting, yaitu tampilArray() untuk menampilkan isi array 2D secara rapi, tukarElemen() untuk menukar nilai pada posisi tertentu antara dua array 2D, dan tukarPointer() untuk menukar isi dua variabel yang ditunjuk oleh pointer. Pada fungsi utama (main()), dua array diinisialisasi dan ditampilkan terlebih dahulu, kemudian dilakukan proses penukaran nilai baik melalui fungsi tukarElemen() maupun dengan tukarPointer(). Hasil akhirnya menampilkan perubahan isi array setelah penukaran. Program ini memperlihatkan bagaimana pointer dan array 2 dimensi dapat digunakan bersama untuk memanipulasi data secara langsung di memori.

##### Output 1
![Screenshot Output 1](https://github.com/kyyyyraa/Struktur-Data-Assigment/blob/main/Modul-2/Output-3-1.jpg)

##### Output 2
![Screenshot Output 2](https://github.com/kyyyyraa/Struktur-Data-Assigment/blob/main/Modul-2/Output-3-2.jpg)

##### Output 3
![Screenshot Output 3](https://github.com/kyyyyraa/Struktur-Data-Assigment/blob/main/Modul-2/Output-3-3.jpg)


## Kesimpulan
...

## Referensi
[1]
<br>Chaniago, M. B., & Sastradipraja, C. K. (2022). Buku Ajar
Algoritma dan Struktur Data. Kaizen Media Publishing.

<br>
