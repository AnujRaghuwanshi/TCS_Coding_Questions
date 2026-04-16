// Number Series with a Twist – 1
// Find the 15th term of the series?
// 0,0,7,6,14,12,21,18,28
// Explanation :
// In this series the odd term is increment of 7 {0, 7, 14, 21, 28, 35 – – – – – – }
// And even term is a increment of 6 {0, 6, 12, 18, 24, 30 – – – – – – } 

#include<iostream>
using namespace std;

int main(){
    int term;
    cin>>term;

    if(term % 2 == 0){
        cout<<6 * (term / 2 - 1);
    }else{
        cout<<7 * (term / 2);
    }

    return 0;
}