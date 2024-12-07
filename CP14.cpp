/*
Link Soal: https://codeforces.com/problemset/problem/1542/B
    Plus and Multiply
    There is an infinite set generated as follows:
    => 1 is in this set.
    => If x is in this set, x⋅a and x+b both are in this set.
    For example, when a=3 and b=6, the five smallest elements of the set are:
    => 1,
    => 3 (1 is in this set, so 1⋅a=3 is in this set),
    => 7 (1 is in this set, so 1+b=7 is in this set),
    => 9 (3 is in this set, so 3⋅a=9 is in this set),
    => 13 (7 is in this set, so 7+b=13 is in this set).
    Given positive integers a, b, n, determine if n is in this set.

    Input
    The input consists of multiple test cases. The first line contains an integer t (1≤t≤10^5) — the number of test cases. The description of the test cases follows.
    The only line describing each test case contains three integers n, a, b (1≤n,a,b≤10^9) separated by a single space.
    Output
    For each test case, print "Yes" if n is in this set, and "No" otherwise. You can print each letter in any case.

    Example
    __________________
    |Input           |
    |5               |
    |24 3 5          |
    |10 3 6          |
    |2345 1 4        |
    |19260817 394 485|
    |19260817 233 264|
    |----------------|
    |Output          |
    |Yes             |
    |No              |
    |Yes             |
    |No              |
    |Yes             |
    |----------------|
    Note
    In the first test case, 24 is generated as follows:
    1 is in this set, so 3 and 6 are in this set;
    3 is in this set, so 9 and 8 are in this set;
    8 is in this set, so 24 and 13 are in this set.
    Thus we can see 24 is in this set.
    The five smallest elements of the set in the second test case is described in statements. We can see that 10 isn't among them.
*/

#include <iostream>
using namespace std;

bool isInSet(long long n, long long a, long long b) {
    if (a == 1) {
        return (n - 1) % b == 0;
    }
    long long power = 1;
    while (power <= n) {
        if ((n - power) % b == 0) {
            return true;
        }
        power *= a;
        if (power > n) break;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        cout << (isInSet(n, a, b) ? "Yes" : "No") << endl;
    }
    return 0;
}
