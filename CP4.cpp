/*
Soal: Fungsi isMatchIdentity
    Buatlah sebuah fungsi untuk mengecek setiap huruf yang menggunakan huruf Vowels,
    apakah ada sebuah String yang mengandung karakter yang identik sama,
    jika ada maka buatlah sebuah fungsi yang hanya megembalikan karakter yang identik sama,
    jika karakternya identik sama maka akan mengembalikan nilai true,
    dan jika karakternya tidak identik sama maka akan mengembalikan nilai false,
    jadi buatlah sebuah fungsi untuk soal berikut ini dan outputnya harus mengembalikan sebuah Boolean seperti dibawah ini.

    Output:
    isMatchIdentity("aaaaaa") => true
    isMatchIdentity("aabbbaaa") => false
    isMatchIdentity("ccccc") => true
*/

#include <iostream>
#include <string>
#include <cctype>

bool isVowel(char c) {
    char lower = tolower(c);
    return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
}

bool isMatchIdentity(const std::string& str) {
    if (str.empty()) return false; 
    
    char firstChar = tolower(str[0]); 
    bool isVowelChar = isVowel(firstChar); 

    for (char c : str) {
        if (tolower(c) != firstChar) {
            return false; 
        }

        if (isVowelChar && !isVowel(c)) {
            return false;
        }
    }

    return true; 
}

int main() {
    std::string input;

    std::cout << "Masukkan string: ";
    std::cin >> input;

    bool result = isMatchIdentity(input);
    std::cout << "isMatchIdentity(\"" << input << "\") => " << (result ? "true" : "false") << std::endl;

    return 0;
}
