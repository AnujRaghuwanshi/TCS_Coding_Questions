// Given N gold wires, each wire has a length associated with it. At a time, only two adjacent small wires are assembled at the end of a 
// large wire and the cost of forming is the sum of their length. Find the minimum cost when all wires are assembled to form a single wire.

// For Example: Suppose, Arr[]={7,6,8,6,1,1,}

// {7,6,8,6,1,1}-{7,6,8,6,2} , cost =2

// {7,6,8,6,2}- {7,6,8,8}, cost = 8

// {7,6,8,8} – {13,8,8}, cost=13

// {13,8,8} -{13,16}, cost=16

// {13, 16} – {29}, cost =29

// 2+8+13+16+29=68
// Hence , the minimum cost to assemble all gold wires is 68.

// Constraints
// 1<=N<=30
// 1<= Arr[i]<=100

// Example 1:
// Input 

// 6  -> Value of N, represent size of Arr

// 7  -> Value of Arr[0], represent length of 1st wire

// 6 -> Value of Arr[1], represent length of 2nd wire

// 8 -> Value of Arr[2] , represent length of 3rd wire

// 6 -> Value of Arr[3], represent length of 4th wire

// 1 -> Value of Arr[4], represent length of 5th wire

// 1 -> Value of Arr[5], represent length of 6th wire

// Output : 68 

// Example 2:
// Input 

// 4   -> Value of N, represents size of Arr

// 12  -> Value of Arr[0], represents length of 1st wire 

// 2   -> Value of Arr[1], represent length of 2nd wire

// 2   -> Value of Arr[2], represent length of 3rd wire

// 5  -> Value of Arr[3], represent length of 4th wire

// Output : 34

#include<bits/stdc++.h>
using namespace std;

int minCost(int n, vector<int>& arr){
    
    priority_queue<int, vector<int>,  greater<int>> min_heap;
    for(auto x : arr){
        min_heap.push(x);
    }

    int cost = 0;
    while (min_heap.size() > 1)
    {
        int first = min_heap.top();
        min_heap.pop();

        int second = 0;
        if(!min_heap.empty()){
            second = min_heap.top();
            min_heap.pop();
        }

        cost += first + second;
        min_heap.push(first + second);
    }

    return cost;    
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    cout<<minCost(n,arr);
    return 0;
}