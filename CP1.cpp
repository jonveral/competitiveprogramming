/*
Soal: Jumlah Subarray dengan Jumlah Tertentu
    Diberikan sebuah array A dengan panjang n,
    hitung jumlah subarray (segmen berurutan) yang memiliki jumlah elemen sama dengan k
    Input Format:
    1. Baris pertama berisi dua bilangan bulat n dan k (1≤n≤10^5 , −10^9≤k≤10^9).
    2. Baris kedua berisi 𝑛n bilangan bulat A[1],A[2],…,A[n] (−10^4≤A[i]≤10^4 ).
    Output Format:
    1. Cetak satu bilangan bulat, jumlah subarray yang memiliki jumlah elemen sama dengan k.
    ---------------
    Contoh Input
    5 7  
    2 4 1 2 5
    ---------------
    Contoh Output
    2
    ---------------
    Penjelasan: Subarray dengan jumlah 7 adalah:
    Subarray dari indeks 0 hingga 2: [2,4,1].
    Subarray dari indeks 3 hingga 4: [2,5].
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int countSubarraysWithSum(int arr[], int n, int k) {
    unordered_map<int, int> prefix_count; 
    int prefix_sum = 0, count = 0;

    prefix_count[0] = 1;

    for (int i = 0; i < n; ++i) {
        prefix_sum += arr[i]; 

        if (prefix_count.find(prefix_sum - k) != prefix_count.end()) {
            count += prefix_count[prefix_sum - k]; 
        }

        prefix_count[prefix_sum]++;
    }

    return count;
}

int main() {
    int n, k;
    cout << "Masukkan panjang array dan nilai k: ";
    cin >> n >> k;

    int arr[n];
    cout << "Masukkan elemen array: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << countSubarraysWithSum(arr, n, k) << endl;
    return 0;
}
