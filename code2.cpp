#include <iostream>
#include <string>
using namespace std;
enum State
{
    S0,
    S1,
    S2
};
bool isDivisibleBy3(const string &input)
{
    State currentState = S0;
    for (char c : input)
    {
        switch (currentState)
        {
        case S0:
            if (c == '0')
            {
                currentState = S0;
            }
            else if (c == '1')
            {
                currentState = S1;
            }
            break;
        case S1:
            if (c == '0')
            {
                currentState = S2;
            }
            else if (c == '1')
            {
                currentState = S0;
            }
            break;
        case S2:
            if (c == '0')
            {
                currentState = S1;
            }
            else if (c == '1')
            {
                currentState = S2;
            }
            break;
        }
    }

    return currentState == S0;
}
int main()
{
    string input;
    cout << "Enter a binary string: ";
    cin >> input;
    if (isDivisibleBy3(input))
    {
        cout << "Accepted (the number is divisible by 3)" << endl;
    }
    else
    {
        cout << "Rejected (the number is not divisible by 3)" << endl;
    }
    return 0;
}