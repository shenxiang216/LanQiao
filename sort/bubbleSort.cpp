#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int> &a)
{
    int len = a.size();
    for (int i = 0; i < len - 1; i++) //需要循环次数
    {
        for (int j = 0; j < len - 1 - i; j++) //每次需要比较个数
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]); //不满足偏序，交换
            }
        }
    }
}
int main()
{
    int a[6] = {6,89,85,41,63,76};
    vector<int> b;
    b.insert(b.begin(), a, a+6);
    bubbleSort(b);
    for(int i = 0;i<b.size();i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
