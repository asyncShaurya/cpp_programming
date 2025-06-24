#include<iostream>
using namespace std;

int main(){
    int n;

    cout << "Enter the number of element in the array: ";
    cin >> n;

    int arr[n];
    int sum = 0;

    cout<< "Enter the element of the array: ";
    for(int i = 0; i<n; i++){
        cin>> arr[i];
    }

    for(int i=0; i<n ; i++){
        sum = sum + arr[i];
    }

    cout<< " The sum of all elements in the array is:" << sum << endl;

    return 0;
}