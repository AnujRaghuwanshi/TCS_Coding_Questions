// Given two arrays, val[] and wt[], representing the values and weights of item respectively, and an integer capacity representing 
// the maximum weight a knapsack can hold, we have to determine the maximum total value that can be achieved by putting the items in 
// the knapsack without exceeding its capacity.
// Items can also be taken in fractional parts if required.

#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int>& a, vector<int>& b){
    double x = (1.0 * a[0]) / a[1];
    double y = (1.0 * b[0]) / b[1];
    return x > y;
}

int fractionalKnapsack(vector<int>& val, vector<int>& wt, int W){
    int n = val.size();
    vector<vector<int>> items(n,vector<int>(2));

    for(int i = 0; i < n; i++){
        items[i][0] = val[i];
        items[i][1] = wt[i];
    }

    sort(begin(items), end(items), compare);

    double res = 0.0;
    for(int i = 0; i < n; i++){
        if(items[i][1] <= W){
            res += items[i][0];
            W -= items[i][1];
        }else{
            res += (1.0 * items[i][0] / items[i][1]) * W;
            break;
        }
    }
    return res;
}

int main(){
    vector<int> val = {10,20,30};
    vector<int> wt = {1,2,3};
    int capacity = 6;

    cout<<fractionalKnapsack(val,wt,capacity);
    return 0;
}