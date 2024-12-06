/*
Soal: Arkavidia 7.0 - Penyisihan PCE

    Judul Program: Emordnilap
    Deskripsi:
    Emor adalah orang yang percaya kepada hal yang aneh.
    Suatu hari, ia percaya bahwa dengan menulis sebuah kata S dengan terbalik, maka ia akan beruntung.
    Namun, Emor hanya bisa menulis karakter berupa huruf alfabet non-kapital dan angka 0 sampai 9 saja,
    dan jika ada karakter alfabet kapital maka akan diubah menjadi non-kapital.
    Jika ada karakter yang tidak bisa ditulis Emor, maka Emor akan menyerah saja.
    Anda diberikan juga kata S tersebut, tentukan hasil kata yang akan ditulis Emor dan apakah Emor beruntung atau tidak!

    Format Masukan:
    1. Satu baris berisi string S (1≤∣S∣≤100), menyatakan kata yang diberikan dan terdiri karakter alfabet, karakter angka, atau karakter lain.

    Format Keluaran:
    1. Satu baris yang berisi kata yang telah ditulis Emor. Jika Emor tidak bisa menulis dan menyerah, maka keluarkan "Emor tidak beruntung :(" (tanpa tanda petik).
    ___________________
    |Contoh Masukan 1 |
    |Kasur            |
    |-----------------|
    |Contoh Keluaran 1|
    |rusak            |
    |-----------------|
    _________________________
    |Contoh Masukan 2       |
    |Ka$ur                  |
    |-----------------------|
    |Contoh Keluaran 2      |
    |Emor tidak beruntung :(|
    |-----------------------|
    ___________________
    |Contoh Masukan 3 |
    |beRuntung123     |
    |Contoh Keluaran 3|
    |321gnutnureb     |
    |-----------------|
*/

#include <iostream>
#include <string>
#include <cctype> 

int main() {
    std::string S, result;
    bool isLucky = true;

    std::getline(std::cin, S); 

    
    for (int i = S.length() - 1; i >= 0; --i) {
        char ch = S[i];
        if (std::isalnum(ch)) { 
            if (std::isalpha(ch)) {
                ch = std::tolower(ch); 
            }
            result += ch; 
        } else {
            isLucky = false; 
            break;
        }
    }

    if (isLucky) {
        std::cout << result << std::endl; 
    } else {
        std::cout << "Emor tidak beruntung :(" << std::endl; 
    }

    return 0;
}
