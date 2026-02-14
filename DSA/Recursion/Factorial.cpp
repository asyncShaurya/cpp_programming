#include<iostream>
using namespace std;
int factorial(int n){
    if(n==0){
        return 1;
    }
    return factorial(n-1)*n;
}

int Ifactorial(int n){
    int f=1;
    int i;
    for(i=1;i<=n;i++){
        f=f*i;
    }
    return f;
}
int main(){
    int x;
    x = Ifactorial(5);
    cout << x << endl;
    return 0;
}