#include <iostream>
using namespace std;

struct nilai{
    float Mtk;
    float BIn;
    float Big;
    float IPA;
};
struct siswa{
    string nama;
    string NISN;
    string jurusan;
    nilai Nilai; // struct in struct
};
void tambahDataSiswa();//menambahkan data pada file siswa.txt
void tampilDataSiswa();//membaca data dari file siswa.txt dan ditampilkan
void cariSiswa();// berdasarkan NISN
float nilaiAkhir();// nilai akhir = 40%matematika+30%IPA+20%B indonesia +20%B Inggris
void ranking(); // menampilkan data siswa berdasarkan peringkat


void inputDataSiswa(siswa s[], int &jumlah);
void tampilDataSiswa(siswa s[], int jumlah);
float nilaiAkhir(nilai n);


int main() {
    siswa data[100];  
    int jumlah = 0;

    inputDataSiswa(data, jumlah);
    tampilDataSiswa(data, jumlah);

    return 0;
}


void inputDataSiswa(siswa s[], int &jumlah) {
    cout << "Masukkan jumlah siswa: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData siswa ke-" << i + 1 << endl;
        cout << "NISN     : ";
        cin >> s[i].NISN;
        cin.ignore(); 
        cout << "Nama     : ";
        getline(cin, s[i].nama);
        cout << "Jurusan  : ";
        getline(cin, s[i].jurusan);
        cout << "Nilai Matematika  : ";
        cin >> s[i].Nilai.Mtk;
        cout << "Nilai Bahasa Indo : ";
        cin >> s[i].Nilai.BIn;
        cout << "Nilai Bahasa Ing  : ";
        cin >> s[i].Nilai.Big;
        cout << "Nilai IPA         : ";
        cin >> s[i].Nilai.IPA;
    }
}


void tampilDataSiswa(siswa s[], int jumlah) {
    cout << "\n=== DATA SISWA ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "\nSiswa ke-" << i + 1 << endl;
        cout << "NISN     : " << s[i].NISN << endl;
        cout << "Nama     : " << s[i].nama << endl;
        cout << "Jurusan  : " << s[i].jurusan << endl;
        cout << "Nilai Matematika  : " << s[i].Nilai.Mtk << endl;
        cout << "Nilai Bahasa Indo : " << s[i].Nilai.BIn << endl;
        cout << "Nilai Bahasa Ing  : " << s[i].Nilai.Big << endl;
        cout << "Nilai IPA         : " << s[i].Nilai.IPA << endl;
        cout << "Nilai Akhir       : " << nilaiAkhir(s[i].Nilai) << endl;
    }
}


float nilaiAkhir(nilai n) {
    return (0.4 * n.Mtk) + (0.3 * n.IPA) + (0.2 * n.BIn) + (0.1 * n.Big);
}