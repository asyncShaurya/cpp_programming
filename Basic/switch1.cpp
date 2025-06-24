#include<iostream>
using namespace std;
int main(){

    int num = 1;
    cout<<endl;
    while(1){
        switch(num){
            case 1 :
            cout<< "First number" << endl;
            break; 
        }
        exit(EXIT_FAILURE); // terminate the program with an error status
    }
    cout<< endl;
    return 0;
}