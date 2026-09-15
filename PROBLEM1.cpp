#include <iostream>
using namespace std;

// Hilangkan astronaut
void hilangAstronaut(int astronaut[], int &jumlah, int posisi) {
    for (int i = posisi; i < jumlah - 1; i++) {
        astronaut[i] = astronaut[i + 1];
    }
    jumlah--;
}

// Urutan eliminasi
void eliminasi(int astronaut[], int jumlah) {
    long long K = 1;
    int posisi = 0;
    cout << "Urutan eliminasi: ";
    while (jumlah > 1) {
        int eliminasiPosisi = (posisi + (K - 1) % jumlah) % jumlah;

        // Menyimpan nomor astronaut yang dieliminasi
        int nomor = astronaut[eliminasiPosisi];
        cout << nomor << " ";

        if (nomor % 2 == 0) {
            K = K * 2;
        } else {
            K = K * 3;
        }
        if (K < 2) {
            K = 2;
        }

        // Hilangkan astronaut
        hilangAstronaut(astronaut, jumlah, eliminasiPosisi);
        if (jumlah > 0) {
            posisi = eliminasiPosisi % jumlah;
        }
    }
    cout << "\nAstronaut terakhir: " << astronaut[0] << endl;
}

int main() {
    int N;
    cout << "Jumlah astronaut: ";
    cin >> N;
    int astronaut[1000];

    for (int i = 0; i < N; i++) {
        astronaut[i] = i + 1;
    }
    eliminasi(astronaut, N);
    return 0;
}