#include <iostream>
#include <iomanip>
using namespace std;
double PI = 3.14159265358979323;
int main()
{
    int r;
    cin >> r;
    cout << fixed << setprecision(7) << PI * r * r;
    return 0;
}
