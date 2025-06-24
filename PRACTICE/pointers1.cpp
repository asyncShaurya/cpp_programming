#include <iostream>
using namespace std;

int main(){
    int num = 5 ;
    cout << num << endl;

    //address of Operator -&

    cout << "address of num is " << &num << endl;
    
    int *ptr = &num;
    cout << "value is : " << *ptr << endl;
    (*ptr)++;
    cout << "after increment the value of num " << num << endl;
    
    //important concept
    int i = 3;
    int *t = &i;
    cout << (*t)++ << endl;
    
    return 0;
}