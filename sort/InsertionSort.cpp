#include <iostream>
#include <vector>
using namespace std;
void InsertionSort(vector<int> &a)
{
    int len = a.size();
    for (int i = 0,j,temp; i < len - 1; i++) //需要循环次数
    {
       j = i;
       temp = a[i+1];
       while(j>=0&&a[j]>temp){
           a[j+1] = a[j];
           j--;
       }
       a[j+1] = temp;
    }
}
int main()
{
    int a[6] = {6, 89, 85, 41, 63, 76};
    vector<int> b;
    b.insert(b.begin(), a, a + 6);
    InsertionSort(b);
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}
