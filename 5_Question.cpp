// Jack is always excited about sunday. It is favourite day, when he gets to play all day. And goes to cycling with his friends. 
// So every time when the months starts he counts the number of sundays he will get to enjoy.
// Considering the month can start with any day, be it Sunday, Monday…. Or so on.

// Count the number of Sunday jack will get within n number of days.

//  Example 1:

// Input 

// mon-> input String denoting the start of the month.

// 13  -> input integer denoting the number of days from the start of the month.

// Output :

// 2    -> number of days within 13 days.

// Explanation:

// The month start with mon(Monday). So the upcoming sunday will arrive in next 6 days.
// And then next Sunday in next 7 days and so on.

// Now total number of days are 13. It means 6 days to first sunday and then remaining 7 days will end up in another sunday.
// Total 2 sundays may fall within 13 days.

#include<bits/stdc++.h>
using namespace std;

int TotalSunday(string day, int n){
    unordered_map<string,int> days;
    days.insert({"sun",0});
    days.insert({"mon",6});
    days.insert({"tue",5});
    days.insert({"wed",4});
    days.insert({"thu",3});
    days.insert({"fri",2});
    days.insert({"sat",1});

    int count = 0;
    int rem_days = n - days[day];

    if(rem_days >= 0){
        count = 1 + (rem_days / 7);
    }
    return count;

}

int main(){
    string day;
    cin>>day;
    int no_of_days;
    cin>>no_of_days;

    cout<<TotalSunday(day,no_of_days);
    return 0;
}