// Given an array Arr[] of size T, contains binary digits, where 

// 0 represents a biker running to the north.
// 1 represents a biker running to the south.
// The task is to count crossing biker in such a way that each pair of crossing biker(N, S), where 0<=N<S<T, 
// is passing when N is running to the north and S is running to the south.

// Constraints:

// 0<=N<S<T

// Example 1:

// Input :

// 5 -> Number of elements i.e. T
// 0 -> Value of 1st element.
// 1 -> Value of 2nd element
// 0 -> Value of 3rd element.
// 1 -> Value of 4th element.
// 1 -> Value of 5th element
// Output :

// 5
// Explanation:

// The 5 pairs are (Arr[0], Arr[1]), (Arr[0], Arr[3]), (Arr[0], Arr[4]), (Arr[2],Arr[3]) and (Arr[2], Arr[4]).

#include<bits/stdc++.h>
using namespace std;

int countPairs(int n, vector<int>& arr){
    int ans = 0, c = 0;
    for(auto x : arr){
        if(x){
            ans += c;
        }else{
            c++;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    cout<<countPairs(n,arr);
    return 0;
}