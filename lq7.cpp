// 问题描述
// 　　1221是一个非常特殊的数，它从左边读和从右边读是一样的，编程求所有这样的四位十进制数。
// 输出格式
// 　　按从小到大的顺序输出满足条件的四位十进制数。
#include <iostream>
using namespace std;
int main()
{
    for (int n = 1000; n < 10000; n++)
    {
        int a = n / 1000;
        int b = (n - a * 1000) / 100;
        int c = (n - a * 1000 - b * 100) / 10;
        int d = (n - a * 1000 - b * 100) % 10;
        if (a == d && b == c)
        {
            cout << n << endl;
        }
    }
    return 0;
}