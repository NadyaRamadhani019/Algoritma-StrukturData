#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define n 10
using namespace std;

void INSERT();
void DELETE();
void CETAKLAYAR();
void Inisialisasi();
void RESET();
int PIL, F, R;
char PILIHAN [1], HURUF;
char Q[n];
int main(){
    Inisialisasi();
    do{
        cout<<"QUEUE"<<endl;
        cout<<"====="<<endl;
        cout<<"1. INSERT"<<endl;
        cout<<"2. DELETE"<<endl;
        cout<<"3. CETAK QUEUE"<<endl;
        cout<<"4. QUIT"<<endl;
        cout<<"PILIHAN : "; cin>>PILIHAN;
        PIL=atoi(PILIHAN);

        switch(PIL){
            case 1:
                INSERT();
                break;
            case 2:
                DELETE();
                break;
            case 3:
                CETAKLAYAR();
                break;
            default:
                cout<<"TERIMA KASIH"<<endl;
                break;
        }
        cout<<"press any key to continue"<<endl;
        getch();
        system("cls");
    } while (PIL<4);
}

void Inisialisasi(){
    F = R = -1;
    RESET();
}

void RESET(){
    for (int i = 0; i < n; i++)
        Q[i] = ' ';
}

void INSERT(){
    if (R == n - 1){
        cout << "Antrian penuh!" << endl;
    } else {
        cout << "Masukkan satu huruf: ";
        cin >> HURUF;
        if (F == -1) F = 0;
        R++;
        Q[R] = HURUF;
        cout << "Huruf " << HURUF << " dimasukkan ke antrian." << endl;
    }
}

void DELETE(){
    if (F == -1 || F > R){
        cout << "Antrian kosong!" << endl;
    } else {
        cout << "Huruf " << Q[F] << " dihapus dari antrian." << endl;
        Q[F] = ' ';
        F++;
    }
}

void CETAKLAYAR(){
    if (F == -1 || F > R){
        cout << "Antrian kosong!" << endl;
    } else {
        cout << "Isi antrian: ";
        for (int i = F; i <= R; i++){
            cout << Q[i] << " ";
        }cout << endl;
    }
}