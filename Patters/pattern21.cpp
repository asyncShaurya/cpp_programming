#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int row = 1;
    while (row <= n)
    {
        //first triangle
        int i = 1;
        while(i<=row){
            cout<<i;
            i=i+1;
        }


        //second trinagle
        int star = row-1;
        while(star){
            cout<<"*";
            star=star-1;
        } 

        //third triangle
        int j = n - row + 1;
        while (j)
        {
            cout << j;
            j = j - 1;
        }

        cout << endl;
        row = row + 1;
    }
}