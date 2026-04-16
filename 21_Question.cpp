// Pangram Checking
// Given a string check if it is Pangram or not. A pangram is a sentence containing every letter in the English Alphabet.

// Examples : The quick brown fox jumps over the lazy dog ” is a Pangram [Contains all the characters from ‘a’ to ‘z’]
// “The quick brown fox jumps over the dog” is not a Pangram [Doesn’t contains all the characters from ‘a’ to ‘z’, as ‘l’, ‘z’, ‘y’ are missing]

// We create a mark[] array of Boolean type. We iterate through all the characters of our string and whenever we see a character we mark it. 
// Lowercase and Uppercase are considered the same. So ‘A’ and ‘a’ are marked in index 0 and similarly ‘Z’ and ‘z’ are marked in index 25.

// After iterating through all the characters we check whether all the characters are marked or not. If not then return false as this is not a 
// pangram else return true.

#include<iostream>
#include<vector>
using namespace std;

bool CheckPangram(string& s){

    int mask = 0;
    for(auto ch : s){
        if(isalpha(ch)){
            mask |= (1 << (tolower(ch) - 'a'));
        }
    }
    return mask == (1 << 26) - 1;

    // vector<int> alpha(26,0);
    // int res = 0;

    // for(char &ch : s){
    //    if(isalpha(ch)){
    //         ch = tolower(ch);
    //         res += !alpha[ch - 'a'];
    //         alpha[ch - 'a'] = 1;
    //     }
    //      }
    // }

    // return res == 26 ? 1 : 0;
}

int main(){
    string str;
    getline(cin,str);

    cout<<CheckPangram(str);
    return 0;
}