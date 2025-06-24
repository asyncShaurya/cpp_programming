// Convert EUR to USD
/*
#include <iostream>
using namespace std;

int main(){
    const double usd_per_eur{1.19};

    cout << "Welcome to the EUR to USD converter" << endl;
    cout << "Enter the value in EUR:";

    double euros{0.0};
    double dollars{0.0};

    cin >> euros;
    dollars = euros*usd_per_eur;
    cout << euros << " euros is equivalent to " << dollars << " dollars" << endl;
    return 0;
}
*/
// USD to Rupees

#include <iostream>
using namespace std;

int main(){
    const double usd_per_rupees{84.6};

    cout << "Welcome to usd to rupees converter" << endl;
    cout << "Enter the value in dollars:";

    double rupees{0.0};
    double dollars{0.0};

    cin >> dollars;
    rupees = dollars*usd_per_rupees;
    cout << dollars << " dollars is equivlatent to " << rupees << " rupees " << endl;
    return 0;
}