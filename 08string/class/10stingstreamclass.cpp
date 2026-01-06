#include <iostream>
#include <vector>
#include <string>
#include <sstream>//string stream class extra header file
using namespace std;
int main()
{
    string str = "raghav is a maths teacher";
    stringstream ss(str);
    string temp;
    while (ss >> temp)
    { // input taking temp
        cout << temp << endl;
    }
}