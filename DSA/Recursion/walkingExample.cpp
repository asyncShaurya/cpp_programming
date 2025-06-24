#include <iostream>
using namespace std;
void reachHome(int src, int dest)
{
    cout << " source " << src << " destination " << dest << endl;
    // base case
    if (src == dest)
    {
        cout << " reached home " << endl;
        return;
    }
    // processing- ek step aage badhjao
    src++;
    // recursive call
    reachHome(src, dest);
}

int main()
{
    int src = 1;
    int dest = 10;

    cout << endl;
    reachHome(src, dest);

    return 0;
}