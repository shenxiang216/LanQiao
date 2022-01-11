#include <iostream>
using namespace std;
int main()
{
    int n, arr[10000], temp = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max = arr[0], min = arr[0];
    for (int i = 0; i < n; i++)
    {
        temp += arr[i];
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    cout << max << endl;
    cout << min << endl;
    cout << temp << endl;
    return 0;
}