#include <iostream>
using namespace std;
int n;
string A(int n)
{
    int i = 0;
    string A;
    A.append("sin(");
    string num;
    for (i = 1; i < n; i++)
    {
        num = '0' + i;
        if (i % 2 != 0)
            A.append(num + "-sin(");
        else
            A.append(num + "+sin(");
    }
    num = '0' + n;
    A.append(num);
    for (int i = 1; i <= n; i++)
        A.append(")");
    return A;
}
string S(int n)
{
    string s, num;
    int i = 0;
    for (int i = 0; i < n - 1; i++)
    {
        s.append("(");
    }
    for (int i = n; i > 1; i--)
    {
        num = '0' + i;
        s.append(A(n - i + 1) + "+" + num + ")");
    }
    s.append(A(n) + "+1");
    return s;
}
int main()
{
    cin >> n;
    cout << S(n);
    return 0;
}