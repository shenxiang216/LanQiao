# C/C++输入一行每隔一个空格一个数据

## 1. 已知数据个数

题设让先输入数据个数，再另起一行，每隔一个空格输入一个整数。程序如下：

int N;
int nArr[100];
cin>>N; //如果是 C 语言，这里就是 scanf("%d",&N)
for(int i=0;i<N;i++)
{
cin>>nArr[i]; //每遇到空格读入一个流 int 数据,如果是 C 语言，这里就是 scanf("%d",nArr+i)
}

## 2. 未知数据个数

题设仅让输入一行数据，空格隔开，并不知道数据个数，那怎么编程呢？
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
int nArr[100];
char c;
int i=0;
while((c=getchar())!='\n') //流中一个字符一个字符判断，直到换行，输入结束
{
if(c != ' ')  
 {
ungetc(c,stdin);//如果字符 c 不是空格，就要将 c 字符还回到流中，不然造成数据读取错误
cin>>nArr[i++];//流输入会将第一个数据全读入，直到遇到空格
}
}
return 0;
}

当你输入一行完成后，程序才会进入 while 中，一一根据流判断每个字符。当判断起头不是空格，cin 会将直到下个空格前的整个数据赋给 int 类型。这块巧妙应用了 ungetc()函数返回字符到流中的功能。

# C++ 标准输出如何控制小数点后位数

```
#include <iostream>
#include <iomanip>
using namespace std;

int main( void )
{
    const double value = 12.3456789;

    cout << value << endl; // 默认以6精度，所以输出为 12.3457
    cout << setprecision(4) << value << endl; // 改成4精度，所以输出为12.35
    cout << setprecision(8) << value << endl; // 改成8精度，所以输出为12.345679
    cout << fixed << setprecision(4) << value << endl; // 加了fixed意味着是固定点方式显示，所以这里的精度指的是小数位，输出为12.3457
    cout << value << endl; // fixed和setprecision的作用还在，依然显示12.3457
    cout.unsetf( ios::fixed ); // 去掉了fixed，所以精度恢复成整个数值的有效位数，显示为12.35
    cout << value << endl;
    cout.precision( 6 ); // 恢复成原来的样子，输出为12.3457
    cout << value << endl;
}
```
# C++ 排序函数sort使用
1.对int数组排序

sort(a,a+a.size());

2.对vector排序

sort(A.begin(),A.end());

2.对对vector降序排列

sort(A.begin(),A.end(),greater<int>());//降序排列

sort(A.rbegin(),A.rend());


# C++ 头文件cstring,string.h,string 三者的区别
//c版头文件
#include <string.h>   //不可以定义string s；可以用到strcpy等函数

//c++版头文件
include <cstring>     //不可以定义string s；可以用到strcpy等函数
using   namespace  std;

//c++版头文件
#include <string>     //可以定义string s；不可以用到strcpy等函数
using   namesapce  std;

**重点内容**
//一般正确的使用方法
#include  <string.h>  
#include  <string>  
using  namespace  std;  

或者  
#include  <cstring>  
#include  <string> 
using  namespace  std; 

# C++ 字符串大小写转换

注意需要include的库

(1)algorithm库的transform函数

#include <algorithm>
#include <string>

string str;
//转小写
transform(str.begin(),str.end(),str.begin(),::tolower);
//转大写
transform(str.begin(),str.end(),str.begin(),::toupper);
(2)标准库的tolower(),toupper()

#include <string>

string a;
//转小写
for (int i=0;i<a.length();++i)
      a[i]=tolower(a[i]);
//转大写
for (int i=0;i<a.length();++i)
      a[i]=toupper(a[i]);
(2)利用ASCII码

#include <string>

string a;
//转小写 +32
for (int i=0;i<a.length();++i)
      if(s[i]>='A'&&s[i]<='Z')
            s[i]+=32;
//转大写 -32
for (int i=0;i<a.length();++i)
      if(s[i]>='a'&&s[i]<='z')
            s[i]-=32;

# 1<<n
1先转成二进制  在左移n位  然后补0
比如 1<<2     1的二进制为 0000 0001   左移2位  0000 0100.
n=1 即 1*2  ， n=2 既1*2*2 ，n=3 既1*2*2*2 
就是进行二进制的翻倍。
二进制每左移一位就是*2，两位就是*2*2,三位就是*2*2*2.
1>>n就是1右移n位
n>>1就是n右移1位
1<<n就是1左移n位
n<<1就是n左移1位
int m=1<<n
就是m的值为把1左移n个二进制位的值
注意是在二进制下

# i &(1<< j )
1<< i 就是左移 i 位，得到的是2的 i 次方

例如 1<<2

00000001   ------>    00000100    ------>2的2次方 = 4   

i &(1<< j )就是将左移 j 位的1与 i 进行按位与

例如  5 & (1<<2)

5 转换为二进制数是 0101

1<<2  得到的是 0100

将 0101 与 0100 进行按位与

0    1    0    1     

|      |     |     |       -->     0&0=0 , 1&1=1 , 0&0=0 , 1&0 = 0

0    1    0    0      得到的数就是0100  =  4 ≠ 0