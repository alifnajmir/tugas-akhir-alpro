#include <iostream>
using namespace std;

int main()
{
     cout << "Selamat datang dilayanan perpustakaan online" << endl;
     cout << "Silahkan, pilih layanan yang ingin anda gunakan" << endl;
     cout << "1. Tambah Buku" << endl;
     cout << "2. Edit Buku" << endl;
     cout << "3. Cari Buku" << endl;
     cout << "4. List Buku" << endl;

     int pilihLayanan;
     cout << "Masukkan Nomer Layanan Yang Ingin Anda Gunakan";
     cin >> pilihLayanan;

     cout << "Anda memilih layanan nomer : " << pilihLayanan;
}