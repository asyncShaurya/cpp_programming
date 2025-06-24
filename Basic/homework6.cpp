#include<iostream>
using namespace std;

int main(){
    const int size = 10;
    int arr[size];

    //Initialize all element to a specific number
    for(int i = 0; i<size; ++i){
        arr[i]=5;
    }
    //Print the array to verify
    for(int i = 0; i<size; ++i){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    return 0;
}