#include <iostream>
using namespace std;
int main()
{
    for (int i = 0; i < 32; ++i)
    {
        int a[5] = {0};
        int temp = i;
        int index = 4;
        while (temp >= 1)
        {
            a[index--] = temp % 2;
            temp = temp / 2;
        }
        for (int idx = 0; idx < 5; ++idx)
        {
            cout << a[idx];
        }
        cout<<endl;
    }
    return 0;
}