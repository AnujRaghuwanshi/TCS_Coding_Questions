// Given an encoded string s, decode it by expanding the pattern k[substring], where the substring inside brackets is written k times.
// Return the final decoded string.

// Examples:  

// Input: s = "3[b2[ca]]"
// Output: bcacabcacabcaca

// Explanation: 
// Inner substring "2[ca]" breakdown into "caca".
// Now , new string becomes "3[bcaca]"
// Similarly "3[bcaca]" becomes "bcacabcacabcaca" which is final result.

// Input: s = "3[ab]"
// Output: ababab
// Explanation: The substring "ab" is repeated 3 times, giving "ababab".

#include<bits/stdc++.h>
using namespace std;

string decodeString(string& s){

    stack<char> st;

    for(auto ch : s){
        if(ch == ']'){
            string new_str  = "";
            string num;
            while (!st.empty() && st.top() != '[')
            {
                new_str = st.top() + new_str;
                st.pop();
            }

            st.pop();

            while(!st.empty() && isdigit(st.top())){
                num = st.top() + num;
                st.pop();
            }

            int n = stoi(num);
            string temp = new_str;

            for(int i=1; i<n; i++){
                new_str += temp;
            }

            for(auto c : new_str){
                st.push(c);
            }
            
        }else{
            st.push(ch);
        }
    }

    string res;

    while(!st.empty()){
        res = st.top() + res;
        st.pop();
    }

    return res;
}

int main(){
    string s;
    cin>>s;

    cout<<decodeString(s);
    return 0;
}