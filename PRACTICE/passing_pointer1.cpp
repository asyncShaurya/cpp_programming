#include <iostream>
#include <vector>
using namespace std;

void display(int *array, int sentinel)
{
    while (*array != sentinel)
    {
        cout << *array++ << " ";
    }
    cout << endl;
}

int main()
{
    int scores[]{100, 98, 97, 79, 85, -1};
    display(scores, -1);
    cout << endl;
    return 0;
}