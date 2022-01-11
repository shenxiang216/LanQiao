#include <iostream>
using namespace std;
int main()
{
    char hex_num[9];
    cin >> hex_num;
    int l; //十六进制数长度
    long long dnum = 0;
    for (l = 0; hex_num[l] != '\0'; l++)
        ;
    for (int i = l - 1; i >= 0; i--)
    { //位权展开法
        int num;
        long long weights = 1; //权值
        if ('0' <= hex_num[i] && hex_num[i] <= '9')
            num = hex_num[i] - '0';
        else if ('A' <= hex_num[i] && hex_num[i] <= 'F')
            num = hex_num[i] - 'A' + 10;
        for (int j = l - i; j > 1; j--)
            weights *= 16;
        dnum += num * weights;
    }
    cout << dnum << endl;
    return 0;
}