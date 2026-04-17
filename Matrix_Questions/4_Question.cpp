// Maximum size square sub-matrix with all 1s
// Given a binary matrix, find out the maximum size square sub-matrix with all 1s.

// For eg –  if the entered matrix is
// [ {1,0,0,1,0},   
//   {1,1,1,1,1},  
//   {1,0,1,1,1},  
//   {0,0,1,1,0} ,     
//   {1,1,1,1,1}],     

// then the output will be
// [{1,1},     
//  {1,1},     
//  {1,1},     
//  {1,1}]

#include<bits/stdc++.h>
using namespace std;

int SumsquareMatrix(int n, int m, vector<vector<int>>& grid){
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i = 0; i < n; i++) dp[i][0] = grid[i][0];
    for(int j = 0; j < m; j++) dp[0][j] = grid[0][j];

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(grid[i][j] == 0) dp[i][j] = 0;
            else{
                dp[i][j] = 1 + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sum += dp[i][j];
        }
    }
    return sum;
}

void maxSquare(vector<vector<int>>& grid, int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    int maxSize = 0;
    int endRow = 0, endCol = 0;

    // Fill DP
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(i == 0 || j == 0){
                dp[i][j] = grid[i][j];
            }
            else if(grid[i][j] == 1){
                dp[i][j] = 1 + min({
                    dp[i-1][j],
                    dp[i][j-1],
                    dp[i-1][j-1]
                });
            } 
            else {
                dp[i][j] = 0;
            }

            // Track maximum
            if(dp[i][j] > maxSize){
                maxSize = dp[i][j];
                endRow = i;
                endCol = j;
            }
        }
    }

    // Print result
    cout << "Max size: " << maxSize << endl;

    cout << "Submatrix:\n";
    for(int i = 0; i < maxSize; i++){
        for(int j = 0; j < maxSize; j++){
            cout << 1 << " ";
        }
        cout << endl;
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> mat(n,vector<int>(m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>mat[i][j];
        }
    }

    cout<<SumsquareMatrix(n, m, mat);
    cout<<endl;

    maxSquare(mat,n,m);
    return 0;
}