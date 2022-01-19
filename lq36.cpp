#include <iostream>
#include <stdlib.h>
using namespace std;
int dp[1000][1000];
int main()
{
    int num;
    cin >> num;
    //dp数组含义：走到第i行，第j列位置时，金币的最大值
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
            cin >> dp[i][j];
    }
    //dp数组第一行赋值
    for (int i = 1; i < num; i++)
    {
        dp[0][i] = dp[0][i - 1] + dp[0][i];
    }
    //dp数组第一列赋值
    for (int i = 1; i < num; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i][0];
    }
    //因为只能向右或者向下走，所以走到第i行第j列的最大值，即为走到第i-1行第j列的值与走到第i行第j-1列的最大值与第i行第j列的值之和
    for (int i = 1; i < num; i++)
    {
        for (int j = 1; j < num; j++)
        {
            dp[i][j] = max(dp[i - 1][j] + dp[i][j], dp[i][j - 1] + dp[i][j]);
        }
    }
    // //dp数组右下角的值即为最大值
    // for (int i = 0; i < num; i++)
    // {
    //     for (int j = 0; j < num; j++)
    //         cout << dp[i][j];
    //     cout << endl;
    // }
    cout << dp[num - 1][num - 1];
    return 0;
}
