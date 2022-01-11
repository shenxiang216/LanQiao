#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.size() == s2.size())
    {
        if (s1.compare(s2) == 0)
        {
            cout << "2";
        }
        else
        {
            transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
            transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
            if (s1 == s2)
            {
                cout << "3";
            }
            else
            {
                cout << "4";
            }
        }
    }
    else
    {
        cout << "1";
    }
}