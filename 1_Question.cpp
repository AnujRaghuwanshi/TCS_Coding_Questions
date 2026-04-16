// There was some circular kriya m = 4 for n > 0 we need to practice kriya such that it will vanish two neighbours
// For example if n = 4
// If kriya 2 practice then it will vanish x-1, x+1 and x also i.e., 1,3,2 will be vanished
// We need to find the maximum sum of the values who will not be vanished

// For m = 4, n = 5
// output = 32
// For m = 4, n = 10
// output = 120

#include<bits/stdc++.h>
using namespace std;

int main(){
    int m = 4, n;
    cin>>n;

    int sum = 0;

    if(n & 1){
        for(int i=3; i<=n; i+=2){
                sum += i;
        }
    }
    else{
        for(int i=2; i<=n; i+=2){
                sum += i;
        }
    }
    cout<<sum*m;
    return 0;
}