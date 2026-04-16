// Problem Statement –
// Joseph is learning digital logic subject which will be for his next semester. 
// He usually tries to solve unit assignment problems before the lecture. Today he got one tricky question.
// The problem statement is “A positive integer has been given as an input. Convert decimal value to binary representation.
// Toggle all bits of it after the most significant bit including the most significant bit. Print the positive integer value 
// after toggling all bits”.

// Constrains-
// 1<=N<=100

// Example 1:

// Input :  10  -> Integer (1010)

// Output : // 5    -> result- Integer (0101)

// Explanation:

// Binary representation of 10 is 1010. After toggling the bits(1010), will get 0101 which represents “5”.
// Hence output will print “5”.

// 1
// #include<bits/stdc++.h>
// using namespace std;

// int ToggleBits(int n){
//     int no_of_bits = floor(log2(n)) + 1;
//     int k = (1 << no_of_bits) - 1;
//     return k^n;
// }

// int main(){
//     int n;
//     cin>>n;
//     cout<<ToggleBits(n);
//     return 0;
// }

// 2
#include<bits/stdc++.h>
using namespace std;

void ToggleBits(int &n){
    int temp = 1;
    while (temp <= n)
    {
        n ^= temp;
        temp <<= 1;
    }
}

int main(){
    int n;
    cin>>n;
    ToggleBits(n);
    cout<<n;
    return 0;
}