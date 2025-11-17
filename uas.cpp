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

        if (pilihanMenu == 0) {
            cout << "\nTerima kasih telah menggunakan program ini!\n";
            break;
        }


        if (pilihanMenu == 1) {
            cout << "\nMasukkan jumlah dalam Rupiah: ";
            cin >> jumlah;

            tampilkanMenu();
            cin >> tujuan;

            if (tujuan == 0) continue;
            if (tujuan < 1 || tujuan > 5) {
                cout << "Pilihan tidak valid!\n";
                continue;
            }

            hasil = konversiDariRupiah(jumlah, kurs[tujuan - 1]);

            cout << "\nHasil konversi: " << hasil << " " << nama[tujuan - 1] << endl;

            riwayat[jumlahRiwayat++] =
                "Rupiah " + to_string(jumlah) +
                " ke " + nama[tujuan - 1] + " " + to_string(hasil);
        }
        else if (pilihanMenu == 2) {
            tampilkanMenu();
            cin >> asal;

            if (asal == 0) continue;
            if (asal < 1 || asal > 5) {
                cout << "Pilihan tidak valid!\n";
                continue;
            }

            cout << "\nMasukkan jumlah dalam " << nama[asal - 1] << ": ";
            cin >> jumlah;

            hasil = konversiKeRupiah(jumlah, kurs[asal - 1]);

            cout << "\nHasil konversi: " << hasil << " Rupiah\n";

            riwayat[jumlahRiwayat++] =
                nama[asal - 1] + string(" ") + to_string(jumlah) +
                " → Rupiah " + to_string(hasil);
        }


        else if (pilihanMenu == 3) {
            cout << "\n--- Pilih Mata Uang Asal ---";
            tampilkanMenu();
            cin >> asal;

            cout << "\n--- Pilih Mata Uang Tujuan ---";
            tampilkanMenu();
            cin >> tujuan;

            if (asal == 0 || tujuan == 0) continue;
            cout << "\nMasukkan jumlah dalam " << nama[asal - 1] << ": ";
            cin >> jumlah;

            hasil = konversiAntarAsing(jumlah, kurs[asal - 1], kurs[tujuan - 1]);

            cout << "\nHasil konversi: " << hasil << " " << nama[tujuan - 1] << endl;

            riwayat[jumlahRiwayat++] =
                nama[asal - 1] + string(" ") + to_string(jumlah) +
                " ke " + nama[tujuan - 1] + " " + to_string(hasil);
        }


        else if (pilihanMenu == 4) {
            tampilkanRiwayat(riwayat, jumlahRiwayat);
        }

        else {
            cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}

            if (asal < 1 || asal > 5 || tujuan < 1 || tujuan > 5) {
                cout << "Pilihan tidak valid!\n";
                continue;
            }
