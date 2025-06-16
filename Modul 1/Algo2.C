#include <iostream>
using namespace std;

struct Kendaraan {
    string plat;
    string jenis;
    string namaP;
    string alamat;
    string kota;
};

int main() {
    Kendaraan data;

    data.plat = "DA1234MK";
    data.jenis = "RUSH";
    data.namaP = "Andika Hartanto";
    data.alamat = "Jl. Kayu Tangi 1";
    data.kota = "Banjarmasin";

    cout << "Plat Nomor Kendaraan  : " << data.plat << endl;
    cout << "Jenis Kendaraan       : " << data.jenis << endl;
    cout << "Nama Pemilik          : " << data.namaP << endl;
    cout << "Alamat                : " << data.alamat << endl;
    cout << "Kota                  : " << data.kota << endl;

    return 0;
}