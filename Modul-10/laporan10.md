# <h1 align="center">Laporan Praktikum Modul 10 - tree(bagian pertama)</h1>
<p align="center">Muhammad Zacky Permana - 103112430228</p>

## Dasar Teori
Setelah sebelumnya mendalami struktur data linear seperti list, stack, dan queue, kini kita beralih ke struktur data non-linear yang disebut Tree. Secara teknis, Tree didefinisikan sebagai tipe graf terhubung yang tidak memiliki arah serta tidak mengandung sirkuit (lintasan tertutup).

Suatu struktur dapat dikategorikan sebagai Tree (T) jika memenuhi karakteristik berikut:
1. Empty Tree: T dikatakan kosong jika tidak memiliki satu pun node.
2. Root (Akar): Hanya terdapat tepat satu node utama yang tidak memiliki pendahulu (predecessor).
3. Hierarki Tunggal: Setiap node selain root diwajibkan hanya memiliki tepat satu node pendahulu.

#### A. Materi modul 10
Pada pertemuan ini, kita akan membahas fungsi fungsi pada struktur tree pada BST (Binary Search Tree).

#### 1. Insert
Jika node yang akan di-insert lebih kecil, maka di-insert pada Left Subtree
Jika lebih besar, maka di-insert pada Right Subtree.

#### 2. Search
Proses pencarian elemen pada binary tree dapat menggunakan algoritma rekursif binary search.
Berikut adalah algoritma binary search :
1. Pencarian pada binary search tree dilakukan dengan menaruh pointer dan membandingkan nilai
yang dicari dengan node awal ( root )
2. Jika nilai yang dicari tidak sama dengan node, maka pointer akan diganti ke child dari node yang
ditunjuk:
a. Pointer akan pindah ke child kiri bila, nilai dicari lebih kecil dari nilai node yang ditunjuk saat
itu
b. Pointer akan pindah ke child kanan bila, nilai dicari lebih besar dari nilai node yang ditunjuk
saat itu
3. Nilai node saat itu akan dibandingkan lagi dengan nilai yang dicari dan apabila belum ditemukan,
maka perulangan akan kembali ke tahap 2
4. Pencarian akan berhenti saat nilai yang dicari ketemu, atau pointer menunjukan nilai NULL

#### 3. Delete
LEAF, tidak perlu dilakukan modifikasi.
2. Node dengan 1 Child, maka child langsung menggantikan posisi Parent.
3. Node dengan 2 Child:
- Left Subtree, yang diambil adalah node yang paling kiri (nilai terbesar).
- Right Subtree, yang diambil adalah node yang paling kanan (nilai terkecil).

#### 4. Most Left
Most-left node adalah node yang berada paling kiri dalam tree. Dalam konteks binary search tree
(BST), most-left node adalah node dengan nilai terkecil, yang dapat ditemukan dengan mengikuti
anak kiri (left child) dari root hingga mencapai node yang tidak memiliki anak kiri lagi.

#### 5. Most right
Most-right node adalah node yang berada paling kanan dalam tree. Dalam konteks binary search
tree (BST), most-right node adalah node dengan nilai terbesar, yang dapat ditemukan dengan
mengikuti anak kanan (right child) dari root hingga mencapai node yang tidak memiliki anak kanan
lagi.

#### 6. Pre-Order
Proses Traverse yang melakukan tahapan cetak node yang dikunjungi, kunjungi left node , kunjungi right node.

#### 7. In-Order
Proses Traverse yang melakukan tahapan kunjungi left node, cetak node yang dikunjungi, kunjungi right node.

#### 8. Post-Order
Proses Traverse yang melakukan tahapan kunjungi left node, kunjungi right node, cetak node yang dikunjungi


## Guided 1

### . [Binary Searh Tree] 

```C++
//bst.h
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef struct BST *node; //alias pointer = node

struct BST{ //nama struct BST
    int angka;
    node left;
    node right;
};

typedef node BinTree; //alias tree = BinTree (merujuk ke node root dari BST)

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif

//bst.cpp
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){ //tengah - kiri - kanan atau root - child kiri - child kanan
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){ //kiri - tengah - kanan atau child kiri - root - child kanan
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){ //kiri - kanan - tengah atau child kiri - child kanan - root
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}
//main.cpp
#include <iostream>
#include "bst.h"
#include "bst.cpp"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
   
```
Melalui antarmuka menu pada main.cpp, program ini memfasilitasi pembangunan serta pengelolaan struktur data Binary Search Tree (BST) secara interaktif. Fitur utama mencakup penambahan node baru ke dalam hierarki pohon serta penghapusan node spesifik yang telah terdaftar. Program ini juga menyediakan fungsi pencarian untuk memvalidasi keberadaan data tertentu dalam pohon. Untuk keperluan visualisasi dan analisis, tersedia fitur penelusuran (traversal) secara Preorder, Inorder, dan Postorder, penghitungan total node yang tersimpan, hingga identifikasi elemen paling kanan (mostright) dan paling kiri (mostleft). Terakhir, sistem memungkinkan pengguna untuk menghapus seluruh struktur pohon secara total guna mengosongkan memori.

## Unguided

## soal 1. 


```C++
//bstree.h
#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef int infotype;
typedef struct Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};

// alokasi node
address alokasi(infotype x);

// insert node ke BST
void insertNode(address &root, infotype x);

// mencari node
address findNode(infotype x, address root);

// traversal inorder
void InOrder(address root);

#endif


//bstree.cpp
#include <iostream>
#include "bstree.h"
using namespace std;

// fungsi alokasi
address alokasi(infotype x) {
    address P = new Node;
    if (P != Nil) {
        P->info = x;
        P->left = Nil;
        P->right = Nil;
    }
    return P;
}

// fungsi insert BST
void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
    // jika sama → tidak dimasukkan
}

// fungsi cari node
address findNode(infotype x, address root) {
    if (root == Nil || root->info == x)
        return root;
    if (x < root->info)
        return findNode(x, root->left);
    return findNode(x, root->right);
}

// traversal InOrder
void InOrder(address root) {
    if (root != Nil) {
        InOrder(root->left);
        cout << root->info << " ";
        InOrder(root->right);
    }
}

//main.cpp
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello World" << endl;

    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);

    InOrder(root);
    return 0;
}

```

### Output soal 1 :
![Screenshot Output 2](https://github.com/kyyyyraa/Struktur-Data-Assigment/blob/main/Modul-10/Output-10-1.jpeg)

Program ini memanfaatkan metode alokasi memori dan operasi penyisipan (insert) untuk membangun struktur pohon biner pencarian atau BST. Setelah data tersusun dalam hierarki pohon, program akan memproses dan menampilkan hasilnya menggunakan metode penelusuran InOrder. Secara teknis, mekanisme ini dilakukan dengan cara mengunjungi subtree sebelah kiri terlebih dahulu, kemudian mencetak nilai pada node yang sedang diakses, dan diakhiri dengan mengunjungi subtree sebelah kanan.

### soal 2. 


```C++
//bstree.h
#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef int infotype;
typedef struct Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
void InOrder(address root);

int hitungNode(address root);
int hitungTotal(address root);
int hitungKedalaman(address root, int start);

#endif

//bstree.cpp
#include <iostream>
#include "bstree.h"
using namespace std;

address alokasi(infotype x) {
    address P = new Node;
    if (P != Nil) {
        P->info = x;
        P->left = Nil;
        P->right = Nil;
    }
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == Nil)
        root = alokasi(x);
    else if (x < root->info)
        insertNode(root->left, x);
    else if (x > root->info)
        insertNode(root->right, x);
}

void InOrder(address root) {
    if (root != Nil) {
        InOrder(root->left);
        cout << root->info << " ";
        InOrder(root->right);
    }
}

int hitungNode(address root) {
    if (root == Nil)
        return 0;
    return 1 + hitungNode(root->left) + hitungNode(root->right);
}

int hitungTotal(address root) {
    if (root == Nil)
        return 0;
    return root->info + hitungTotal(root->left) + hitungTotal(root->right);
}

int hitungKedalaman(address root, int start) {
    if (root == Nil)
        return start;
    int kiri = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);
    return (kiri > kanan) ? kiri : kanan;
}

//main.cpp
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    address root = Nil;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,7);

    InOrder(root);
    cout << "\n";

    cout << "kedalaman : " << hitungKedalaman(root,0) << endl;
    cout << "jumlah Node : " << hitungNode(root) << endl;
    cout << "total : " << hitungTotal(root) << endl;

    return 0;
}

```

### Output:
![Screenshot Output 2](https://github.com/kyyyyraa/Struktur-Data-Assigment/blob/main/Modul-10/Output-10-2.jpeg)

Program ini dirancang untuk membangun struktur Binary Search Tree (BST) dengan memfungsikan metode alokasi memori untuk setiap node baru dan prosedur insertNode untuk menempatkan data tanaman ke dalam hierarki pohon yang tepat. Guna melakukan analisis terhadap data yang tersimpan, program dilengkapi dengan fungsi hitungJumlahNode untuk mengetahui total elemen yang ada, serta fungsi hitungTotalInfo untuk mengakumulasi nilai atau informasi tertentu dari seluruh node. Selain itu, program ini mampu menghitung dimensi pohon melalui pengukuran kedalaman (depth). Secara teknis, terdapat perbedaan mendasar dalam metrik ini: kedalaman mengukur jarak vertikal suatu node dari root (akar), sementara ketinggian (height) mengukur jarak antara suatu node dengan leaf (daun/node terminal) yang berada di posisi paling bawah di bawahnya.

### soal 3.

```C++
//bstree.h
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

address alokasi(infotype X);
void insertNode(address &root, infotype X);
address findNode(infotype X, address &root);
void printInorder(address root);
void preOrder(address root);
void postOrder(address root);

#endif

//bstree.cpp
#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype X){
    address nodeBaru = new Node;
    nodeBaru->info = X;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(address &root, infotype X){
    if(root == Nil){
        root = alokasi(X);
    } else if (X < root->info){
        insertNode(root->left, X);
    } else if (X > root->info){
        insertNode(root->right, X);
    }
}

address findNode(infotype X, address &root){
    if(root == Nil){
        cout << "Tree kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(X < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if (X > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if (X == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu = true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data: " << nodeBantu->info << endl;
        }
    }
    return Nil;
}

void printInorder(address root){
    if(root != Nil){
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

void preOrder(address root){
    if(root == Nil){
        return;
    }
    cout << root->info << " - ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(address root){
    if(root == Nil){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->info << " - ";
}

//main.cpp
#include <iostream>
#include "bstree.h"
using namespace std;
int main()
{
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root, 6);
    insertNode(root, 7);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 1);
    cout << "Tampilkan preOrder : " ;
             preOrder(root); 
             cout << endl;
    cout << "Tampilkan postOrder : "; 
             postOrder(root);
             cout << endl;
    return 0;
}

```

### Output:
![Screenshot Output 2](https://github.com/kyyyyraa/Struktur-Data-Assigment/blob/main/Modul-10/Output-10-3.jpeg)


Program ini dirancang untuk mengonstruksi struktur data Binary Search Tree (BST) dengan kemampuan menyajikan data melalui dua metode penelusuran (traversal) yang berbeda. Pertama, metode PreOrder, di mana program akan mengakses dan mencetak nilai node induk (root) terlebih dahulu sebelum beralih menelusuri cabang (subtree) kiri dan diakhiri dengan cabang kanan. Kedua, metode PostOrder, di mana urutan pengerjaannya dimulai dengan menyisir cabang kiri secara mendalam, diikuti oleh cabang kanan, dan terakhir baru memproses atau menampilkan nilai dari node induknya.

### Kesimpulan
Materi ini mengupas tuntas berbagai fungsi fundamental dalam pengelolaan struktur data Tree, yang diawali dengan mekanisme penambahan elemen melalui prosedur alokasi memori dan penyisipan data menggunakan insertNode. Selain aspek manipulasi data, terdapat fungsi analitis seperti hitungJumlahNode untuk mengkuantifikasi seluruh elemen dalam pohon, serta hitungTotalInfo untuk mengakumulasi nilai data yang tersimpan di setiap node. Pembahasan juga mencakup metrik dimensi pohon melalui fungsi hitungKedalaman. Penting untuk dipahami bahwa meskipun parameter kedalaman (depth) dan ketinggian (height) tampak mirip secara konseptual, keduanya memiliki logika implementasi yang berlainan, sehingga keduanya didefinisikan sebagai fungsi yang berbeda dan tidak dapat saling menggantikan dalam analisis struktur pohon.


