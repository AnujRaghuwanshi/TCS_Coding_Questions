// Two parallel roads separated by a river are connected from cities A and B to an outer ring road. Both roads have a high flow of traffic 
// throughout the day. People who want to travel from city A to city B or vice versa have to pass through the ring road which is a huge waste 
// of time and money. To ease the traffic and also to make it convenient for commuters to travel from city A to city B and vice versa, the 
// construction of a bridge over the river is planned.

// The surveillance team submitted a report stating the bridge should be constructed in the following manner:

// The ground or soil is stronger at certain points on the road favorable for the construction of the bridge.
// The strong ground positions are given from the starting point of each road. Say, the road of city A has strong ground at 1,4 meaning there 
// is a strong ground at a distance of 1 unit, another strong ground point at a distance of 4 units from the starting point of the road of city A.
// Collate the strong ground positions of both roads. Sort them in ascending order. Calculate the middle point or median of the combined strong 
// ground positions. The bridge should be constructed from road A as per the middle point calculated. Given the number of strong positions on 
// roads A and B(N1 and N2 respectively) and the strong ground positions on each road, the task here is to calculate the midpoint of the combined 
// strong positions on both roads.

// NOTE: When the strong positions are combined, the repeated positions on the different roads are dropped.

// Example 1:

// Input:
// 3 -> Value of N1
// 3 -> Value of N2
// {3,5,2} -> a[ ], Elements a[0]to a[N1-1], where each input element is separated by new line
// {1,2,3} -> b[ ], Elements b[0]to b[N2-1), where each input element is separated by new line
// Output: 2.5
// Explanation:
// From the inputs given above:
// Number of strong ground positions on road A:3
// Number of strong ground positions on road B:3
// The positions of strong ground from the starting point of road A are at a distance of 3,5,2
// The positions of strong ground from the starting point of road B are at a distance of 1,2,3
// Combining the strong ground positions of both the roads and sorting them in ascending order
// 1, 2, 3, 5
// The Middle points are 2 and 3
// 2+3 = 5
// 5/2 = 2.5
// So, the middle point from where the bridge should be constructed is 2.5.
// Hence, the output is 2.5

// Example 2: 
// Input:
// 2 -> Value of N1
// 3 -> Value of N2
// {2,3} -> all, Elements a[O]to a[N1-1), where each input element is separated by new line
// {5,6,4} -> b[ ], Elements b[O]to b[N2-1], where each input element is separated by new line
// Output: 4
// Explanation:
// From the inputs given above:
// Number of strong ground positions on road A: 2
// Number of strong ground positions on road B: 3
// The positions of strong ground from the starting point of road A are at a distance of 2, 3 The positions of strong ground from the starting 
// point of road B are at a distance of 5, 6, and 4 Combining the strong ground positions of both the roads and sorting them in ascending 
// order: 2, 3, 4, 5, 6 > Middle point is 4
// So, the middle point from where the bridge should be constructed is 4.
// Hence, the output is 4.

#include<bits/stdc++.h>
using namespace std;

double middlePoint(int n1, vector<int>& A, int n2, vector<int>& B){

    set<int> st;
    for(int x : A) st.insert(x);
    for(int y : B) st.insert(y);

    int n = st.size();

    auto mid_index = next(st.begin(), n / 2);

    if(n % 2 == 0){
        return (*mid_index + *next(st.begin(), n / 2 -1)) * 1.0 / 2;
    }

    return *mid_index;



    // vector<int> mid;
    // sort(begin(A), end(A));
    // sort(begin(B), end(B));

    // int i = 0, j = 0;
    // while(i < n1 && j < n2){
    //     if(A[i] == B[j]){
    //         mid.push_back(A[i]);
    //         i++;
    //         j++;
    //     }else if(A[i] > B[j]){
    //         mid.push_back(B[j]);
    //         j++;
    //     }else{
    //         mid.push_back(A[i]);
    //         i++;
    //     }
    // }

    // while (i < n1)
    // {
    //    mid.push_back(A[i++]);
    // }

    // while(j < n2){
    //     mid.push_back(B[j++]);
    // }

    // int n = mid.size();
    // int mid_index = n / 2;

    // if(n % 2 == 0){
    //     return (mid[mid_index] + mid[mid_index - 1]) * 1.0 / 2;
    // }

    // return mid[mid_index];
    
}

int main(){
    int n1, n2;
    cin>>n1>>n2;
    vector<int> A(n1);
    vector<int> B(n2);

    for(int i = 0; i < n1; i++){
        cin>>A[i];
    }
    for(int i = 0; i < n2; i++){
        cin>>B[i];
    }

    cout<<middlePoint(n1,A,n2,B);
    return 0;
}