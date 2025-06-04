#include <iostream>
using namespace std;

void tukar(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void insertion(string &str) {
    for (int i = 1; i < (int)str.size(); i++) {
        char CharKey = str[i];
        int j = i - 1;
        while (j >= 0 && str[j] > CharKey) {
            str[j + 1] = str[j];
            j--;
        }
        str[j + 1] = CharKey;
    }
}

void mergegabung(string &str, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char *tempL = new char[n1];
    char *tempR = new char[n2];
    
    for (int i = 0; i < n1; i++)
        tempL[i] = str[left + i];
    for (int j = 0; j < n2; j++)
        tempR[j] = str[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (tempL[i] <= tempR[j]) {
            str[k++] = tempL[i++];
        } else {
            str[k++] = tempR[j++];
        }
    }
    while (i < n1) str[k++] = tempL[i++];
    while (j < n2) str[k++] = tempR[j++];
    
    delete[] tempL;
    delete[] tempR;
}

void mergepecah(string &str, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergepecah(str, left, mid);
        mergepecah(str, mid + 1, right);
        mergegabung(str, left, mid, right);
    }
}

void shell(string &str) {
    int n = (int)str.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = str[i];
            int j;
            for (j = i; j >= gap && str[j - gap] > temp; j -= gap) {
                str[j] = str[j - gap];
            }
            str[j] = temp;
        }
    }
}

int partisi(string &str, int low, int high) {
    char pivot = str[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (str[j] <= pivot) {
            i++;
            tukar(str[i], str[j]);
        }
    }
    tukar(str[i + 1], str[high]);
    return i + 1;
}

void quick(string &str, int low, int high) {
    if (low < high) {
        int NewIndex = partisi(str, low, high);
        quick(str, low, NewIndex - 1);
        quick(str, NewIndex + 1, high);
    }
}

void bubble(string &str) {
    int n = (int)str.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                tukar(str[j], str[j + 1]);
            }
        }
    }
}

void selection(string &str) {
    int n = (int)str.size();
    for (int i = 0; i < n - 1; i++) {
        int IndexMin = i;
        for (int j = i + 1; j < n; j++) {
            if (str[j] < str[IndexMin]) {
                IndexMin = j;
            }
        }
        tukar(str[i], str[IndexMin]);
    }
}

void tampil(const string &data) {
    for (int i = 0; i < (int)data.size(); i++) {
        cout << data[i];
        if (i != (int)data.size() - 1) cout << ' ';
    }
    cout << endl;
}

int main() {
    int pilih;

    do {
        cout << "-------------------------" << endl;
        cout << "|        SORTING        |" << endl;
        cout << "-------------------------" << endl;
        cout << " 1. Insertion Sort       " << endl;
        cout << " 2. Merge Sort           " << endl;
        cout << " 3. Shell Sort           " << endl;
        cout << " 4. Quick Sort           " << endl;
        cout << " 5. Bubble Sort          " << endl;
        cout << " 6. Selection Sort       " << endl;
        cout << " 7. Exit                 " << endl;
        cout << "-------------------------" << endl;
        cout << "Masukkan Pilihan : ";
        cin >> pilih;
        cin.ignore();
        cout << endl;

        string temp;
        switch (pilih) {
            case 1:
                cout << "=== INSERTION SORT ===" << endl;
                cout << "Masukkan Nama: ";
                getline(cin, temp);
                insertion(temp);
                cout << "Hasil Sorting: ";
                tampil(temp);
                break;
            case 2:
                cout << "=== MERGE SORT ===" << endl;
                cout << "Masukkan Nama: ";
                getline(cin, temp);
                mergepecah(temp, 0, (int)temp.size() - 1);
                cout << "Hasil Sorting: ";
                tampil(temp);
                break;
            case 3:
                cout << "=== SHELL SORT ===" << endl;
                cout << "Masukkan Nama: ";
                getline(cin, temp);
                shell(temp);
                cout << "Hasil Sorting: ";
                tampil(temp);
                break;
            case 4:
                cout << "=== QUICK SORT ===" << endl;
                cout << "Masukkan NIM: ";
                getline(cin, temp);
                quick(temp, 0, (int)temp.size() - 1);
                cout << "Hasil Sorting: ";
                tampil(temp);
                break;
            case 5:
                cout << "=== BUBBLE SORT ===" << endl;
                cout << "Masukkan NIM: ";
                getline(cin, temp);
                bubble(temp);
                cout << "Hasil Sorting: ";
                tampil(temp);
                break;
            case 6:
                cout << "=== SELECTION SORT ===" << endl;
                cout << "Masukkan NIM: ";
                getline(cin, temp);
                selection(temp);
                cout << "Hasil Sorting: ";
                tampil(temp);
                break;
            case 7:
                cout << "===== TERIMA  KASIH =====" << endl;
                cout << "    -Program selesai-    " << endl;
                cout << "==== Nadya Ramadhani ====" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silahkan pilih kembali." << endl;
        }
        if (pilih != 7) {
            cout << "\nPress Enter to Continue";
            cin.ignore();
            cin.get();
            system("cls");
        }
    } while (pilih != 7);

    return 0;
}