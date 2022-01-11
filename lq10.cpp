#include <iostream>
using namespace std;
int main()
{
    int n, arr[n], a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> a;
    for (int i = 0; i < n; i++)
    {
        if (a == arr[i])
        {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}