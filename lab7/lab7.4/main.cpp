///Implement "power" recursive function

#include <iostream>
using namespace std;

int calcPower(int base, int powerOf)
{
    if (powerOf != 0)
        return (base*calcPower(base, powerOf-1));
    else
        return 1;
}

int main()
{
    int base, powerRaised, result;

    cout << "Enter base number: ";
    cin >> base;

    cout << "Enter power number(positive integer): ";
    cin >> powerRaised;

    result = calcPower(base, powerRaised);
    cout << base << "^" << powerRaised << " = " << result;

    return 0;
}

