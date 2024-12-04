/*

Soal: Menyusun Pangkat Terbesar yang Mungkin
    Diberikan dua bilangan bulat a dan b,
    tentukan apakah ada bilangan bulat x dan y sedemikian sehingga a^x = b^y,
    di mana x dan y adalah bilangan bulat positif, dan tentukan nilai x dan y tersebut.
    Jika ada, temukan pasangan x dan y yang memenuhi persamaan tersebut dan dengan nilai x dan y terkecil.
    Jika tidak ada, cetak -1.
    Input Format:
    1. Baris pertama berisi dua bilangan bulat a dan b (2≤a, b≤10^5).
    Output Format:
    1. Jika ada pasangan (x,y), cetak pasangan x dan y yang memenuhi a^x = b^y,
       dengan x dan y terkecil.
    2. Jika tidak ada, cetak -1.
    _______________________
    | Input    | Output   | 
    | 2 8      | 3 1      |
    |----------|----------|
    Penjelasan:
    2^3 = 8^1 = 8,
    jadi pasangan (x,y) = (3,1) adalah solusi yang valid.
    _______________________
    | Input    | Output   | 
    | 4 8      | 3 2      |
    |----------|----------|
    Penjelasan:
    4^3 = 8^2 = 16,
    jadi pasangan (x,y) = (2,3) adalah solusi yang valid.
    _______________________
    | Input    | Output   | 
    | 5 7      | -1       |
    |----------|----------|
    Penjelasan:
    Tidak ada pasangan (x,y) yang memenuhi persamaan 5^x = 7^y,
    jadi output adalah -1.

*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

pair<int, int> find_pair(int a, int b) {
    for (int x = 1; x <= 100; ++x) { 
        double val_a = pow(a, x);
        
        for (int y = 1; y <= 100; ++y) {
            if (val_a == pow(b, y)) {
                return {x, y};
            }
        }
    }
    
    return {-1, -1}; 
}

int main() {
    int a, b;
    cin >> a >> b;

    pair<int, int> result = find_pair(a, b);

    if (result.first == -1) {
        cout << -1 << endl;
    } else {
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}
