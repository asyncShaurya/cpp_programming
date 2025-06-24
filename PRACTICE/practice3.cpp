// Dereferencing pointer 

#include <iostream>
#include<vector>
using namespace std;

int main(){
    int score {100};
    int *score_ptr{&score};
    cout << *score_ptr << endl;

    *score_ptr = 200;
    cout << *score_ptr << endl;
    cout << score << endl;

cout <<"\n---------------------" << endl;
vector<string> stooges{"Larry","Moe","Curly"};
vector<string>*vector_prt{nullptr};

vector_prt = &stooges;
cout << "First stooge: " <<(*vector_prt).at(0) << endl;

cout << "Stooges:";
for(auto stooge: *vector_prt)
  cout << stooge << " ";
cout << endl;  
    return 0;
}