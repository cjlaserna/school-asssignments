// Given three floating-point numbers x, y, and z, 
// output x to the power of z, 
// x to the power of (y to the power of z), 
// the absolute value of y
// square root of (xy to the power of z).

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x;
    double y;
    double z;

    cin >> x;
    cin >> y;
    cin >> z;

    cout << pow(x, z) << " " << pow(x, pow(y,z)) << " "  << abs(y) << " " << sqrt(pow(x*y, z)); 

    return 0;
}