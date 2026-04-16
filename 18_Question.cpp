// Mr. Rao is relocating from place A to B. The moving truck has a maximum capacity C. 
// There are ‘N’ items in the house where each item has a corresponding value (Vi) and weight(Wi). 
// Mr. Rao has to carry only the most valuable items whose total weight does not exceed the capacity of truck. 
// The task here is to find those items (single or combination of items) whose total value (v) will be the maximum and their 
// corresponding weight(w) will not exceed truck capacity(c). Here,

// N= No. of items
// C= Maximum capacity of the truck, an integer value,
// W[0 to N-1]- An array consisting weight of each item
// V[0 to N-1] – An array consisting value of each item.
// Example 1:

// Input :

// 4  -> Value of N
// 80 -> Value of C
// [10,45,60,90] -> Elements of array v[], where each element is separated by new line.
// [15,20,30,40] -> Elements of array  w[], where each element is separated by new line.
// Output: 150

#include<bits/stdc++.h>
using namespace std;

int maxValue(int n, int C, vector<int>& v, vector<int>& w){
    vector<vector<int>> dp(n+1, vector<int> (C+1,0));

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= C; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }else{
                int pick = 0;
                if(w[i-1] <= j){
                    pick = v[i-1] + dp[i-1][j-w[i-1]]; 
                }
                int not_pick = dp[i-1][j];

                dp[i][j] = max(pick,not_pick);
            }
        }
    }

    return dp[n][C];
}

int main(){
    int n;
    cin>>n;
    int C;
    cin>>C;
    vector<int> v(n), w(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    for(int i = 0; i < n; i++){
        cin>>w[i];
    }

    cout<<maxValue(n,C,v,w);

    return 0;
}