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
        if (c < '0' || c > '9')
        {
            cout << "Invalid input: Non-decimal character encountered!" << endl;
            return false;
        }
        int digit = c - '0'; 
        switch (currentState)
        {
        case S0:
            currentState = static_cast<State>((0 * 10 + digit) % 3);
            break;
        case S1:
            currentState = static_cast<State>((1 * 10 + digit) % 3);
            break;
        case S2:
            currentState = static_cast<State>((2 * 10 + digit) % 3);
            break;
        }
    }
   
    return currentState == S0;
}
int main()
{
    string input;
    cout << "Enter a decimal string: ";
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