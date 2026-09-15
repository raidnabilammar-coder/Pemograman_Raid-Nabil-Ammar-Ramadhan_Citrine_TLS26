#include <iostream>
using namespace std;

int nilaiHuruf(char huruf) {
    return huruf - 'A' + 1;
}
char huruf(int nilai) {
    return 'A' + nilai - 1;
}
int panjangPesan(char pesan[]) {
    int panjang = 0;
    while (pesan[panjang] != '\0') {
        panjang++;
    }
    return panjang;
}

void sandi(char pesan[]) {
    int panjang = panjangPesan(pesan);
    int sebelumnya = 0;

    for (int i = 0; i < panjang; i++) {
        int sekarang = nilaiHuruf(pesan[i]);
        int hasil = sekarang + sebelumnya;
        if (hasil > 26) {
            hasil = hasil % 26;
        }
        if (hasil == 0) {
            hasil = 26;
        }
        pesan[i] = huruf(hasil);
        sebelumnya = sekarang;
    }
}

int main() {
    char pesan[1000];
    cout << "Masukkan pesan: ";
    cin >> pesan;
    sandi(pesan);
    cout << "Pesan yang telah disandi: " << pesan << endl;
    return 0;
}