#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, arr[n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
   for (int i = 0, j, temp; i < n - 1; i++) //需要循环次数
    {
        j = i;
        temp = arr[i + 1];
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    cout << arr[0];
    for (int i = 1; i < n; i++)
    {
        cout << " " << arr[i];
    }
    vector<int> v;
    v.push_back(1);
    for(int i = 0;i<v.size();i++){
        cout<<v[i];
    }
    return 0;
}
