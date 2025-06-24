#include <iostream>
#include <iomanip>
#include <string> //important!

using namespace std;

int main()
{
    string s0;
    string s1{"Apple"};
    string s2{"Banana"};
    string s3{"Kiwi"};
    string s4{"apple"};
    string s5{s1};       // Apple
    string s6{s1, 0, 3}; // App
    string s7(10, 'X');  // XXXXXXXXX

    // cout << s0 << endl;  //No garbage
    // cout << s0.length() << endl; //empty string

    // Initialization
    // cout << "\nInitialization" << "\n---------------------"<< endl;
    // cout << "s1 is initialized to:"<< s1 << endl;
    // cout << "s2 is initialized to:"<< s2 << endl;
    // cout << "s3 is initialized to:"<< s3 << endl;
    // cout << "s4 is initialized to:"<< s4 << endl;
    // cout << "s5 is initialized to:"<< s5 << endl;
    // cout << "s6 is initialized to:"<< s6 << endl;
    // cout << "s7 is initialized to:"<< s7 << endl;

    // Comparison
    // cout << "\nComparison" << "\n-------------------"<< endl;
    // cout << boolalpha;
    // cout << s1 << " == " << s5 <<":" << (s1==s5) << endl;  //True  Apple==Apple
    // cout << s1 << " == " << s2 <<":" << (s1==s2) << endl;  //False Apple!=Banana
    // cout << s1 << " != " << s2 <<":" << (s1!=s5) << endl;  //True  Apple!=Banana
    // cout << s1 << " < " << s2 <<":" << (s1<s2) << endl;   //True  Apple < Banana
    // cout << s2 << " > " << s1 <<":" << (s2>s1) << endl;   // True  Banana > Apple
    // cout << s4 << " < " << s5 <<":" << (s4<s5) << endl;   // False   apple >Apple
    // cout << s1 << " == " << "Apple" <<":" << (s1=="Apple") << endl; // True Apple == Apple

    // getline
    //  cout <<"\ngetline" << "\n-------------------" << endl;
    //  string full_name{};
    //  cout << "Enter your full name: ";
    //  getline(cin,full_name);

    // cout << "Your full names is: " << full_name << endl;

    // Find
    cout << "\nfind" << "\n----------------------" << endl;
    s1 = "The secret word is Boo";
    string word{};

    cout << "Enter the word to find:";
    cin >> word;
    size_t position = s1.find(word);
    if (position != string::npos)
        cout << "Found " << word << " at position:" << position << endl;
    else
        cout << "Sorry, " << word << " not found " << endl;

    return 0;
}