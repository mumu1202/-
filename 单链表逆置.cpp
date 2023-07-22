#include<iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename DataType>
struct Node
{
	DataType data;
	Node<DataType>* next;
};

template <typename DataType>
class LinkList
{
public:
	LinkList(DataType a[], int n);
	void PrintList();
	void reverse();
private:
	Node<DataType>* first;
};

template <typename DataType>
LinkList<DataType>::LinkList(DataType a[], int n)
{
	first = new Node<DataType>;
	first->next = nullptr;
	for (int i = 0;i < n;i++)
	{
		Node<DataType>* s = nullptr;

		s = new Node<DataType>;s->data = a[i];

		s->next = first->next;first->next = s;
	}
}

template <typename DataType>
void LinkList<DataType>::PrintList()
{
	Node<DataType>* p = first->next;
	while (p != nullptr)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

template <typename DataType>
void LinkList<DataType>::reverse()
{
	Node<DataType>* p = first, * q = nullptr;
	p = first->next;
	first->next = nullptr;
	q = p->next;
	while (p)
	{
		p->next = first->next;
		first->next = p;
		p = q;
		if (q)
			q = q->next;
	}
}

int main()
{
	int n, a[100] = {};
	cin >> n;
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
	}
	else
	{
		return 0;
	}
	LinkList<int> L{ a,n };
	L.PrintList();

	return 0;
}


