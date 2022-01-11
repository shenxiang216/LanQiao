#include <iostream>
#define M 10007
using namespace std;
int arr[1000000];
int main()
{
    int n;
    cin >> n;
    arr[0] = 1;
    arr[1] = 1;
    if (n == 1 || n == 2)
    {
        arr[n - 1] = 1;
    }
    for (int a = 2; a <= n - 1; a++)
    {
        arr[a] = (arr[a - 1] + arr[a - 2]) % M;
    }
    cout << arr[n - 1];
    return 0;
}
