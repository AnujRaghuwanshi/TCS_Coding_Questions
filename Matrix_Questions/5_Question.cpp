// Find Maximum Sum Submatrix in a given matrix
// Given a M x N matrix, calculate maximum sum submatrix of size k x k in a given M x N matrix in O(M*N) time. Here, 0 < k < M, N.

// For example, consider below 5 x 5 matrix

// [ 3 -4 6 -5 1 ]
// [ 1 -2 8 -4 -2 ]
// [ 3 -8 9 3 1 ]
// [ -7 3 4 2 7 ]
// [ -3 7 -5 7 -6 ]

// If k = 2, maximum sum k x k sub-matrix is
// [ 9 3 ]
// [ 4 2 ]

// If k = 3, maximum sum k x k sub-matrix is
// [ 8 -4 -2 ]
// [ 9 3 1 ]
// [ 4 2 7 ]

#include<bits/stdc++.h>
using namespace std;

int maxSumSubmatrix(vector<vector<int>>& grid, int n, int m, int k){

    vector<vector<int>> ps(m,vector<int>(n,0));

    for(int i=0; i < m; i++){
        for(int j=0; j<n ;j++){
            ps[i][j] = grid[i][j];
            if(i > 0) ps[i][j] += ps[i-1][j];
            if(j > 0) ps[i][j] += ps[i][j-1];
            if(i > 0 && j > 0) ps[i][j] -= ps[i-1][j-1];
        }
    }

    int maxSum = INT_MIN;
    for(int i = k-1; i < m; i++){
        for(int j = k-1; j < n; j++){

            int sum = ps[i][j];

            if(i >= k) sum -= ps[i-k][j];
            if(j >= k) sum -= ps[i][j-k];
            if(i >= k && j >= k) sum += ps[i-k][j-k];

            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}

int main(){
    vector<vector<int>> grid = {
        {3,-4,6,-5,1},
        {1,-2,8,-4,-2},
        {3,-8,9,3,1},
        {-7,3,4,2,7},
        {-3,7,-5,7,-6}
    };

    cout << maxSumSubmatrix(grid, 5, 5, 2);

    return 0;
}