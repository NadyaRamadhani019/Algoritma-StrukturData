#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

int random(int bil){
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize(){
    srand(time(NULL));
}

void clrscr(){
    system("cls");
}

void sequent() {
    int data[100];
    int cari = 0;
    int counter = 0;
    bool ditemukan = false;

    randomize();
    cout << "Generating 100 random numbers...\n";
    for(int i = 0; i < 100; i++) {
        data[i] = random(100) + 1;
        cout << data[i] << " ";
    }

    cout << "\nMencari data: ";
    cin >> cari;
    for(int i = 0; i < 100; i++) {
        if (data[i] == cari) {
            if (!ditemukan) {
                cout << "Data " << cari << " ditemukan pada indeks: ";
            }
            cout << i << " ";
            counter++;
            ditemukan = true;
        }
    } cout << "\n";

    if (ditemukan) {
        cout << "Data ditemukan sebanyak " << counter << " kali.\n";
    } else {
        cout << "Data tidak ditemukan!\n";
    }
}

void binary(){
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Masukkan jumlah data? ";
    cin >> n;
    int angka[n];
    for(int i = 0; i < n; i++){
        cout << "Angka ke - [" << i << "] : ";
        cin >> angka[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1; j++){
            if (angka[j] > angka[j + 1]){
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }
    cout << "========================================================================\n";
    cout << "Data yang telah diurutkan adalah:\n";
    for (int i = 0; i < n; i++){
        cout << angka[i] << " ";
    }
    cout << "\n========================================================================\n";
    cout << "Masukkan angka yang dicari: ";
    cin >> key;
    
    kiri = 0;
    kanan = n - 1;
    while (kiri <= kanan){
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah]){
            ketemu = true;
            break;
        } else if (key < angka[tengah]){
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }
    if (ketemu == true){
        cout << "Angka ditemukan pada indeks: " << tengah << "!\n";
    }
    else {
        cout << "Angka tidak ditemukan!";
    }
}

void penjelas(){
    cout << "   Searching adalah proses untuk menemukan suatu data atau informasi dari sekumpulan data/informasi yang\n";
    cout << "ada. Dalam Algoritma dan Struktur data ada banyak cara untuk mencari data, di antaranya adalah pencarian\n";
    cout << "beruntun (Sequential Searching) dan pencarian biner (Binary Searching).\n";
    cout << "1). Pencarian Beruntun (Sequential Searching)\n";
    cout << "       Pencarian Beruntun atau Sequential Searching adalah teknik pencarian data secara urut dari depan\n";
    cout << "    ke belakang atau dari awal sampai akhir. Pencarian akan dihentikan jika data telah ditemukan.\n";
    cout << "       Sequential searching lebih mudah dipahami dan diimplementasikan tanpa memerlukan data yang terurut\n";
    cout << "    serta lebih cocok untuk mencari data dengan jumlah yang sedikit. Namun, cara ini kurang efisien untuk\n";
    cout << "    data berukuran besar karena harus memeriksa satu per satu dan membutuhkan banyak perbandingan sehingga\n";
    cout << "    performanya lebih lambat dibandingkan metode pencarian lain.\n";
    cout << "2). Pencarian Biner (Binary Searching)\n";
    cout << "       Pencarian Biner atau Binary Searching adalah teknik pencarian data dengan membagi dua bagian data\n";
    cout << "    yang sudah terurut, lalu membandingkan nilai tengahnya dengan data yang dicari. Proses ini akan terus\n";
    cout << "    berulang hingga data yang dicari ditemukan atau bisa jadi data yang dicari tidak ada.\n";
    cout << "       Cara ini jauh lebih cepat dibanding pencarian sekuensial, terutama untuk data yang berukuran besar\n";
    cout << "    karena membagi ruang pencarian menjadi dua bagian setiap langkahnya. Namun, kekurangannya adalah data\n";
    cout << "    harus sudah terurut terlebih dahulu dengan algoritma yang sedikit lebih rumit untuk dipahami dan juga\n";
    cout << "    diimplementasikan dibandingkan cara pencarian sekuensial.\n";
    cout << "\n==================Perbedaan Sequential Searching dan Binary Searching=====================\n\n";
    cout << "           Sequential Searching            |              Binary Searching                \n";
    cout << "-------------------------------------------|----------------------------------------------\n";
    cout << "    Mencari data satu per satu dari awal   |        Membagi data menjadi dua bagian       \n";
    cout << "               hingga akhir                |                secara berulang               \n";
    cout << "-------------------------------------------|----------------------------------------------\n";
    cout << "         Tidak perlu data terurut          |      Hanya bisa dilakukan pada data yang     \n";
    cout << "                                           |                sudah diurutkan               \n";
    cout << "-------------------------------------------|----------------------------------------------\n";
    cout << "      Kurang efisien untuk data besar      | Lebih cepat dan efisien dibanding sequential \n";
    cout << "-------------------------------------------|----------------------------------------------\n";
}

int main() {
    clrscr();
    int pilih;
    
    do {
        cout << "\n===== PROGRAM PENCARIAN DATA =====" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan perbedaan Sequential Searching dan Binary Searching!" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih : ";
        cin >> pilih;
        
        switch(pilih) {
            case 1:
                sequent();
                break;
            case 2:
                binary();
                break;
            case 3:
                penjelas();
                break;
            case 4:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        
        if(pilih != 4) {
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }

    } while(pilih != 4);   
    return 0;
}