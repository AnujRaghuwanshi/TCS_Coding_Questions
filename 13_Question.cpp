//  find the maximum difference where the smallest number appears before the largest in the list

#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> arr = {12, -5, 1, 6, -7, 8, 11};
    int n = arr.size();

    int min_val = arr[0];
    int diff = 0;

    for(int i = 1; i < n; i++){
        
        min_val = min(min_val,arr[i]);

        diff = arr[i] - min_val;
    }

    cout<<diff;

    return 0;
}