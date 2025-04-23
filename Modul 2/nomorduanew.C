#include <iostream>
using namespace std;

const int maks = 5;

struct stack{
    int data[maks];
    int atas = -1;
} Tumpuk;

int kosong(){
    if(Tumpuk.atas == -1)
        return 1;
    else
        return 0;
}

int penuh(){
    if(Tumpuk.atas == maks - 1)
        return 1;
    else
        return 0;
}

void input (int data){
    if(kosong()==1){
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack\n";
    }else if(penuh()==0){
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack\n";
    }else
        cout << "Tumpukan Penuh";
}

void hapus(){
    if(kosong()==0){
        cout << "Data Teratas Sudah Terambil\n";
        Tumpuk.atas--;
    }else{
        cout << " Data Kosong\n";
    }
}

void tampil(){
    if(kosong()==0){
        for(int i = Tumpuk.atas; i>=0; i--)
        {
            cout << "\nTumpukan Ke " << i << " = " << Tumpuk.data[i] << "\n";
        }
    }else
        cout << "Tumpukan Kosong\n";
}

void bersih(){
    Tumpuk.atas = -1;
    cout << " Tumpukan Kosong !\n";
}

int main(){
    int pilih, data;
    
    do{
        cout << "=====MENU STACK=====" << endl;
        cout << "1. Menambah Data ke Tumpukan" << endl;
        cout << "2. Menghapus Data dari Tumpukan" << endl;
        cout << "3. Menampilkan Data di Tumpukan" << endl;
        cout << "4. Bersihkan Data di Tumpukan" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih Menu" << endl;
        cin >> pilih;

        switch (pilih){
        case 1:
            cout << "Masukkan Data (angka): " << endl;
            cin >> data;
            input(data);
            break;
        case 2:
            hapus();
            break;
        case 3:
            tampil();
            break;
        case 4:
            bersih();
            break;
        case 5:
            cout << "Terima Kasih" << endl;
            break;
        default:
            cout << "Pilihan Tidak Valid" << endl;
            break;
        }
    }while(pilih != 5);

    return 0;
}