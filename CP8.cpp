/*
Soal: Pertandingan
    Deskripsi
    Dalam sebuah pertandingan olahraga, Budi diberikan kesempatan untuk memilih urutan pemain yang harus dilawannya.
    Asumsikan ada N orang lawan yang masing-masing memiliki tingkat kemahiran Ai.
    Setelah Budi berhasil mengalahkan pemain ke-i, tingkat kemahirannya akan bertambah sebanyak Bi yang akan digunakan untuk melawan pemain selanjutnya.
    Perlu diingat bahwa Budi hanya bisa mengalahkan pemain dengan tingkat kemahiran yang lebih rendah atau sama dengan dirinya sendiri.
    Jika Budi memiliki tingkat kemahiran awal M, tentukan pemain manakah yang harus dilawan Budi secara berurutan
    sampai dia tidak bisa lagi mengalahkan lawannya sehingga Budi mendapatkan tingkat kemahiran yang maksimal.
    Format Masukan:
    1. Baris pertama dua buah bilangan N dan M (1≤N, M≤100)
    2. Baris kedua N buah bilangan Ai (1≤Ai≤1000) 
    3. Baris ketiga N buah bilangan Bi (1≤Bi≤1000)
    Format Keluaran:
    1. Tingkat kemahiran maksimal yang akan didapatkan Budi.
    _______________________
    |   Contoh Masukan    |
    |   4 2               |
    |   8 9 3 2           |
    |   5 4 1 3           |
    |---------------------|  
    |   Contoh Keluaran   |
    |   6                 |
    |---------------------|
    _______________________
    |   Contoh Masukan    |
    |   5 3               |
    |   8 4 5 6 7         |
    |   9 8 7 5 6         |
    |---------------------|
    |   Contoh Keluaran   |
    |   3                 |
    |---------------------|
    _______________________
    |   Contoh Masukan     |
    |   5 9                |
    |   2 3 6 7 8          |
    |   3 4 2 2 3          |
    |----------------------|
    |   Contoh Keluaran    |
    |   23                 |                          
    |----------------------|
*/

#include <iostream>
using namespace std;

int main()
{
    
    int N, M;
    cin >> N >> M;
    cout << endl;
    
    int arr_a[N], arr_b[N];
    for(int i=0; i<N; i++){
        cin >> arr_a[i];
    }
    cout << endl;
    
    for(int j=0; j<N; j++){
        cin >> arr_b[j];
    }
    cout << endl;
    
    
    for(int k=0; k<N; k++){
        for(int l=0; l<N; l++){
            if (M>=arr_a[l]){
                M += arr_b[l];
                arr_b[l] = 0;
            }
        }
    }
    
    cout << M;
    
    
    return 0;
}
