#include <iostream>
using namespace std;

const int MAX_RIWAYAT = 200;

void tampilkanMenu() {
    cout << "\nPilih mata uang:\n";
    cout << "1. USD (Dolar Amerika)\n";
    cout << "2. EUR (Euro)\n";
    cout << "3. JPY (Yen Jepang)\n";
    cout << "4. MYR (Ringgit Malaysia)\n";
    cout << "5. WON (Won Korea)\n";
    cout << "0. Kembali\n";
    cout << "Pilihan: ";
}

double konversiDariRupiah(double rupiah, double kurs) {
    return rupiah / kurs;
}

double konversiKeRupiah(double nilaiAsing, double kurs) {
    return nilaiAsing * kurs;
}

double konversiAntarAsing(double nilaiAsing, double kursAsal, double kursTujuan) {
    return (nilaiAsing * kursAsal) / kursTujuan;
}

void tampilkanRiwayat(string riwayat[], int jumlah) {
    if (jumlah == 0) {
        cout << "\nBelum ada riwayat konversi.\n";
        return;
    }

    cout << "\n======= RIWAYAT KONVERSI =======\n";
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". " << riwayat[i] << endl;
    }
}


int main() {

    string nama[5] = {"USD", "EUR", "JPY", "MYR", "WON"};
    double kurs[5] = {16712, 19421, 108, 4044, 11.53};

    string riwayat[MAX_RIWAYAT];
    int jumlahRiwayat = 0;

    int pilihanMenu, asal, tujuan;
    double jumlah, hasil;

    cout << "========== PROGRAM KONVERSI MATA UANG ==========\n";

    while (true) {
        cout << "\nMenu Utama:\n";
        cout << "1. Rupiah ke Mata Uang Asing\n";
        cout << "2. Mata Uang Asing ke Rupiah\n";
        cout << "3. Mata Uang Asing ke Mata Uang Asing\n";
        cout << "4. Lihat Riwayat Konversi\n";
        cout << "0. Keluar\n";

        
        cout << "Pilih menu: ";
        cin >> pilihanMenu;
