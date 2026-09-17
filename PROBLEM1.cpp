#include <iostream>
using namespace std;

void eliminasiAstronot(int N, int K) {
    int astronaut[100];
    // Mengisi nomor astronot 1 sampai N
    for (int i = 0; i < N; i++) {
        astronaut[i] = i + 1;
    }
    int jumlah = N;
    int posisi = 0;
    cout << "Urutan eliminasi: ";

    while (jumlah > 1) {
        // Mencari posisi astronot yang dieliminasi
        posisi = (posisi + K - 1) % jumlah;
        int tereliminasi = astronaut[posisi];
        cout << tereliminasi << " ";
        // Mengubah K berdasarkan nomor astronot
        if (tereliminasi % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;

            if (K < 2) {
                K = 2;
            }
        }
        // Menghapus astronot dari array
        for (int i = posisi; i < jumlah - 1; i++) {
            astronaut[i] = astronaut[i + 1];
        }
        jumlah--;
        // Setelah eliminasi, mulai dari orang setelahnya
        if (posisi == jumlah) {
            posisi = 0;
        }
    }
    cout << "\nAstronot terakhir: " << astronaut[0] << endl;
}

int main() {
    int N, K;
    cout << "Masukkan jumlah astronot: ";
    cin >> N;
    cout << "Masukkan nilai K: ";
    cin >> K;
    if (K < 2) {
        K = 2;
    }
    eliminasiAstronot(N, K);
    return 0;
}