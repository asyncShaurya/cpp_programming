#include<iostream>
using namespace std;
void fun(int n)
{
    if(n>0){
        fun(n-1); // it is head recursion fun
        cout << n << " " << endl;
       //fun(n-1); it is tail recursion fun

    }
}

int main(){
    int x=3;
    fun(x);

    return 0;
}