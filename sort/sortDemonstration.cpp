#include <iostream>
using namespace std;
const int maxsize = 100;
int num = 0; //定义全局变量，为每一趟的输出做准备
int x = 0;
template <class type>
class sortlist
{
private:
  int currentsize; //数据表中数据元素的个数
public:
  type *arr;                                               //存储数据元素的向量（排序表）
  sortlist() : currentsize(0) { arr = new type[maxsize]; } //构造函数
  sortlist(int n)
  {
    arr = new type[maxsize];
    currentsize = n;
  }
  void insert(int i, type x) { arr[i] = x; }
  ~sortlist() { delete[] arr; } //析构函数
  void swap(type &x, type &y)   //数据元素x和y交换位置
  {
    type temp = x;
    x = y;
    y = temp;
  }
  void bubblesort();                                                                                                    //冒泡排序
  void quicksort(int low, int high);                                                                                    //快速排序
  void insertionsort();                                                                                                 //直接插入排序
  void binaryinsertsort();                                                                                              //折半插入排序
  void selectsort();                                                                                                    //简单选择排序
  void heapsort();                                                                                                      //堆排序
  void mergesort(sortlist<type> &table);                                                                                //归并排序
  void filterdown(const int start);                                                                                     //建立最大堆
  void mergepass(sortlist<type> &sourcetable, sortlist<type> &mergedtable, const int len);                              //一趟归并
  void merge(sortlist<type> &sourcetable, sortlist<type> &mergedtable, const int left, const int mid, const int right); //两路归并算法
  void shellsort();                                                                                                     //希尔排序
};

template <class type> //直接插入排序
void sortlist<type>::insertionsort()
{
  type temp;
  int j;
  for (int i = 1; i <= currentsize - 1; i++)
  {
    temp = arr[i];
    j = i - 1;
    while (j >= 0 && temp < arr[j])
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
    cout << "第" << ++num << "趟排序结果为:";
    for (int t = 0; t < currentsize; t++)
      cout << arr[t] << "  ";
    cout << endl;
  }
  num = 0;
}

template <class type> //折半插入排序
void sortlist<type>::binaryinsertsort()
{
  type temp;
  int left, right;
  for (int i = 1; i < currentsize; i++)
  {
    left = 0;
    right = i - 1;
    temp = arr[i];
    while (left <= right) //找插入位置
    {
      int mid = (left + right) / 2;
      if (temp < arr[mid])
        right = mid - 1;
      else
        left = mid + 1;
    }
    for (int k = i - 1; k >= left; k--) //向后移动
    {
      arr[k + 1] = arr[k];
      arr[left] = temp;
      cout << "第" << ++num << "趟排序结果为:";
      for (int t = 0; t < currentsize; t++)
        cout << arr[t] << "  ";
      cout << endl;
    }
    num = 0;
  }
}

template <class type> //冒泡排序
void sortlist<type>::bubblesort()
{
  int i = 1;
  int finish = 0; //0表示还没有排好序
  while (i < currentsize && !finish)
  {
    finish = 1; //排序结束标志置为,假定已经排好序
    for (int j = 0; j < currentsize - i; j++)
      if (arr[j] > arr[j + 1]) //逆序
      {
        swap(arr[j], arr[j + 1]); //相邻元素交换位置
        finish = 0;
      } //排序结束标志置为,表示本趟发生了交换，说明还没有排好序
    i++;
    cout << "第" << ++num << "趟排序结果为:";
    for (int t = 0; t < currentsize; t++)
      cout << arr[t] << "  ";
    cout << endl;
  }
  num = 0;
}

template <class type>
void sortlist<type>::selectsort() //简单选择排序
{
  int k;
  for (int i = 0; i < currentsize - 1; i++)
  {
    k = i;
    for (int j = i + 1; j < currentsize; j++)
      if (arr[j] < arr[k])
        k = j;  //k 指示当前序列中最小者的位置
    if (k != i) //最小关键字的数据元素位置不等于i
      swap(arr[i], arr[k]);
    cout << "第" << ++num << "趟排序结果为:";
    for (int t = 0; t < currentsize; t++)
      cout << arr[t] << "  ";
    cout << endl;
  }
  num = 0;
}

template <class type>                             //快速排序
void sortlist<type>::quicksort(int low, int high) //在待排序区间[low,high]上，递归地进行快速排序
{
  int i = low, j = high;
  type temp = arr[low]; //取区间第一个位置为基准位置
  if (i < j)
  {
    while (i < j)
    {
      while (i < j && temp < arr[j])
        j--;
      if (i < j)
      {
        swap(arr[i], arr[j]);
        i++;
      }
      while (i < j && temp >= arr[i])
        i++;
      if (i < j)
      {
        swap(arr[i], arr[j]);
        j--;
      }
    }
    arr[i] = temp; //将基准元素就位
    cout << "第" << ++x << "趟排序结果为:";
    for (int t = 0; t < currentsize; t++)
      cout << arr[t] << "  ";
    cout << endl;
    quicksort(low, i - 1);  //在左子区间递归进行快速排序
    quicksort(i + 1, high); //在右子区间递归进行快速排序
  }
}

template <class type> //建立最大堆
void sortlist<type>::filterdown(const int start)
{                               //向下调整使从start开始到currentsize-1为止的子表成为最大堆
  int i = start, j = 2 * i + 1; //j为i的左孩子
  int tablesize = currentsize;
  type temp = arr[i];
  while (j <= currentsize - 1)
  {
    if (j < currentsize - 1 && arr[j] < arr[j + 1])
      j++; //在两个孩子中选关键字较大者
    if (temp >= arr[j])
      break;
    else
    {
      arr[i] = arr[j];
      i = j;
      j = 2 * j + 1;
    }
  }
  arr[i] = temp;
}

template <class type>
void sortlist<type>::heapsort()
{
  int tablesize = currentsize;
  for (int i = (currentsize - 2) / 2; i >= 0; i--)
    filterdown(i); //初始建堆
  for (int i = currentsize - 1; i >= 1; i--)
  {
    swap(arr[0], arr[i]); //堆顶元素和最后一个元素交换
    currentsize--;
    filterdown(0); //重建最大堆
    cout << "第" << ++num << "趟排序结果为:";
    for (int t = 0; t < tablesize; t++)
      cout << arr[t] << "  ";
    cout << endl;
  }
  num = 0;
  currentsize = tablesize;
}

template <class type>
void sortlist<type>::merge(sortlist<type> &sourcetable, sortlist<type> &mergedtable, const int left, const int mid, const int right)
{
  int i = left, j = mid + 1, k = left; //指针初始化
  //i是前一段的当前元素位置，j是后一段的当前元素位置，k是辅助数组的当前位置
  while (i <= mid && j <= right)
    if (arr[i] <= arr[j])
    {
      arr[k] = arr[i];
      i++;
      k++;
    }
    else
    {
      arr[k] = arr[j];
      j++;
      k++;
    }
  if (i <= mid)
  {
    for (int p = k, q = i; q <= mid; p++, q++)
      arr[p] = arr[q]; //把前一段复制到mergedtable
  }
  else
    for (int p = k, q = j; q <= right; p++, q++)
      arr[p] = arr[q]; //把后一段复制到mergedtable
}

template <class type>
void sortlist<type>::mergepass(sortlist<type> &sourcetable, sortlist<type> &mergedtable, const int len)
{
  int i = 0;
  while (i + 2 * len <= currentsize - 1) //表示至少有个子序列
  {
    merge(sourcetable, mergedtable, i, i + len - 1, i + 2 * len - 1);
    i += 2 * len;
  }
  if (i + len <= currentsize - 1) //若只有最后两个子序列
    merge(sourcetable, mergedtable, i, i + len - 1, currentsize - 1);
  else //若只有最后一个子序列
    for (int j = i; j <= currentsize - 1; j++)
      arr[j] = arr[j];
  if (len <= currentsize - 1)
  {
    if (num < currentsize)
    {
      cout << "第" << ++num << "趟排序结果为:";
      for (int t = 0; t < currentsize; t++)
        cout << arr[t] << "  ";
      cout << endl;
    }
  }
}

template <class type>
void sortlist<type>::mergesort(sortlist<type> &table)
{ //按数据元素关键字非递减的顺序对排序表table中数据元素进行递归排序
  sortlist<type> temptable;
  int len = 1;
  while (len < currentsize)
  {
    mergepass(table, temptable, len);
    len *= 2;
    mergepass(temptable, table, len);
    len *= 2;
  }
  num = 0;
}

template <class type>
void sortlist<type>::shellsort()
{
  int len = currentsize;
  for (int gap = len / 2; gap > 0; gap /= 2)
  {
    for (int i = 0; i < gap; i++)
    {

      for (int j = i + gap, temp, preIndex; j < len; j += gap)
      {                     //temp作为哨兵
        temp = arr[j];      //保存哨兵
        preIndex = j - gap; //将要对比的编号
        while (preIndex >= 0 && arr[preIndex] > temp)
        {
          arr[preIndex + gap] = arr[preIndex]; //被替换
          preIndex -= gap;                     //向下走一步
        }
        arr[preIndex + gap] = temp; //恢复被替换的值
      }
      cout << "第" << ++num << "趟排序结果为:";
      for (int t = 0; t < len; t++)
        cout << arr[t] << "  ";
      cout << endl;
    }
  }
  num = 0;
}

int main() //主函数
{
  cout << "                                                            " << endl;
  cout << "***********************************************************************" << endl;
  cout << "                          排序问题                        " << endl;
  cout << "***********************************************************************"
       << endl
       << endl
       << endl;
  int c = 1;
  char ch, cc;
  int n1 = 0;
  while (c != 0)
  {
    cout << "\n======================================================================="
         << endl;
    cout << "======================可供选择的排序方法==============================" << endl;
    cout << "             1    直接插入排序          2    折半插入排序     " << endl;
    cout << "             3    冒泡排序              4    简单选择排序     " << endl;
    cout << "             5    快速排序              6    堆排序           " << endl;
    cout << "             7    归并排序              8    希尔排序     " << endl;
    cout << "                           0    退出排序程序                 " << endl;
    cout << "=======================================================================" << endl;
    cout << "\n   请输入您需要的排序种类:";
    cin >> ch;
    if (ch == '0')
    {
      cout << "   您已成功退出该系统!" << endl;
      system("pause");
      return 0;
    }
    int n, number;
    if (ch >= '0' && ch <= '8')
    {
      cout << "\n   输入您要进行排序的数的个数：";
      cin >> n;
      cout << "\n   请输入" << n << "个数：";
      sortlist<int> table(n);
      for (int i = 0; i < n; i++)
      {
        cin >> number;
        table.insert(i, number);
      }
      switch (ch)
      {
      case '1':
        cout << "\n   *******您选择的是直接插入排序*******\n"
             << endl;
        table.insertionsort();
        break;
        system("pause");
        break;
      case '2':
        cout << "\n   *******您选择的是折半插入排序*******\n"
             << endl;
        table.binaryinsertsort();
        break;
        system("pause");
        break;
      case '3':
        cout << "\n   *******您选择的是冒泡排序*******\n"
             << endl;
        table.bubblesort();
        break;
        system("pause");
        break;
      case '4':
        cout << "\n   *******您选择的是简单选择排序*******\n"
             << endl;
        table.selectsort();
        break;
        system("pause");
        break;
      case '5':
        cout << "\n   *******您选择的是快速排序*******\n"
             << endl;
        table.quicksort(0, n);
        break;
        system("pause");
        break;
      case '6':
        cout << "\n   *******您选择的是堆排序*******\n"
             << endl;
        table.heapsort();
        break;
        system("pause");
        break;
      case '7':
        cout << "\n   *******您选择的是归并排序*******\n"
             << endl;
        table.mergesort(table);
        break;
        system("pause");
        break;
      case '8':
        cout << "\n   *******您选择的是希尔排序*******\n"
             << endl;
        table.shellsort();
        break;
        system("pause");
        break;
      }
    }
  }
  system("pause");
  return 0;
}
