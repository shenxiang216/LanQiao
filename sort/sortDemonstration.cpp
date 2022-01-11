#include <iostream>
using namespace std;
const int maxsize = 100;
int num = 0; //����ȫ�ֱ�����Ϊÿһ�˵������׼��
int x = 0;
template <class type>
class sortlist
{
private:
  int currentsize; //���ݱ�������Ԫ�صĸ���
public:
  type *arr;                                               //�洢����Ԫ�ص������������
  sortlist() : currentsize(0) { arr = new type[maxsize]; } //���캯��
  sortlist(int n)
  {
    arr = new type[maxsize];
    currentsize = n;
  }
  void insert(int i, type x) { arr[i] = x; }
  ~sortlist() { delete[] arr; } //��������
  void swap(type &x, type &y)   //����Ԫ��x��y����λ��
  {
    type temp = x;
    x = y;
    y = temp;
  }
  void bubblesort();                                                                                                    //ð������
  void quicksort(int low, int high);                                                                                    //��������
  void insertionsort();                                                                                                 //ֱ�Ӳ�������
  void binaryinsertsort();                                                                                              //�۰��������
  void selectsort();                                                                                                    //��ѡ������
  void heapsort();                                                                                                      //������
  void mergesort(sortlist<type> &table);                                                                                //�鲢����
  void filterdown(const int start);                                                                                     //��������
  void mergepass(sortlist<type> &sourcetable, sortlist<type> &mergedtable, const int len);                              //һ�˹鲢
  void merge(sortlist<type> &sourcetable, sortlist<type> &mergedtable, const int left, const int mid, const int right); //��·�鲢�㷨
  void shellsort();                                                                                                     //ϣ������
};

template <class type> //ֱ�Ӳ�������
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
    cout << "��" << ++num << "��������Ϊ:";
    for (int t = 0; t < currentsize; t++)
      cout << arr[t] << "  ";
    cout << endl;
  }
  num = 0;
}

template <class type> //�۰��������
void sortlist<type>::binaryinsertsort()
{
  type temp;
  int left, right;
  for (int i = 1; i < currentsize; i++)
  {
    left = 0;
    right = i - 1;
    temp = arr[i];
    while (left <= right) //�Ҳ���λ��
    {
      int mid = (left + right) / 2;
      if (temp < arr[mid])
        right = mid - 1;
      else
        left = mid + 1;
    }
    for (int k = i - 1; k >= left; k--) //����ƶ�
    {
      arr[k + 1] = arr[k];
      arr[left] = temp;
      cout << "��" << ++num << "��������Ϊ:";
      for (int t = 0; t < currentsize; t++)
        cout << arr[t] << "  ";
      cout << endl;
    }
    num = 0;
  }
}

template <class type> //ð������
void sortlist<type>::bubblesort()
{
  int i = 1;
  int finish = 0; //0��ʾ��û���ź���
  while (i < currentsize && !finish)
  {
    finish = 1; //���������־��Ϊ,�ٶ��Ѿ��ź���
    for (int j = 0; j < currentsize - i; j++)
      if (arr[j] > arr[j + 1]) //����
      {
        swap(arr[j], arr[j + 1]); //����Ԫ�ؽ���λ��
        finish = 0;
      } //���������־��Ϊ,��ʾ���˷����˽�����˵����û���ź���
    i++;
    cout << "��" << ++num << "��������Ϊ:";
    for (int t = 0; t < currentsize; t++)
      cout << arr[t] << "  ";
    cout << endl;
  }
  num = 0;
}

template <class type>
void sortlist<type>::selectsort() //��ѡ������
{
  int k;
  for (int i = 0; i < currentsize - 1; i++)
  {
    k = i;
    for (int j = i + 1; j < currentsize; j++)
      if (arr[j] < arr[k])
        k = j;  //k ָʾ��ǰ��������С�ߵ�λ��
    if (k != i) //��С�ؼ��ֵ�����Ԫ��λ�ò�����i
      swap(arr[i], arr[k]);
    cout << "��" << ++num << "��������Ϊ:";
    for (int t = 0; t < currentsize; t++)
      cout << arr[t] << "  ";
    cout << endl;
  }
  num = 0;
}

template <class type>                             //��������
void sortlist<type>::quicksort(int low, int high) //�ڴ���������[low,high]�ϣ��ݹ�ؽ��п�������
{
  int i = low, j = high;
  type temp = arr[low]; //ȡ�����һ��λ��Ϊ��׼λ��
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
    arr[i] = temp; //����׼Ԫ�ؾ�λ
    cout << "��" << ++x << "��������Ϊ:";
    for (int t = 0; t < currentsize; t++)
      cout << arr[t] << "  ";
    cout << endl;
    quicksort(low, i - 1);  //����������ݹ���п�������
    quicksort(i + 1, high); //����������ݹ���п�������
  }
}

template <class type> //��������
void sortlist<type>::filterdown(const int start)
{                               //���µ���ʹ��start��ʼ��currentsize-1Ϊֹ���ӱ��Ϊ����
  int i = start, j = 2 * i + 1; //jΪi������
  int tablesize = currentsize;
  type temp = arr[i];
  while (j <= currentsize - 1)
  {
    if (j < currentsize - 1 && arr[j] < arr[j + 1])
      j++; //������������ѡ�ؼ��ֽϴ���
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
    filterdown(i); //��ʼ����
  for (int i = currentsize - 1; i >= 1; i--)
  {
    swap(arr[0], arr[i]); //�Ѷ�Ԫ�غ����һ��Ԫ�ؽ���
    currentsize--;
    filterdown(0); //�ؽ�����
    cout << "��" << ++num << "��������Ϊ:";
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
  int i = left, j = mid + 1, k = left; //ָ���ʼ��
  //i��ǰһ�εĵ�ǰԪ��λ�ã�j�Ǻ�һ�εĵ�ǰԪ��λ�ã�k�Ǹ�������ĵ�ǰλ��
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
      arr[p] = arr[q]; //��ǰһ�θ��Ƶ�mergedtable
  }
  else
    for (int p = k, q = j; q <= right; p++, q++)
      arr[p] = arr[q]; //�Ѻ�һ�θ��Ƶ�mergedtable
}

template <class type>
void sortlist<type>::mergepass(sortlist<type> &sourcetable, sortlist<type> &mergedtable, const int len)
{
  int i = 0;
  while (i + 2 * len <= currentsize - 1) //��ʾ�����и�������
  {
    merge(sourcetable, mergedtable, i, i + len - 1, i + 2 * len - 1);
    i += 2 * len;
  }
  if (i + len <= currentsize - 1) //��ֻ���������������
    merge(sourcetable, mergedtable, i, i + len - 1, currentsize - 1);
  else //��ֻ�����һ��������
    for (int j = i; j <= currentsize - 1; j++)
      arr[j] = arr[j];
  if (len <= currentsize - 1)
  {
    if (num < currentsize)
    {
      cout << "��" << ++num << "��������Ϊ:";
      for (int t = 0; t < currentsize; t++)
        cout << arr[t] << "  ";
      cout << endl;
    }
  }
}

template <class type>
void sortlist<type>::mergesort(sortlist<type> &table)
{ //������Ԫ�عؼ��ַǵݼ���˳��������table������Ԫ�ؽ��еݹ�����
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
      {                     //temp��Ϊ�ڱ�
        temp = arr[j];      //�����ڱ�
        preIndex = j - gap; //��Ҫ�Աȵı��
        while (preIndex >= 0 && arr[preIndex] > temp)
        {
          arr[preIndex + gap] = arr[preIndex]; //���滻
          preIndex -= gap;                     //������һ��
        }
        arr[preIndex + gap] = temp; //�ָ����滻��ֵ
      }
      cout << "��" << ++num << "��������Ϊ:";
      for (int t = 0; t < len; t++)
        cout << arr[t] << "  ";
      cout << endl;
    }
  }
  num = 0;
}

int main() //������
{
  cout << "                                                            " << endl;
  cout << "***********************************************************************" << endl;
  cout << "                          ��������                        " << endl;
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
    cout << "======================�ɹ�ѡ������򷽷�==============================" << endl;
    cout << "             1    ֱ�Ӳ�������          2    �۰��������     " << endl;
    cout << "             3    ð������              4    ��ѡ������     " << endl;
    cout << "             5    ��������              6    ������           " << endl;
    cout << "             7    �鲢����              8    ϣ������     " << endl;
    cout << "                           0    �˳��������                 " << endl;
    cout << "=======================================================================" << endl;
    cout << "\n   ����������Ҫ����������:";
    cin >> ch;
    if (ch == '0')
    {
      cout << "   ���ѳɹ��˳���ϵͳ!" << endl;
      system("pause");
      return 0;
    }
    int n, number;
    if (ch >= '0' && ch <= '8')
    {
      cout << "\n   ������Ҫ������������ĸ�����";
      cin >> n;
      cout << "\n   ������" << n << "������";
      sortlist<int> table(n);
      for (int i = 0; i < n; i++)
      {
        cin >> number;
        table.insert(i, number);
      }
      switch (ch)
      {
      case '1':
        cout << "\n   *******��ѡ�����ֱ�Ӳ�������*******\n"
             << endl;
        table.insertionsort();
        break;
        system("pause");
        break;
      case '2':
        cout << "\n   *******��ѡ������۰��������*******\n"
             << endl;
        table.binaryinsertsort();
        break;
        system("pause");
        break;
      case '3':
        cout << "\n   *******��ѡ�����ð������*******\n"
             << endl;
        table.bubblesort();
        break;
        system("pause");
        break;
      case '4':
        cout << "\n   *******��ѡ����Ǽ�ѡ������*******\n"
             << endl;
        table.selectsort();
        break;
        system("pause");
        break;
      case '5':
        cout << "\n   *******��ѡ����ǿ�������*******\n"
             << endl;
        table.quicksort(0, n);
        break;
        system("pause");
        break;
      case '6':
        cout << "\n   *******��ѡ����Ƕ�����*******\n"
             << endl;
        table.heapsort();
        break;
        system("pause");
        break;
      case '7':
        cout << "\n   *******��ѡ����ǹ鲢����*******\n"
             << endl;
        table.mergesort(table);
        break;
        system("pause");
        break;
      case '8':
        cout << "\n   *******��ѡ�����ϣ������*******\n"
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
