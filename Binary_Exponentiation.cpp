// Calculate the Power of a Number : Binary Exponentiation
// To efficiently calculate the power of a number, especially when dealing with large exponents, we can use Binary Exponentiation. 
// We reduce the number of multiplication operations needed to compute the power by breaking down the exponent to its half, smaller 
// operations.

// At each step of the loop, we check whether the current exponent is even or odd.

// If the exponent is even, we square the base as xn = (x2)n/2.
// If the exponent is odd, the algorithm multiples the result by the base as xn = x(xn-1).

#include<iostream>
using namespace std;

int findPower(int a, int b){
    if(b == 0) return 1;
    int half = findPower(a , b / 2);
    int res = half * half;
    if(b & 1){
        res *= a;
    }
    return res;
}

int main(){
    int num;
    cin>>num;

    int power;
    cin>>power;

    cout<<findPower(num,power);

    return 0;
}