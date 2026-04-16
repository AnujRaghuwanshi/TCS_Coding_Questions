// Mahesh and Suresh are playing a new game “Checkers“. This is a very simple game but becomes challenging when more expert players are playing.
// Below is the description of the game and rules: The game is played by 2 players. This game consists of an N*M matrix. Each of the cells is background 
// lit by lights. And these cells are either Green or Black. The green and black cells are randomly lit and will be represented with 1’s and 0’s respectively.
// Green cells are the cells that need to be captured. Black cells cannot be captured. Everyone is in the race to capture the maximum number of cells possible.
// In a single chance, a player can capture all those adjacent cells which share an edge. Once there is no adjacent edge the chance breaks and the next player will play.
// Mahesh always starts the game and Suresh is second.
// Both players are playing optimally, find out how many cells Suresh captures.

// Input:
// N and M, size of the matrix
// A[i][j] for all 1<=i<=N and 1<=j<=M

// Let us try to understand it with an example 

// Consider the matrix below
// N = 4
// M = 4
// A = 1001
//        0110
//        0110
//        1001

// If Mahesh plays first, he will try to capture most of the 1’s, he will capture A[2][2], A[2][3], A[3][2], and A[3][3]. 
// Now there are no adjacent cells left. So, the chance will be given to Suresh. Now Suresh’s turn. He can capture either A[1][1] or A[4][1] or 
// A[1][4] or A[4][4]. He will capture any one cell, and as there is no adjacent deft, the chance will now be given to Mahesh. 
// The game proceeds and then again Suresh’s turn will come, and he will again be able to choose only 1 cell finally Mahesh will end the game by choosing the final cell.
// Like this Mahesh has captured 6 cells and Suresh has captured only 2 cells.
// Hence 2 is the answer.

// Example 1:

// Input:
// 2 2       -> Input integer, N, M
// 1 1       -> Input integer, A[i]
// 1 1       -> Input integer, A[N]
// Output:
// 0          -> Output
// Explanation:
// In the above scenario, it is very clear that if Mahesh plays first, he will capture all the cells as all the cells are adjacent to each other.
// There will be nothing left for Suresh. Hence the cells captured by Suresh will be 0.
// Hence the answer is 0.
// Example 2:

#include<bits/stdc++.h>
using namespace std;

int dfs(int i, int j, int m, int n, vector<vector<int>>& grid){
    if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) return 0;
    grid[i][j] = 0;
    return 1 + dfs(i+1,j,m,n,grid) + dfs(i-1,j,m,n,grid) + dfs(i,j+1,m,n,grid) + dfs(i,j-1,m,n,grid);
}

int Solve(int m, int n, vector<vector<int>>& grid){
    vector<int> comp;
    for (int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1) comp.push_back(dfs(i,j,m,n,grid));
        }
    }

    sort(comp.rbegin(),comp.rend());

    int suresh = 0;
    for(int i=1; i<comp.size(); i += 2){
        suresh += comp[i];
    }

    return suresh;
    
}

int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<int>> A(m,vector<int>(n,0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>A[i][j];
        }
    }
    
    cout<<Solve(m,n,A);
    return 0;   
    
}