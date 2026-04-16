// James has a sequence of N numbers. There is also an integer X which is a random number from other sources. He is allowed to perform a specific 
// operation on this sequence X number of times. Below is the operation:

// Pick exactly one element from the sequence and multiply it with -1.
// Your task is to find out the number of different sequences which can be formed by performing the above operation. If the answer is large, 
// print the result modulo 109 +7.

// Let us try to understand it with an example,

// N = 3
// X = 2
// S = [1, 2, 3]

// There are 2 ways in which this operation can be performed.

// Way 1: Either -1 should be multiplied to the same element 2 times, OR
// Way 2: -1. Should be multiplied by two different elements once each.
// Way 1:
// If we multiply -1, to each element 2 times. It will become +1 (-1 *-1).
// We will get the same sequence for each element:

// Multiply -1, 2 times to S[1] : [1, 2, 3].
// Multiply -1, 2 times to S[2] : [1, 2, 3].
// Multiply -1, 2 times to S[3] : [1, 2, 3].
// So, the unique sequence is just 1 which is [1, 2, 3].

// Way 2:
// If we multiply -1, by two different elements just 1 time each. We get:

// Multiply -1 to S[1] & S[2] : [-1, -2, 3].
// Multiply -1 to S[2] & S[3] : [1, -2, -3].
// Multiply -1 to S[1] & S[3] : [-1, 2, -3].
// Hence, we get a total of 3 different sequences from Way 2.
// Total 1 + 3 = 4 different sequences.

// Hence the answer is 4

// Example 1:

// Input:
// 3 1 -> Input integer, N, X
// {1, 2, 1} -> Input integer, S
// Output:
// 3 -> Output
// Explanation:
// In the given scenario, we have X =1. Hence, we can have this multiplication of -1 only once.
// So, if we multiply -1, by different elements just 1 time. We get:
// Multiply -1 to S[1] & S[2] : [-1, 2, 1].
// Multiply -1 to S[2] & S[3] : [1, -2, 1].
// Multiply -1 to S[1] & S[3] : [1, 2, -1].
// Hence, we get a total of 3 different sequences. 
// So, the answer is 3.

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

// Compute C(n, r) mod p using Pascal's triangle
long long C[1001][1001]; // adjust size as needed

void precompute(int n) {
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    }
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> s(n);
    for (int& v : s) cin >> v;

    precompute(n);

    long long ans = 0;

    // Valid k: same parity as X, k <= min(X, N)
    int start = x % 2; // k starts at 0 if X even, 1 if X odd
    int limit = min(x, n);

    for (int k = start; k <= limit; k += 2) {
        ans = (ans + C[n][k]) % MOD;
    }

    cout << ans << endl;
    return 0;
}