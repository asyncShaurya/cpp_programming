// This program will calculate the area of a room in square feet 
#include <iostream>
using namespace std;
int main(){

    cout << "Enter the width of the room:";
    int room_width{0};
    cin >> room_width;

    cout << "Enter the length of the room:";
    int room_lenght{0};
    cin >> room_lenght;

    cout << "The area of the room is " << room_width*room_lenght << " square feet" << endl;
    return 0;
}