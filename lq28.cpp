// 问题描述
// 　　Tom教授正在给研究生讲授一门关于基因的课程，有一件事情让他颇为头疼：一条染色体上有成千上万个碱基对，它们从0开始编号，到几百万，几千万，甚至上亿。
// 　　比如说，在对学生讲解第1234567009号位置上的碱基时，光看着数字是很难准确的念出来的。
// 　　所以，他迫切地需要一个系统，然后当他输入12 3456 7009时，会给出相应的念法：
// 　　十二亿三千四百五十六万七千零九
// 　　用汉语拼音表示为
// 　　shi er yi san qian si bai wu shi liu wan qi qian ling jiu
// 　　这样他只需要照着念就可以了。
// 　　你的任务是帮他设计这样一个系统：给定一个阿拉伯数字串，你帮他按照中文读写的规范转为汉语拼音字串，相邻的两个音节用一个空格符格开。
// 　　注意必须严格按照规范，比如说“10010”读作“yi wan ling yi shi”而不是“yi wan ling shi”，“100000”读作“shi wan”而不是“yi shi wan”，“2000”读作“er qian”而不是“liang qian”。
// 输入格式
// 　　有一个数字串，数值大小不超过2,000,000,000。
// 输出格式
// 　　是一个由小写英文字母，逗号和空格组成的字符串，表示该数的英文读法。
// 样例输入
// 1234567009
// 样例输出
// shi er yi san qian si bai wu shi liu wan qi qian ling jiu
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
//初始要输出的数
string v[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string d[6] = {"shi", "bai", "qian", "wan", "yi"};
char a[11];
//将要输出的数放在一个数组中
string res[30];

int main()
{
    cin >> a;
    int len = 0;
    int b[2] = {0};
    int length = strlen(a);
    for (int i = 0; i < length; ++i)
    {
        //转为数型
        int temp = a[length - i - 1] - '0';
        if (temp > 0)
        {
            //不为0的处理
            //四位时的处理
            if (i >= 4 && !b[i / 4 - 1])
            {
                //达到几次四位，判断wan和yi
                b[i / 4 - 1] = 1;
                res[len++] = d[i / 4 + 2];
            }
            if (i % 4 != 0)
            {
                res[len++] = d[i % 4 - 1];
            }
            //放入数字
            res[len++] = v[temp];
        }
        else
        {
            //出现0的处理，如果有“ling”，则不必再赋
            if (len > 0 && res[len - 1].compare(v[0]))
            {
                res[len++] = v[0];
            }
        }
    }
    if (!(!res[len - 1].compare(v[1]) && len > 2 && !res[len - 2].compare(d[0])))
    {
        cout << res[len - 1] << ' ';
    }
    for (int i = len - 2; i >= 0; --i)
    {
        cout << res[i] << " ";
    }
    return 0;
}