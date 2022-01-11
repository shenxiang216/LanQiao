#include <iostream>
#include <string>
using namespace std;

int main()
{
    //小于24的数组
    string num[25] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                      "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
                      "nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four"};
    //十分位的数组
    string dicimal[6] = {"", "", "twenty", "thirty", "forty", "fifty"};
    int h = 0; //时
    int m = 0; //分
    cin >> h >> m;
    cout << num[h] << " ";
    if (m == 0)
    {
        cout << "o'clock";
    }
    else if (m > 0 && m < 20)
    {
        cout << num[m];
    }
    else if (m >= 20 && m < 60)
    {
        cout << dicimal[m / 10] << " " << num[m % 10];
    }
    return 0;
}