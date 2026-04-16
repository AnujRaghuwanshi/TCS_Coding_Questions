// Jack and Jill are playing a string game. Jack has given Jill two strings A and B. Jill has to derive a string C from A, by deleting elements from string A, such that string C does not contain any element of string B. Jill needs help to do this task. She wants a program to do this as she is lazy. Given strings A and B as input, give string C as Output.

// Example 1:
// Input:
// tiger     -> input string A
// ti          -> input string B
// Output:
// ger       -> Output string C
// Explanation:
// After removing “t” and “i” from “tiger”, we are left with “ger”.
// So, the answer is “ger”.
// Example 2:

// Input:
// processed     -> input string A
// esd                -> input string B
// Output:
// proc               -> Output string C
// Explanation:
// After removing “e” “s” and “d” from “processed”, we are left with “proc”.
// So, the answer is “proc”.
// Example 3:

// Input:
// talent        -> input string A
// tens          -> input string B
// Output:
// al              -> Output string C
// Explanation:
// After removing “t” “e” and “n” from “talent”, we are left with “al”.
// So, the answer is “al”.

#include<bits/stdc++.h>
using namespace std;

string removeChar(string& A, string& B){
    string res;
    for(auto ch : A){
        if(B.find(ch) == string::npos){
            res += ch;
        }
    }
    return res;
}

int main(){
    string A,B;
    cin>>A;
    cin>>B;

    cout<<removeChar(A,B);

    return 0;
}