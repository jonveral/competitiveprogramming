/*
Soal: Arkavidia 7.0 - Penyisihan PCB

    Judul Program: Buku Raja
    Deskripsi:
    Raja Aleks mempunyai buku-buku yang dinomori dari  1 sampai N, buku-buku ini awalnya dijejerkan rapat secara acak dalam satu baris.
    Raja Aleks memerintahkan Sandra untuk mencari suatu buku bernomor X
    dan menaruhnya di paling depan barisan buku tersebut, kemudian mendorong buku agar rapat kembali.
    Sandra dapat pergi dari satu buku ke buku disampingnya selama satu detik.
    Pada awalnya Sandra ada di paling depan barisan buku, dan tentunya harus kembali ke paling depan barisan buku setelah mengambil suatu buku yang diperintahkan.
    Sandra disuruh memenuhi perintah sebanyak M kali,
    Anda sebagai pengawas disana ingin mencari waktu total yang dibutuhkan Sandra untuk melakukan semua perintah Aleks!

    Format Masukan:
    1. Baris pertama berisi dua buah bilangan N dan M (1≤N,M≤10^5), menyatakan banyaknya buku dan banyaknya perintah. 
    2. Baris kedua berisi  N bilangan bulat B1,B2,...,BN (1≤Bi≤N), berupa permutasi nomor-nomor buku yang dijejerkan. 
    3. M baris berikutnya berupa satu bilangan bulat X (1≤X≤N), menyatakan nomor buku yang perlu ditaruh paling depan. 
    Catatan:
    Barisan N bilangan bulat disebut permutasi jika barisan tersebut berisi semua bilangan bulat dari 1 sampai N tepat sekali.

    Format Keluaran:
    1. Satu baris berisi sebuah bilangan bulat berupa total waktu yang dibutuhkan Sandra untuk memenuhi semua perintah Aleks.
    _________________
    |Contoh Masukan |
    |5 4            |
    |1 5 4 3 2      |
    |3              |
    |5              |
    |4              |
    |4              |
    |---------------|
    |Contoh Keluaran|
    |16             |
    |---------------|
    Penjelasan:
    Pada awalnya barisan bukunya adalah [1,5,4,3,2]. 
    Saat mengambil buku nomor 3 dibutuhkan 3 + 3 = 6 detik, sekarang barisan buku menjadi [3,1,5,4,2] 
    Saat mengambil buku nomor 5 dibutuhkan 2 + 2 = 4 detik, sekarang barisan buku menjadi [5,3,1,4,2] 
    Saat mengambil buku nomor 4 dibutuhkan 3 + 3 = 6 detik, sekarang barisan buku menjadi [4,5,3,1,2] 
    Saat mengambil buku nomor 4 dibutuhkan 0 detik, karena sudah berada di paling depan
    Total waktu yang dibutuhkan: 6 + 4 + 6 = 16 detik.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> books(N);
    unordered_map<int, int> position; 

    for (int i = 0; i < N; ++i) {
        cin >> books[i];
        position[books[i]] = i; 
    }

    long long total_time = 0;

    for (int i = 0; i < M; ++i) {
        int X;
        cin >> X;

        int current_pos = position[X];
        total_time += current_pos * 2;

        for (int j = 0; j < N; ++j) {
            if (position[books[j]] < current_pos) {
                position[books[j]]++;
            }
        }
        position[X] = 0;

        books.erase(books.begin() + current_pos);
        books.insert(books.begin(), X);
    }

    cout << total_time << endl;
    return 0;
}
