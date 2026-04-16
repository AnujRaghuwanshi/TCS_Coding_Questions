// Largest Palindromic Number
// You are given a string num consisting of digits only.

// Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. 
// It should not contain leading zeroes.

// Notes:
// You do not need to use all the digits of num, but you must use at least one digit.
// The digits can be reordered.
 
// Example 1:
// Input: num = "444947137"
// Output: "7449447"
// Explanation: 
// Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
// It can be shown that "7449447" is the largest palindromic integer that can be formed.
// Example 2:

// Input: num = "00009"
// Output: "9"
// Explanation: 
// It can be shown that "9" is the largest palindromic integer that can be formed.
// Note that the integer returned should not contain leading zeroes.

#include<bits/stdc++.h>
using namespace std;

string largestPalindromic(string& num){
    if(num.empty()) return "";
    vector<int> freq(10,0);

    for(char &ch : num){
        freq[ch - '0']++;
    }

    string firstHalf = "", middle = "";

    for(char c = '9'; c >= '0'; c--){
        if(freq[c - '0'] > 0){
            int f = freq[c - '0'];
            if(f % 2 == 1 && middle.empty()){
                middle +=c;
            }
            if(c == '0' && firstHalf.empty()) continue;
            firstHalf += string(f/2,c);
        }
    }

    if(firstHalf.empty() && middle.empty() && freq['0' - '0'] > 0) return "0";

    string last = firstHalf;
    reverse(last.begin(), last.end());
    return firstHalf+middle+last;
}

int main(){
    string num;
    cin>>num;

    cout<<largestPalindromic(num);
    return 0;
}