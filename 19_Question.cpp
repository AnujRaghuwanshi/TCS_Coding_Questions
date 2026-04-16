// Mike has arranged a small party for the inauguration of his new startup. He has invited all of his fellow employees who are N in number. 
// These employees are indexed with an array starting from 1 to N. In this startup, everyone knows each other’s salary. We will represent salary 
// by an integer value. Mike has to arrange tables, where he will accommodate everyone. But he is a little thrifty in that, he wants to adjust 
// everyone in as few tables as he can. Tables of various seating are available.
// Let’s say the cost of renting each table is K. All the employees have to seat in the order of the index. The only problem is that the 
// employees with the same salary can get into arguments which can ruin the party.
// Mike came across the term inefficiency of arrangement, which can be defined as the sum of the cost of tables + the total number of people 
// getting into arguments. Given the number of employees, N, and their salaries in array a[ ], he wants to find the optimal inefficiency, i.e., 
// the smallest possible value for the inefficiency of arranging the N employees.

// Let’s understand it with an example.
// Number of employees invited N = 5
// A a = {5 1 3 3 3}
// K = 1

// Now let’s check all the combinations and how in-efficient is all of them.

// When we make 1st, 2nd, and 3rd employee on table-1 and 4th and 5th on table-2
// Cost of 2 tables = 2*1
// Number of people getting into arguments = 2 (two 3’s: 4th and 5th employee)
// Total = 2 + 2 = 4

// When we make 1st, 2nd, 3rd, and 4th employees on table-1 and 5th on table-2
// Cost of 2 tables = 2*1
// Number of people getting into arguments = 2 (two 3’s: 4th and 5th employee)
// Total = 2 + 2 = 4

// When we make all of them sit at 1 table, then inefficiency will be
// Cost of 1 table = 1
// Number of people getting into arguments = 3 (all 3’s: 3rd, 4th and 5th employee)
// Total = 1 + 3 = 4

// When we make 1st, 2nd and 3rd employee on table-1 and 4th on table-2 and 5th on table-3
// Cost of 3 tables = 3*1
// Number of people getting into arguments = 0 (all 3’s are. sitting at different tables)
// Total = 3 + 0 = 3

// Hence the optimal in-efficiency is 3.
// So, the output will be 3.

// Example 2:
// Input:
// 5 14 -> Input Integer, N and K.
// {1, 4, 2, 4, 4} -> Input Integer, array elements a[i].
// Output:
// 17 -> Output
// Explanation:
// Below is the seating for each case:

// Case 1:
// Table 1: 1st, 2nd, and 3rd
// Table 2: 4th and 5th
// Number of people getting into arguments: 2
// Total in-efficiency: 2*14 + 2 = 30

// Case 2:
// Table 1: 1st, 2nd, 3rd, and 4th
// Table 2: 5th
// Number of people getting into arguments: 2
// Total in-efficiency: 2*14 + 2 = 30

// Case 3:
// Table 1: 1st, 2nd, 3rd, 4th, and 5th
// Number of people getting into arguments: 3
// Total in-efficiency: 1*14+3 = 17

// Case 4:
// Table 1: 1st, 2nd, and 3rd
// Table 2: 4th
// Table 3: 5th
// Number of people getting into arguments: 0
// Total in-efficiency: 3*14+ 0 = 42

// Chose the minimum which is 17.
// So, the answer is 17.


#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
#include<algorithm>
using namespace std;

int Countconflicts(vector<int>& arr, int l, int r){
    unordered_map<int,int> freq;
    for(int i = l; i <= r; i++){
        freq[arr[i]]++;
    }

    int conflicts = 0;
    for(auto &p : freq){
        if(p.second >= 2) conflicts += p.second;
    }

    return conflicts;
}

int Optimalinefficiency(int N, vector<int>& arr, int k){
    vector<int> dp(N+1,INT_MAX);
    dp[0] = 0;

    for(int i = 1; i<= N; i++){
        for(int j = 0; j < i; j++){
            int cost = k + Countconflicts(arr, j, i-1);
            if(dp[j] != INT_MAX){
                dp[i] = min(dp[i], dp[j] + cost);
            }
        }
    }

    return dp[N];
}

int main(){
    int N, k; 
    cin>>N;
    cin>>k;

    vector<int> arr(N);
    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }

    cout<<Optimalinefficiency(N, arr, k);

    return 0;
}

