#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int> &a)
{
    int len = a.size();
    for (int i = 0, minIndex; i < len - 1; i++) //需要循环次数
    {
        minIndex = i;                        // 最小小标
        for (int j = 0; j < len - 1 - i; j++) // 访问未排序的元素
        {
            if (a[j] > a[minIndex])
            {
                minIndex = j; //找到最小的
            }
            swap(a[i],a[minIndex]);
        }
    }
}
int main()
{
    int a[6] = {6, 89, 85, 41, 63, 76};
    vector<int> b;
    b.insert(b.begin(), a, a + 6);
    selectionSort(b);
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}
