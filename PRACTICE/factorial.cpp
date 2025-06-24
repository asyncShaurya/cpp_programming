// Recursion - Factorial

#include <iostream>
using namespace std;

unsigned long long factorial(unsigned long long);

unsigned long long factorial(unsigned long long n){
    if(n==0)
      return 1;   // base case 
    return n*factorial(n-1); // recursive case  
}

int main(){
    cout << factorial(3) << endl;
    cout << factorial(8) << endl;
    cout << factorial(12) << endl;
    cout << factorial(20) << endl;

    return 0;
}