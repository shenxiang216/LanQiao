#include <iostream>
using namespace std;
void f(int n)
{
    if (n == 1)
        cout << "A";
    else
    {
        f(n - 1);
        char temp = 'A' + n - 1;
        cout << temp;
        f(n - 1);
    }
}
int main()
{
    int n;
    cin >> n;
    f(n);
    return 0;
}