#include <iostream>
using namespace std;

#define MaxSize 100

template <class DataType>
class SeqList
{
public:
    SeqList(int a[], int n);
    void Insert(int i);
    void PrintList();
private:
    DataType data[MaxSize];
    int length;
};

template <class DataType>
SeqList<DataType>::SeqList(int a[], int n)
{
    if (n > MaxSize)throw "参数非法";
    for (int i = 0;i < n;i++)
    {
        data[i] = a[i];
    }
    length = n;
}
template <class DataType>
void SeqList<DataType>::Insert(int i)
{
    if (i <= data[0])
    {
        for (int k = length;k >= 0;k--)
        {
            data[k] = data[k - 1];
        }
        data[0] = i;
        length++;
    }
    else if (i >= data[length - 1])
    {
        data[length] = i;
        length++;
    }
    else
    {
        for (int j = 0;j < length - 1;j++)
        {
            if (data[j]<= i && data[j + 1] >= i)
            {
                for (int k = length;k >= j+1;k--)
                {
                    data[k] = data[k - 1];
                }
                data[j+1] = i;
                length++;
                break;
            }
        }
    }
}
template <class DataType>
void SeqList<DataType>::PrintList()
{
    for (int i = 0;i < length;i++)
    {
        cout << data[i] << " ";
    }
}

int main()
{
    int a;
    int r[10] = { 1,3,5,7,9,11,13,15,17,19 };
    SeqList<int> L{ r,10 };
    cin >> a;
    L.Insert(a);
    L.PrintList();
}
