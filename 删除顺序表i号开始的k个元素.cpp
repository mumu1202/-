#include <iostream>
using namespace std;

#define MaxSize 100

template <class DataType>
class SeqList
{
public:
    SeqList(int a[], int n);
    void remove_k(int i, int k);
    void PrintList();
private:
    DataType data[MaxSize];
    int length;
};

template <class DataType>
SeqList<DataType>::SeqList(int a[], int n)
{
    if (n > MaxSize)throw "�����Ƿ�";
    for (int i = 0;i < n;i++)
    {
        data[i] = a[i];
    }
    length = n;
}
template <class DataType>
void SeqList<DataType>::remove_k(int i, int k)
{
    if ((i <= 0) || ( i > 10) || (k==0)||(i + k > 11))
    {
        cout << "error";
        exit(0);
    }

    for (int s = 0;s < k;s++)
    {
        for (int j = i;j < length;j++)
        {
            data[j - 1] = data[j];
        }
        length--;
    }
}
template <class DataType>
void SeqList<DataType>::PrintList()
{
    for (int i = 0;i < length;i++)
    {
        cout << data[i]<<" ";
    }
}

int main()
{

    int a, b;
    int r[10] = { 10,9,8,7,6,5,4,3,2,1 };
    SeqList<int> L{ r,10 };
    cin >> a >> b;
    L.remove_k(a, b);
    L.PrintList();
}


  