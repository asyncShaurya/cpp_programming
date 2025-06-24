//Overloading copy assignment
#include <iostream>
#include <vector>
#include "Mystring.h"
#include "Mystring.cpp"

using namespace std;
int main(){
    Mystring a{"Hello"};          //overloaded constructor
    Mystring b;                  //no-args constructor
    b = a;                      //copy assignment
                               //b.operator =(a)
    b ="This is a test";      //b.operator=("This is a test");

    Mystring empty;
    Mystring larry("Larry");
    Mystring stooge{larry};
    Mystring stooges;

    empty = stooge;

    empty.display();
    larry.display();
    stooge.display();
    empty.display();

    stooges = "Larry,Moe, and Curly";
    stooges.display();

    vector<Mystring> stooges_vec;
    stooges_vec.push_back("Larry");
    stooges_vec.push_back("Moe");
    stooges_vec.push_back("Curly");

    cout << "============Loop1======="<<endl;
    for(const Mystring &s: stooges_vec)
     s.display();        //copy assignment

     return 0;

}