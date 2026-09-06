#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of scalar multiplications
int matrixChainOrder(int arr[], int n) {
    // dp[i][j] stores the minimum multiplication cost from matrix i to matrix j
    // Matrix i has dimensions arr[i-1] x arr[i]
    int dp[n][n];

    // Base Case: Cost is 0 when multiplying one matrix
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    // L is the chain length.
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX; // Initialize to infinity

            // Try every possible split position k between i and j-1
            for (int k = i; k <= j - 1; k++) {
                // q = cost/scalar multiplications
                int q = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }

    // The result for multiplying chain from 1 to n-1 is stored at dp[1][n-1]
    return dp[1][n - 1];
}

int main() {
    int arr[] = {10, 30, 5, 60};
    int N = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum number of scalar multiplications is: %d\n", matrixChainOrder(arr, N));

    return 0;
}
