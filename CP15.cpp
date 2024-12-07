/*
Link Soal: https://codeforces.com/problemset/problem/300/C
    Beautiful Numbers
    Vitaly is a very weird man. He's got two favorite digits a and b.
    Vitaly calls a positive integer good, if the decimal representation of this integer only contains digits a and b.
    Vitaly calls a good number excellent, if the sum of its digits is a good number.
    For example, let's say that Vitaly's favourite digits are 1 and 3, then number 12 isn't good and numbers 13 or 311 are.
    Also, number 111 is excellent and number 11 isn't.
    Now Vitaly is wondering, how many excellent numbers of length exactly n are there.
    As this number can be rather large, he asks you to count the remainder after dividing it by 1000000007 (10^9+7).
    A number's length is the number of digits in its decimal representation without leading zeroes.

    Input
    The first line contains three integers: a, b, n (1≤a<b≤9, 1≤n≤10^6).
    Output
    Print a single integer — the answer to the problem modulo 1000000007 (10^9+7).

    Examples
    ________
    |Input |
    |1 3 3 |
    |------|
    |Output|
    |1     |
    |------|
    ________
    |Input |
    |2 3 10|
    |------|
    |Output|
    |165   |
    |------|
*/

#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

// Fungsi untuk menghitung (base^exp) % mod
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Fungsi untuk menghitung kombinasi (nCr) modulo MOD
long long combination(long long n, long long r, vector<long long>& fact) {
    if (r > n) return 0;
    long long denom = (fact[r] * fact[n - r]) % MOD;
    long long inv_denom = modPow(denom, MOD - 2, MOD); // Modular inversi dengan Fermat
    return (fact[n] * inv_denom) % MOD;
}

// Fungsi untuk memeriksa apakah suatu angka adalah "Good Number"
bool isGoodNumber(long long num, int a, int b) {
    while (num > 0) {
        int digit = num % 10;
        if (digit != a && digit != b) return false;
        num /= 10;
    }
    return true;
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    vector<long long> fact(n + 1, 1); // Array faktorial
    for (int i = 2; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    long long result = 0;
    for (int k = 0; k <= n; ++k) {
        long long sum = k * a + (n - k) * b; // Jumlah digit
        if (isGoodNumber(sum, a, b)) {
            result = (result + combination(n, k, fact)) % MOD;
        }
    }

    cout << result << endl;
    return 0;
}

