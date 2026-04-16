// Addition of two numbers a Twist
// Using a method, pass two variables and find the sum of two numbers.
// Test case:
// Number 1 – 20
// Number 2 – 20.38
// Sum = 40.38

// There were a total of 4 test cases. Once you compile 3 of them will be shown to you and 1 will be a hidden one.
//  You have to display error message if numbers are not numeric. 

#include<iostream>
using namespace std;

template<typename T>
T add(T a, T b){
    return a+b;
}

int main(){
   float n1, n2;
   cin>>n1>>n2;

   if(!n1 || !n2) cout<<"error";
   else cout<<add(n1, n2);

   return 0;
}