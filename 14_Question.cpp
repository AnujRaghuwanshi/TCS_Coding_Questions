// ## Smallest window containing all characters
// Given two strings s and p. Find the smallest substring in s consisting of all the characters (including duplicates) of the string p.
// Return empty string in case no such substring is present.
// If there are multiple such substring of the same length found, return the one with the least starting index.

// Examples:

// Input: s = "timetopractice", p = "toc"
// Output: "toprac"
// Explanation: "toprac" is the smallest substring in which "toc" can be found.
// Input: s = "zoomlazapzo", p = "oza"
// Output: "apzo"
// Explanation: "apzo" is the smallest substring in which "oza" can be found.
// Input: s = "zoom", p = "zooe"
// Output: ""
// Explanation: No substring is present containing all characters of p.

#include<bits/stdc++.h>
using namespace std;

// string smallestWindow(string& s, string& p){                            //for lowerCase alphabet
//     int n = s.length();
//     int m = p.length();
//     if(m > n) return "-1";

//     vector<int> sChar(26,0), pChar(26,0);
//     int start = -1, len = INT_MAX, c = 0, c2 = 0, j = 0;

//     for(int i = 0; i < m; i++){
//         pChar[p[i] - 'a']++;
//         if(pChar[p[i] - 'a'] == 1) c++;
//     }

//     for(int i = 0; i < n; i++){
//         sChar[s[i] - 'a']++;
//         if(sChar[s[i] - 'a'] == pChar[s[i] - 'a']) c2++;
//         if(c == c2){
//             while(sChar[s[j] - 'a'] > pChar[s[j] - 'a']) sChar[s[j++] - 'a']--;
//             if(len > (i - j + 1)){
//                 start = j;
//                 len = i - j + 1;
//             }
//         }
//     }
//     if(start == -1) return "-1";
//     return s.substr(start, len);
// }

string smallestWindow(string& s, string& t){
    int n = s.length();
    int m = t.length();

    if(m > n) return "";

    unordered_map<char,int> mp;
    for(char &ch : t){
        mp[ch]++;
    }

    int requiredCount = m;
    int minWindow = INT_MAX;
    int i = 0, j = 0;
    int start = -1;

    while(j < n){
        char ch = s[j];
        if(mp[ch] > 0){
            requiredCount--;
        }

        mp[ch]--;

        while(requiredCount == 0){
            if(minWindow > j - i + 1){
                minWindow = j - i + 1;
                start = i;
            }
            mp[s[i]]++;
            if(mp[s[i]] > 0){
                requiredCount++;
            }
            i++;
        }
        j++;
    }
    return start == -1 ? "" : s.substr(start, minWindow);
}

int main(){
    string s, p;
    cin>>s>>p;
    cout<<smallestWindow(s , p);
    return 0;
}