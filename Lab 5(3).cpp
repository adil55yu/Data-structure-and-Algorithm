#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;

    cout << "Enter the term number: ";
    cin >>n;

    if (n < 0)
        cout << "Please enter a non-negative number.";
    else
        cout << "Fibonacci term at position " << n << " is " << fibonacci(n);

    return 0;
}