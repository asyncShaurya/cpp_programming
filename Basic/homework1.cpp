// Homework to do is to check whether the character is in lower , upper or in numeric.
#include <iostream>
using namespace std;
int main(){
    char ch;
    cout<< "Enter the value of ch:" << endl;
    cin >>ch;
    if(ch>='a' && ch<='z'){
        cout<< "This character is lowercase" << endl;
    }
    else if(ch>='A' && ch<='Z'){
        cout<< "This character is uppercase" << endl;
    }
    else if(ch>='0' && ch<='9'){
    cout << "This character is numeric" << endl;
    }
    else{
        cout<< "NULL" << endl;
    }
    return 0;
    
}