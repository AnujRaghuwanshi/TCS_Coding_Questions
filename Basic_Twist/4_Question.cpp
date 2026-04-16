// Number Series with a Twist 2
// Link to this Question
// Consider the following series: 1, 1, 2, 3, 4, 9, 8, 27, 16, 81, 32, 243, 64, 729, 128, 2187 …

// This series is a mixture of 2 series – all the odd terms in this series form a geometric series and all the even terms form yet another geometric series. Write a program to find the Nth term in the series.

// The value N in a positive integer that should be read from STDIN. The Nth term that is calculated by the program should be written to STDOUT. Other than value of n th term,no other character / string or message should be written to STDOUT. For example , if N=16, the 16th term in the series is 2187, so only value 2187 should be printed to STDOUT.

// You can assume that N will not exceed 30.

#include<iostream>
using namespace std;

int findTerm(int a, int b){
    if(b == 0) return 1;
    int half = findTerm(a, b/2);
    int res = half * half;
    if(b & 1) res *= a;
    
    return res;
}

int main(){
    int n;
    cin>>n;

    int term = 1;
    if(n == 1 || n == 2) cout<<term;

    else if(n % 2 == 0){
        int x = n/2 - 1;
        cout<<findTerm(3,x);
    }else{
        cout<<findTerm(2,n/2);
    }

    return 0;
}