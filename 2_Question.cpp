// The Signal Stability Analyzer
// In a deep space transmission relay, binary signals are streamed continuously.
//  1 represents a stable signal
//  0 represents a disruption caused by cosmic interference.
// The stability of a transmission session is measured by the longest uninterrupted chain of stable pulses.
// Your task is to determine the maximum  no.of consecutive 1s in the signal log.

// Test Cases
// Input: [1,1,0,1,1,1,0,1]
// Output: 3

// Input: [0,0,0,0]
// Output: 0

// Input: [1,1,1,1,1]
// Output: 5

#include<bits/stdc++.h>
using namespace std;

int CountMax(int n, vector<int>& arr){
    int count1 = 0;
    int res = INT_MIN;
    for(int x : arr){
        if(x == 1){
            count1++;
        }else{
            res = max(res,count1);
            count1 = 0;
        }
    }
    return max(res,count1);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<CountMax(n,arr);
    return 0;
}