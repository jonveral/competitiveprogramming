#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long minimalChocolatesAndCandies(int N, vector<long long>& A, vector<long long>& B) {
    // Tentukan total minimum T berdasarkan kondisi awal
    long long T = 0;
    for (int i = 0; i < N; ++i) {
        T = max(T, A[i] + B[i]);
    }

    // Pastikan setiap anak memiliki nilai unik
    vector<pair<long long, int>> adjustments(N);
    for (int i = 0; i < N; ++i) {
        adjustments[i] = {A[i] + B[i], i};
    }

    // Urutkan berdasarkan total awal
    sort(adjustments.begin(), adjustments.end());

    // Tetapkan total unik mulai dari T
    vector<long long> finalTotals(N);
    finalTotals[adjustments[0].second] = T;

    for (int i = 1; i < N; ++i) {
        int idx = adjustments[i].second;
        long long prevTotal = finalTotals[adjustments[i - 1].second];
        finalTotals[idx] = max(prevTotal + 1, T); // Pastikan nilai unik dan ≥ T
    }

    return finalTotals[adjustments[N - 1].second];
}

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    cout << minimalChocolatesAndCandies(N, A, B) << endl;
    return 0;
}
