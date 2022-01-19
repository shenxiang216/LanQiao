// 问题描述
// 　　共有n种图案的印章，每种图案的出现概率相同。小A买了m张印章，求小A集齐n种印章的概率。
// 输入格式
// 　　一行两个正整数n和m
// 输出格式
// 　　一个实数P表示答案，保留4位小数。
// 样例输入
// 2 3
// 样例输出
// 0.7500
// 数据规模和约定
// 　　1≤n，m≤20
// https://blog.csdn.net/okok__TXF/article/details/121099645
#include <iostream>
#include <cmath>
using namespace std;
double dp[25][25], p;
int main()
{
    //记住是小数啊，要*1.0进行类型转换的
    int n, m;
    cin >> n >> m;
    p = 1.0 / n; //每种出现的概率
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i < j)
                dp[i][j] = 0;
            if (j == 1)
            {
                dp[i][j] = pow(p, i - 1);
            }
            else
            {
                dp[i][j] = dp[i - 1][j] * (j * 1.0 / n) + dp[i - 1][j - 1] * ((n - j + 1) * 1.0 / n);
            }
        }
    }
    // cout << "dp\n";
    // for (int i = 1; i <= m; ++i)
    // {
    //     for (int j = 1; j <= n; ++j)
    //     {
    //         printf("%.2lf  ", dp[i][j]);
    //     }
    //     cout << endl;
    // }
    printf("%.4lf  ", dp[m][n]);
    return 0;
}
