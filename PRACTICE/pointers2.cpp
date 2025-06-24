#include<iostream>
using namespace std;
int main(){
    // int arr[10] = {23,122,41,67};
    
    // cout << " address of first memory block is " << arr << endl;
    // cout << " address of first memory block is " << &arr[0] << endl;
    // cout << " Something value " << *arr << endl;
    // cout << "5th "<< *arr +1 << endl;
    // cout << "6th "<< *(arr+1) << endl;
    // cout << "7th "<< *(arr) + 1 << endl;

    // int i = 3;
    // cout << i[arr] << endl;

    // int a[20] = {1,2,3,4,5};
    // cout << " -> "<< &a[0] << endl;

    // int *p = &a[0];
    // cout << " -> " << &p << endl;

    // arr = arr + 1; it will give an error

    int arr[10];

    int *ptr = &arr[0];
    cout << ptr << endl;
    ptr = ptr +1;
    cout << ptr << endl;
     return 0;
}