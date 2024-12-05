/*

Soal: Fungsi Angka Menurun
    Buatlah sebuah fungsi untuk perhitungan mundur dari sebuah angka yang diambil dari parameternya,
    outputnya harus berupa angka yang menghitung mundur sesuai dengan digit angka yang diberikan sampai dengan index ke 0,
    jadi buatlah sebuah fungsi untuk soal berikut ini dan outputnya harus mengembalikan sebuah Array seperti dibawah ini.

    Output
    F(5) => [5, 4, 3, 2, 1, 0]
    F(3) => [3, 2, 1, 0]
    F(0) => []

*/

#include <iostream>
#include <vector>

std::vector<int> growUpNumber(int n) {
    if (n == 0) return {};

    std::vector<int> result;

    for (int i = n; i >= 0; --i) {
        result.push_back(i);
    }

    return result;
}

int main() {
    int num;

    std::cout << "x =  ";
    std::cin >> num;

    std::vector<int> result = growUpNumber(num);

    std::cout << "F(" << num << ") => [";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
