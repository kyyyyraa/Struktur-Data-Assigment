# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (1)</h1>
<p align="center">Muhammad Zacky Permana - 103112430228</p>

## Dasar Teori
Materi ini memperkenalkan Code::Blocks, sebuah lingkungan pengembangan (IDE) gratis yang digunakan untuk menulis program dalam bahasa C++. Anda akan belajar cara menginstal , membuat proyek baru , menulis kode, dan menjalankan program. Selain itu, modul ini juga menjelaskan cara mengatasi masalah umum, seperti ketika program tidak bisa berjalan, dengan fitur seperti Clean project , serta cara memahami pesan kesalahan (error messages) yang muncul saat ada kesalahan penulisan kode.


Pada bagian dasar pemrograman, dijelaskan konsep-konsep inti C++. Ini mencakup struktur dasar program , penggunaan tipe data (seperti int untuk angka bulat dan float untuk desimal) , dan variabel untuk menyimpan nilai. Anda juga akan mempelajari operator untuk operasi matematika dan logika , serta struktur kontrol alur program seperti pernyataan kondisional (if-else, switch) untuk membuat keputusan dan perulangan (for, while, do-while) untuk menjalankan tugas berulang kali.


### 1. ...

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    cout << "\nPenjumlahan : " << a + b << endl;
    cout << "Pengurangan : " << a - b << endl;
    cout << "Perkalian   : " << a * b << endl;
    cout << "Pembagian   : " << a / b << endl;

    return 0;
}

```
Penjelasan singkat 1
Program C++ ini adalah kalkulator sederhana yang melakukan empat operasi aritmatika dasar. Program akan meminta pengguna untuk memasukkan dua buah bilangan (bisa berupa bilangan desimal). Setelah kedua bilangan dimasukkan, program akan menghitung dan menampilkan hasil dari penjumlahan, pengurangan, perkalian, dan pembagian kedua bilangan tersebut.


### 2. ...

```C++

#include <iostream>
using namespace std;

int main() {
    int angka;

    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100 ) {
        cout << "Angka di luar jangkauan" << endl;

        return 0;
    }

    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam",  "tujuh", "delapan", "sembilan"};
    string belasan[] = {"Sepuluh", "Sebelas", "Dua Belas", "Tiga Belas", "Empat Belas", "Lima Belas", "Enam Belas", "Tujuh Belas", "Delapan Belas", "Sembilan Belas"};
    string puluhan[] = {"", "", "Dua Puluh", "Tiga Puluh", "Empat Puluh", "Lima Puluh", "Enam Puluh", "Tujuh Puluh", "Delapan Puluh", "Sembilan Puluh"};

    if (angka == 0) {
        cout << "Nol" << endl;
    } else if (angka == 100) {
        cout << "Seratus" << endl;
    } else if (angka >= 10 && angka < 20) {
        cout << belasan[angka - 10] << endl;
    } else {
        int puluh = angka / 10;
        int satu = angka % 10;

        if (puluh > 0) cout << puluhan[puluh];
        if (puluh > 0 && satu > 0) cout << " ";
        if (satu >  0) cout << satuan[satu];
        cout << endl;
    }
    return 0;
}

```
penjelasan singkat 2
Program C++ ini berfungsi sebagai konverter yang mengubah angka bulat menjadi representasi teks dalam Bahasa Indonesia, khusus untuk rentang 0 hingga 100. Program akan meminta pengguna untuk memasukkan sebuah angka, kemudian memvalidasi apakah input tersebut berada dalam jangkauan yang ditentukan. Jika angka valid, program akan memprosesnya: kasus-kasus khusus seperti 0, 100, dan angka belasan (10-19) akan langsung dikonversi. Untuk angka lainnya, program akan memisahkannya menjadi komponen puluhan dan satuan, lalu menggabungkan tulisan dari kedua komponen tersebut untuk menampilkan hasil akhir dalam bentuk kata-kata.

### 3. ...

```C++

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    cout << "Output:" << endl;

    for (int i = n; i >= 1; i--) {
        for (int s = n; s > i; s--) {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j;
            if (j < i) cout << " ";
        }

        cout << endl;
    }

    for (int s = 0; s < n; s++) {
        cout << "  ";
    }
    cout << "*" << endl;

    return 0;
}



```
penjelasan singkat  3
Program C++ ini bertujuan untuk membuat sebuah pola angka simetris (mirrored pattern) yang menurun berdasarkan input dari pengguna. Setelah pengguna memasukkan sebuah bilangan bulat, program akan menghasilkan serangkaian baris. Setiap baris menampilkan dua urutan angka yang dipisahkan oleh simbol asterisk (*): urutan pertama menurun dari angka baris saat itu ke 1, dan urutan kedua menaik dari 1 kembali ke angka baris tersebut. Pola ini terus menyusut di setiap baris berikutnya hingga mencapai 1, dan diakhiri dengan satu simbol * di bagian paling bawah.

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/kyyyyraa/Struktur-Data-Assigment/blob/main/Modul-2/Output-1-1.jpg)

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/kyyyyraa/Struktur-Data-Assigment/blob/main/Modul-2/Output-1-2.jpg)

##### Output 3
![Screenshot Output Unguided 1_1](https://github.com/kyyyyraa/Struktur-Data-Assigment/blob/main/Modul-2/Output-1-3.jpg)


## Kesimpulan
...

## Referensi
[1]
<br>Asyiknya Belajar Struktur Data di Planet C++. (n.d.). (n.p.):
Elex Media Komputindo.
<br>