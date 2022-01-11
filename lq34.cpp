#include <iostream>
using namespace std;
int main()
{
    int t, s, m, h;
    cin >> t;
    if (t == 0)
    {
        cout << "0:0:0";
    }
    else
    {
        s = t % 60;
        m = ((t - s) / 60) % 60;
        h = (t / 60 - m) / 60;
        cout << h << ":" << m << ":" << s;
    }
    return 0;
}