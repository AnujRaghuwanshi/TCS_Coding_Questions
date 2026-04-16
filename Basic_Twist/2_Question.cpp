// Prime Numbers with a Twist
// Ques. Write a code to check whether no is prime or not. Condition use function check() to find whether entered no is positive or negative ,if negative then enter the no, And if yes pas no as a parameter to prime() and check whether no is prime or not?

// Whether the number is positive or not, if it is negative then print the message “please enter the positive number”
// It is positive then call the function prime and check whether the take positive number is prime or not.

#include<iostream>
using namespace std;

bool prime(int n){
    if(n == 0 || n == 1) return 0;
    if(n == 2 || n == 3) return 1;

    for(int i = 2; i*i <= n; i++){
        if(n % i == 0) return 0;
    }

    return 1;
}

int main(){
    int num;
    cin>>num;

    if(num < 0) cout<<"please enter the positive number";
    else cout<<prime(num);

    return 0;
}