#include <iostream>
#include <cmath>
using namespace std;

int n;                  //皇后数目
int a[8][8];            //棋盘
int white[8], black[8]; //white白皇后位置，black黑皇后位置
int count = 0;          //不同放置情况计数

void blackq(int pos) //黑色皇后放置
{
    for (int i = 0; i < pos - 1; i++)
    {
        int judge = black[pos - 1] - black[i];         // 上一个位置与之前所有位置的行之差，用于判断
        if (judge == 0 || abs(judge) == (pos - 1 - i)) // 在同一列，或行、列之差绝对值相等
            return;
    }

    if (pos == n)
    {
        count++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[pos][i] && white[pos] != i)
        { // 判断此位置是否能放皇后，且此位置是否已放白皇后
            black[pos] = i;
            blackq(pos + 1); //判断此位置能否放皇后，能则继续递归，否则返回，回溯测下一个
        }
    }
}

void whiteq(int pos) //白色皇后放置，第pos行，也就是第pos+1个白皇后
{
    for (int i = 0; i < pos - 1; i++)
    {
        int judge = white[pos - 1] - white[i];         // 上一个位置与之前所有位置的行之差，用于判断
        if (judge == 0 || abs(judge) == (pos - 1 - i)) // 在同一列，或行、列之差绝对值相等
            return;
    }

    if (pos == n)
    { //已排好所有白皇后，开始排黑皇后
        blackq(0);
        return;
    }

    for (int i = 0; i < n; i++)
    { // i 对应第i列
        if (a[pos][i])
        { // 判断此位置是否能放皇后
            white[pos] = i;
            whiteq(pos + 1); //判断此位置能否放皇后，能则继续递归，否则返回，回溯测下一个
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    whiteq(0);
    cout << count << endl;
    return 0;
}
