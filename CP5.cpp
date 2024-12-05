/*
Soal: Fungsi additiveInverse
    Buatlah sebuah fungsi untuk menghitung matematik dengan mengunakan pola Additive Inverse seperti angka berikut dibawah ini,
    Additive Inverse sangat identik dengan pertukaran angka dari Plus ke Mines begitu juga sebaliknya,
    jadi buatlah sebuah fungsi untuk soal berikut ini dan outputnya harus mengembalikan sebuah Array seperti dibawah ini.

    Output:
    additiveInverse([12, -7, -1, 3, 5]) => [-12, 7, 1, -3, -5]
    additiveInverse([0, -3, 4, 1, 2]) => [0, 3, -4, -1, -2]
    additiveInverse([-5, -25, 35]) => [5, 25, -35]
*/

#include <iostream>
#include <vector>

std::vector<int> additiveInverse(const std::vector<int>& arr) {
    std::vector<int> result;

    for (int num : arr) {
        result.push_back(-num); 
    }

    return result;
}

int main() {
    int n;
    std::vector<int> input;

    std::cout << "Masukkan jumlah elemen: ";
    std::cin >> n;

    std::cout << "Masukkan elemen-elemen array:\n";
    for (int i = 0; i < n; ++i) {
        int element;
        std::cin >> element;
        input.push_back(element);
    }

    std::vector<int> output = additiveInverse(input);

    std::cout << "additiveInverse([";
    for (size_t i = 0; i < input.size(); ++i) {
        std::cout << input[i];
        if (i < input.size() - 1) std::cout << ", ";
    }
    std::cout << "]) => [";

    for (size_t i = 0; i < output.size(); ++i) {
        std::cout << output[i];
        if (i < output.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
