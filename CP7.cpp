/*
Soal: Urutan Aneh
    Deskripsi
    Buatlah program yang melakukan pengurutan N (2≤N≤1000) buah bilangan seperti pada contoh kasus di bawah ini.
    Format Masukan:
    1. Baris pertama berisi satu buah bilangan N.
    2. Baris kedua berisi N buah bilangan bulat Xi.
    3. Setiap bilangan dipastikan hanya antara 0-100.
    Format Keluaran:
    1. N buah baris berisi urutan bilangan sesuai dengan contoh
    ________________________________
    |  Contoh Masukan               |
    |  10                           |
    |  1 11 12 2 13 23 31 62 71 81  |
    |-------------------------------|
    |  Contoh Keluaran              |
    |  1                            |
    |  11                           |
    |  31                           |
    |  71                           |
    |  81                           |
    |  2                            |
    |  12                           |
    |  62                           |
    |  13                           |
    |  23                           |
    |-------------------------------|

*/

#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int N;
    cin >> N;
    cout << endl;
    
    int X[N];
    for(int i=0; i<N; i++){
        cin >> X[i];
    }

    
    int len_x = sizeof(X)/sizeof(X[0]);
    sort(X, X+len_x);
    
    for(int j=0; j<=9; j++){
        for(int k=0; k<N; k++){
            if(X[k]%10==j){
                cout << X[k] << endl;
            }
        }
    }
    
    return 0;
}