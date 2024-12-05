/*

Soal: Fungsi minSwaps
    Buatlah sebuah fungsi untuk mengkonversi satu String Biner ke String Biner yang lainnya,
    yang dimana nilainya harus mengembalikan jumlah minimum swap untuk mengkonversi String Biner pertama agar menjadi String Biner yang kedua,
    jadi buatlah sebuah fungsi untuk soal berikut ini dan outputnya harus mengembalikan sebuah Number seperti dibawah ini.

    Output:
    minSwaps("1001", "1001") => 0
    minSwaps("1100", "1001") => 1
    minSwaps("110011", "010111") => 1
    minSwaps("1100", "0011") => 2
    minSwaps("110011", "001111") => 2
    minSwaps("10011001", "01100101") => 3

*/

#include <iostream>
#include <string>
#include <stdexcept>

int minSwaps(const std::string &str1, const std::string &str2) {
    if (str1.length() != str2.length()) {
        throw std::invalid_argument("Strings must be of equal length");
    }

    int mismatched01 = 0; 
    int mismatched10 = 0; 

    for (size_t i = 0; i < str1.length(); ++i) {
        if (str1[i] == '0' && str2[i] == '1') {
            mismatched01++;
        } else if (str1[i] == '1' && str2[i] == '0') {
            mismatched10++;
        }
    }

    if (mismatched01 != mismatched10) {
        return -1; 
    }

    return mismatched01;
}

int main() {
    std::string str1, str2;

    std::cout << "Enter the first binary string: ";
    std::cin >> str1;
    std::cout << "Enter the second binary string: ";
    std::cin >> str2;

    try {
        int result = minSwaps(str1, str2);
        if (result == -1) {
            std::cout << "minSwaps(\"" << str1 << "\", \"" << str2 << "\") ➞ Conversion is impossible" << std::endl;
        } else {
            std::cout << "minSwaps(\"" << str1 << "\", \"" << str2 << "\") ➞ " << result << std::endl;
        }
    } catch (const std::invalid_argument &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
