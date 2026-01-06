#include <iostream>
using namespace std;
int main()
{
 int x;//2
 cout << "Enter first number\n";
 cin >> x; // user will give ‘x’ a value.
 int y, m;//3  6
 cout << "Enter second number and value for taking modulus\n";
 cin >> y >> m; // user will give ‘y’ a value.
 int Z = (x * y) % m;
 cout << "Output is: " << Z;//0
}