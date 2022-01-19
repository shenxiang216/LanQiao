// 问题描述
// 　　给定一个1～N的排列a[i]，每次将相邻两个数相加，得到新序列，再对新序列重复这样的操作，显然每次得到的序列都比上一次的序列长度少1，最终只剩一个数字。
// 　　例如:
// 　　3 1 2 4
// 　　4 3 6
// 　　7 9
// 　　16
// 　　现在如果知道N和最后得到的数字sum，请求出最初序列a[i]，为1～N的一个排列。若有多种答案，则输出字典序最小的那一个。数据保证有解。
// 输入格式
// 　　第1行为两个正整数n，sum
// 输出格式
// 　　一个1～N的一个排列
// 样例输入
// 4 16
// 样例输出
// 3 1 2 4
// 数据规模和约定
// 　　0<n<=10

/*
算法训练 数字游戏
思路：
	使用do{}while(next_permutation(a,a+n))函数将数组当中的数按照从小到大的字典序进行排列
	然后定义一个判断的数字，当sum算到随后的和为输入的那个数的时候判断的数字就改变
	终止循环，否则循环到最后一个字典序最大的数组
	如果判断条件对了，就输出这个数组，如果判断条件错了就不输出
*/

#include <iostream>
#include <iomanip>
#include <climits>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int main()
{

    int a[20], b[20];
    int k = 0, j;
    int n, sum;
    cin >> n >> sum;
    j = n;
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    do
    {

        for (int i = 0; i < n; i++)
        {

            b[i] = a[i];
        }
        while (j > 1)
        {

            for (int i = 0; i < n - 1; i++)
            {

                b[i] = b[i] + b[i + 1];
            }
            j--;
        }
        j = n;
        if (b[0] == sum)
        {

            k = 1;
            break;
        }
    } while (next_permutation(a, a + n));
    if (k == 1)
    {

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
    return 0;
}
