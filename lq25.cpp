// 问题描述
// 　　有n（2≤n≤20）块芯片，有好有坏，已知好芯片比坏芯片多。
// 　　每个芯片都能用来测试其他芯片。用好芯片测试其他芯片时，能正确给出被测试芯片是好还是坏。而用坏芯片测试其他芯片时，会随机给出好或是坏的测试结果（即此结果与被测试芯片实际的好坏无关）。
// 　　给出所有芯片的测试结果，问哪些芯片是好芯片。
// 输入格式
// 　　输入数据第一行为一个整数n，表示芯片个数。
// 　　第二行到第n+1行为n*n的一张表，每行n个数据。表中的每个数据为0或1，在这n行中的第i行第j列（1≤i, j≤n）的数据表示用第i块芯片测试第j块芯片时得到的测试结果，1表示好，0表示坏，i=j时一律为1（并不表示该芯片对本身的测试结果。芯片不能对本身进行测试）。
// 输出格式
// 　　按从小到大的顺序输出所有好芯片的编号
// 样例输入
// 3
// 1 0 1
// 0 1 0
// 1 0 1
// 样例输出
// 1 3
// 思路：因为，题目中说到好芯片的数量比坏芯片的数量多，因此只要判断每一个芯片的合格次数大于n/2即可。
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <string>
#include <cmath>
using namespace std;

const int N = 22;
int main()
{
    int n;
    cin >> n;
    int a[N][N];
    int good[N];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (a[i][j])
            {
                sum++;
            }
        }
        //如果这个芯片测试的好芯片比坏芯片多，这个芯片才可能是好芯片，记录下来
        if (sum > n / 2)
        {
            good[k++] = i;
        }
    }
    //假设这些可能的好芯片里面全是好芯片
    int ans[N] = {0}; //记录第i个芯片被测试成好芯片的次数
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[good[i]][j] == 1)
                ans[j]++;
        }
    }
    for (int i = 0; i < n; i++) //如果被测试成好芯片的次数大于一半，就肯定是好芯片
        if (ans[i] > n / 2)
            cout << i + 1 << " ";
}
