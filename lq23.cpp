// 问题描述
// 　　回形取数就是沿矩阵的边取数，若当前方向上无数可取或已经取过，则左转90度。一开始位于矩阵左上角，方向向下。
// 输入格式
// 　　输入第一行是两个不超过200的正整数m, n，表示矩阵的行和列。接下来m行每行n个整数，表示这个矩阵。
// 输出格式
// 　　输出只有一行，共mn个数，为输入矩阵回形取数得到的结果。数之间用一个空格分隔，行末不要有多余的空格。
// 样例输入
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9
// 样例输出
// 1 4 7 8 9 6 3 2 5
// 样例输入
// 3 2
// 1 2
// 3 4
// 5 6
// 样例输出
// 1 3 5 6 4 2
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    int a[200][200];
    for (int i = 0; i < m; i++) //二维数组输入
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    int num = 0;
    int i = 0, j = 0;
    int flag = 1;                                   //flag代表方向
    int aflag = m, bflag = n, cflag = 0, dflag = 1; //记录每一个方向的最后一个位置
    vector<int> b;                                  //向量来记录数组输出顺序
    while (num != m * n)
    {
        b.push_back(a[i][j]);
        if (flag == 1)
        {
            if (i < aflag - 1)
                i++;
            else
            {
                flag = 2;
                j++;
                aflag--;
            }
            num++;
            continue;
        }
        if (flag == 2)
        {
            if (j < bflag - 1)
                j++;
            else
            {
                flag = 3;
                i--;
                bflag--;
            }
            num++;
            continue;
        }
        if (flag == 3)
        {
            if (i > cflag)
                i--;
            else
            {
                flag = 4;
                j--;
                cflag++;
            }
            num++;
            continue;
        }
        if (flag == 4)
        {
            if (j > dflag)
                j--;
            else
            {
                flag = 1;
                i++;
                dflag++;
            }
            num++;
            continue;
        }
    }
    for (int i = 0; i < b.size() - 1; i++)
        cout << b[i] << " ";
    cout << b[b.size() - 1];
    return 0;
}