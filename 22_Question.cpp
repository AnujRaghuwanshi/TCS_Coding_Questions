// Joe was reading an interesting novel when all of a sudden, his 5-year-old son came to him and started asking a few questions about functions. 
// He tried making him understand various functions, but his son didn’t get find it interesting. Then he created his function Absent number function 
// A(S) According to this function, there is always the smallest positive integer number in a sequence that is not available. 
// In simple words, if you sort the given sequence, then the smallest integer number (other than 0) which is not present in the sequence is the 
// Absent number. Consider a sequence S= [1, 2, 3], then B(S)=4. The minimum value greater than 0 which is not present here in the sequence is 4. 
// Now his son found it interesting, So Joe extended this logic to sub-sequence. If there is a given sequence S, you have to find the Absent Number 
// for each sub-sequence and then sum it up. If the answer is large, print the result modulo, 109 +7.

// Let say there exist a sequence with N = 3, and sequence S = [1, 2, 1]
// Below are the various sub-sequences of it,

// It will be 2N:

// [ ] : B([ ]) = 1
// [1] : B([1]) = 2
// [2] : B([2]) = 1
// [1] : B([1]) = 2
// [1, 2] : B([1, 2]) = 3
// [2, 1] : B([2, 1]) = 3
// [1, 1] : B([1, 1]) = 2
// [1, 2, 1] : B([1, 2, 1]) = 3

// Total sum of all B(S) = 1+2+1+2+3+3+2+3 = 17.
// Hence the answer is 17.

// Example 1:

// Input:
// 2 -> input Integer, N
// 1 1 -> input Integer, S
// Output:
// 7 -> Output
// Explanation:
// In the above scenario below are the various sub-sequence and their respective functions of it:
// [ ] : B(l) = 1
// [1]: B([1])= 2
// [1]: B([1]) = 2
// [1,1]: B([1,1]) = 2
// Total sum of all B(S) = 1+2+2+2 = 7 Hence the answer is 7.
// Example 2:

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void findSubsets(int curr, vector<int>& S, vector<int>& subset, vector<vector<int>>& res){
    if(curr == S.size()){
        res.push_back(subset);
        return;
    }
    
    subset.push_back(S[curr]);
    findSubsets(curr + 1, S, subset, res);

    subset.pop_back();
    findSubsets(curr + 1, S, subset, res);
}

int sumAbsent(int N, vector<int>& S){
    int mod = 1e9+7;
    if(N == 0) return 1;
    
    sort(S.begin(), S.end());

    vector<int> subset;
    vector<vector<int>> res;
    findSubsets(0, S, subset, res);

    int ans = 0;
    for(const auto &v : res){
        int min_val = 1;
        for(const auto &x : v){
            if(x == min_val) min_val++;
        }
        ans = (ans + min_val) % mod;
    }

    return ans % mod;
}

int main(){
    int N;
    cin>>N;

    vector<int> S(N);
    for(int i = 0; i < N; i++){
        cin>>S[i];
    }

    cout<<sumAbsent(N, S);
    return 0;
}