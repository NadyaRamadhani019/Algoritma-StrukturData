#include <iostream>
using namespace std;

struct Mhs {
    string nama, nim, jurusan;
    int sks, program;
};

int main() {
    int tetap, var;
    Mhs bayar[2];

    for (int i = 0; i < 2; i++) {
        cout << "\n\n--------------------------------------------\n";
        cout << "Input ke-" << i + 1 << endl;
        cout << "--------------------------------------------\n";
        cout << "Nama mhs               = ";
        cin.ignore();
        getline(cin, bayar[i].nama);
        cout << "NIM                    = "; cin >> bayar[i].nim;
        cout << "Jurusan [TI, PTK]      = "; cin >> bayar[i].jurusan;

        while (true) {
            cout << "Program [1=D3, 2=S1]    = "; cin >> bayar[i].program;
            if (bayar[i].program == 1 || bayar[i].program == 2) break;
            cout << "Program tidak sesuai. Ulangi.\n";
        }

        cout << "Jumlah SKS             = "; cin >> bayar[i].sks;

        if(bayar[i].program==1){
            tetap=500000;
            var=bayar[i].sks*25000;
        }else if(bayar[i].program==2){
            tetap=750000;
            var=bayar[i].sks*50000;
        }cout<<endl;

        cout << "\n\n-----------------------------------------\n";
        cout << "Output mahasiswa ke-" << i + 1 << endl;
        cout << "-----------------------------------------\n";
        cout << "Nama mhs           = " << bayar[i].nama << endl;
        cout << "NIM                = " << bayar[i].nim << endl;
        cout << "Jurusan            = " << bayar[i].jurusan << endl;
        cout << "Program            = " << bayar[i].program << endl;
        cout << "Jumlah SKS         = " << bayar[i].sks << endl;
        cout << "SPP tetap          = Rp " << tetap << endl;
        cout << "SPP variabel       = Rp " << var << endl;
    }

    return 0;
}