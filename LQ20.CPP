#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;
int main()
{

    int SumHuf(int);
    int num;
    int sum = 0;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    cout << SumHuf(sum) << endl;
    return 0;
}
int SumHuf(int sum)
{
    while (a.size() > 1)
    {
        int temp = 0;
        sort(a.begin(), a.end(), greater<int>());
        for (int i = 0; i < 2; i++)
        {
            temp += a.back();
            a.pop_back();
        }
        sum += temp;
        a.push_back(temp);
    }
    return sum;
}