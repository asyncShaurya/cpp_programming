#include <iostream>
using namespace std;
int main()
{
    cout << "Hello, welcome to Shaurya's Carpet Cleaning  Service" << endl;
    cout << "\n How many small rooms would you like cleaned?";
    int number_of_smallrooms;
    cin >> number_of_smallrooms;

    cout << "\n How many large rooms would you like cleaned?";
    int number_of_largerooms;
    cin >> number_of_largerooms;

    const double price_per_smallroom{25.0};
    const double price_per_largeroom{35.0};
    const double sales_tax{0.06};
    const int estimate_expiry{30}; // days

    cout << "\nEstimate for carpet cleaning service" << endl;

    cout << "Number of smallrooms:" << number_of_smallrooms << endl;
    cout << "Number of largerooms:" << number_of_largerooms << endl;

    cout << "Price per smallroom:$" << price_per_smallroom << endl;
    cout << "Price per largeroom:$" << price_per_largeroom << endl;

    cout << "Cost:$" << (price_per_smallroom * number_of_smallrooms) + (price_per_largeroom * number_of_largerooms) << endl;
    cout << "Tax:$" << (price_per_smallroom * number_of_smallrooms * sales_tax) + (price_per_largeroom * number_of_largerooms * sales_tax) << endl;

    cout << "==========================" << endl;
    cout << "Total estimate:$" << (price_per_smallroom * number_of_smallrooms) + (price_per_smallroom * number_of_smallrooms * sales_tax) + (price_per_largeroom * number_of_largerooms) + (price_per_largeroom * number_of_largerooms * sales_tax) << endl;
    cout << "This estimate is valid for" << estimate_expiry << " days" << endl;

    return 0;
}