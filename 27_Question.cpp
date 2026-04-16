// Given a string, find the second most frequent character in it. Expected time complexity is O(n) where n is the length of the input string.

// Examples:

// Input: str = "aabababa";
// Output: Second most frequent character is 'b'

// Input: str = "abcd";
// Output: No Second most frequent character
// A simple solution is to start from the first character, count its occurrences, then second character and so on. 
// While counting these occurrence keep track of max and second max. Time complexity of this solution is O(n2).
// We can solve this problem in O(n) time using a count array with size equal to 256 (Assuming characters are stored in ASCII format). 
// Following is C implementation of the approach. 

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

char secondFreq(string& s){
    vector<int> alpha(256,0);
    int max_freq = 0;
    int second = 0;

    for(auto ch : s){
        alpha[ch]++;
    }

    for(int i = 0; i < 256; i++){
        if(alpha[i] > 0){
            if(alpha[i] > alpha[max_freq]){
                second = max_freq;
                max_freq = i;
            }
            else if(alpha[i] > alpha[second] && alpha[i] != alpha[max_freq]){
                second = i;
            }
        }
    }
    return (char)second;
}
int main(){
    string str;
    cin>>str;

    cout<<secondFreq(str);
    return 0;
}