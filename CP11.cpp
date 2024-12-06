/*
Soal: Arkavidia 7.0 - Penyisihan PCA

    Judul Program: Ambil Batu
    Deskripsi:
    Elon dan Melvin sedang bermain sebuah game. Terdapat sebuah tumpukan batu yang berisi  M buah batu.
    Lalu, mereka boleh mengambil sejumlah batu dari tumpukan tersebut.
    Jumlah yang boleh diambil harus merupakan suatu bilangan dari himpunan {A1 ,A2,...,A N}.
    Pemain akan dinyatakan kalah bila ia tidak dapat mengambil batu. 
    Elon akan bergerak pertama kali. Mereka akan memainkan Q buah permainan.
    Dengan mengasumsikan bahwa setiap pemain akan selalu melakukan gerakan terbaik, tentukan siapa yang akan memenangkan setiap permainan!

    Format Masukan:
    1. Baris pertama berisi dua buah bilangan  N (1≤N≤20), menyatakan jumlah bilangan pada himpunan dan Q (1≤Q≤10^5), menyatakan banyaknya permainan. 
    2. Baris kedua berisi  N bilangan asli A1,A2,...,AN (1≤Ai≤20), berupa himpunan banyaknya batu yang dapat diambil.
       Dijamin bahwa setiap elemen pada A unik.  
    3. Q baris berikutnya berisi satu bilangan bulat M (1≤M≤10^18), menyatakan jumlah batu pada tumpukan.

    Format Keluaran:
    1. Q buah baris yang berisi nama pemenang permainan ("Elon" atau "Melvin" tanpa tanda kutip).
    _________________
    |Contoh Masukan |
    |4 5            |
    |1 2 3 4        |
    |13             |
    |26             |
    |39             |
    |52             |
    |65             |
    |---------------|
    |Contoh Keluaran|
    |Elon           |
    |Elon           |
    |Elon           |
    |Elon           |
    |Melvin         |
    |---------------|
    Penjelasan:
    Pada permainan pertama, terdapat 13 buah batu. Salah satu skenario yang mungkin terjadi adalah:
    Elon mengambil 3 buah batu, sehingga tersisa 10 buah batu.
    Melvin mengambil 2 buah batu, sehingga tersisa 8 buah batu.
    Elon mengambil 3 buah batu, sehingga tersisa 5 buah batu.
    Melvin mengambil 4 buah batu, sehingga tersisa 1 buah batu.
    Elon mengambil 1 buah batu, sehingga tersisa 0 buah batu.
    Melvin tidak dapat mengambil batu.
    Oleh karena itu, Elon memenangkan permainan pertama.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MAX_A = 20;
const int MAX_N = 20;

unordered_map<long long, bool> memo;

bool isWinning(long long M, const vector<int>& moves) {
    if (M == 0) return false;
    if (memo.count(M)) return memo[M];

    for (int move : moves) {
        if (M >= move && !isWinning(M - move, moves)) {
            return memo[M] = true;
        }
    }
    return memo[M] = false;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> moves(N);
    for (int i = 0; i < N; ++i) {
        cin >> moves[i];
    }

    vector<string> results(Q);
    for (int i = 0; i < Q; ++i) {
        long long M;
        cin >> M;

        if (isWinning(M, moves)) {
            results[i] = "Elon";
        } else {
            results[i] = "Melvin";
        }
    }

    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}
