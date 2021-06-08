#include <iostream>
using namespace std;

#include "MHeap.h"


/*
template<class T>
class Node
{
	T Data;
	int next_index;//for this question
	int row;
	size_t Key;
	Node* Next;
	Node* Left;
	Node* Right;
	Node* Parent;

	template<class T> friend class MHeap;


public:
	Node();
	Node<T>(T new_d, Node<T>* left, Node<T>* right, Node<T>* parent, Node<T>* next, size_t key , int next_index , int row);
	~Node();

	bool swap(Node<T>* tmep);


};

template<class T>
bool Node<T>::swap(Node<T>* temp)
{
	if (temp && this)
	{
		T t = temp->Data;
		temp->Data = this->Data;
		this->Data = t;

		int r = temp->row;
		temp->row = this->row;
		this->row = r;

		int n = temp->next_index;
		temp->next_index = this->next_index;
		this->next_index = n;

		return true;
	}

	return false;
}

template<class T>
Node<T> ::Node<T>(T new_d, Node<T>* left, Node<T>* right, Node<T>* parent, Node<T>* next, size_t key , int next_index , int r)
{
	this->row = r;
	this->next_index = next_index;
	this->Data = new_d;
	this->Left = left;
	this->Right = right;
	this->Parent = parent;
	this->Next = next;
	this->Key = key;
	return;
}

template<class T>
Node<T>::Node<T>()
{
	this->Left = nullptr;
	this->Right = nullptr;
	this->Parent = nullptr;
	this->Next = nullptr;

	return;
}

template<class T>
Node<T>::~Node<T>()
{
	this->Next = nullptr;
	this->Left = nullptr;
	this->Right = nullptr;
	this->Parent = nullptr;
	return;
}
*/


/*
template<class T>
class MHeap
{
	Node<T>* Root;
	size_t Size;

	template<class T> friend class Node;

public:
	MHeap();
	~MHeap();
	void Destructor(Node<T>* root);
	void Insert(T data);
	void heapify_down(Node<T>* root);
	void heapify_up(Node<T>* root);
	void Insert(T data, int last_key , int r);
	T getMin();
	T Pop();
	T getRow();

	size_t size();
};
template<class T>
T MHeap<T>::getRow()
{
	return this->Root->row;
}
template<class T>
T MHeap<T>::getMin()
{
	return this->Root->Data;
}

template<class T>
size_t MHeap<T>::size()
{
	return this->Size;
}
template<class T>
T MHeap<T>::Pop()
{
	if (!this->Root)
	{
		throw "Min Heap is Null";
	}
	if (!this->Root->Next)
	{
		T del = this->Root->Data;
		this->~MHeap();
		return del;
	}
	Node<T>* temp = this->Root;
	Node<T>* temp_last = this->Root;
	T del = temp->Data;
	int next_index = temp->next_index;
	while (temp_last->Next && temp_last->Next->Next)
	{
		temp_last = temp_last->Next;
	}
	temp = temp_last->Next;
	temp->swap(this->Root);

	if (Size % 2 == 0 && temp->Parent && temp)
		temp->Parent->Left = nullptr;
	else if (Size % 2 != 0 && temp && temp->Parent)
		temp->Parent->Right = nullptr;

	temp->Parent = nullptr;
	temp = nullptr;
	delete temp;
	temp_last->Next = nullptr;
	heapify_down(this->Root);

	Size--;
	return next_index;
}

template<class T>
void MHeap<T>::heapify_down(Node<T> * root)
{
	if (!root)
		return;

	if (root->Left && root->Left->Data < root->Data)
	{
		root->swap(root->Left);
	}

	if (root->Right && root->Right->Data < root->Data)
	{
		root->swap(root->Right);
	}

	if (root->Left)
		heapify_down(root->Left);

	if (root->Right)
		heapify_down(root->Right);

	return;

}

template<class T>
void MHeap<T>::heapify_up(Node<T> * root)
{
	if (!root)
		return;

	if (root->Parent && root->Parent->Data > root->Data)
	{
		root->swap(root->Parent);
	}


	if (root->Parent)
		heapify_up(root->Parent);

	return;

}

template<class T>
void MHeap<T>::Insert(T data)
{
	Node<T>* new_node = new Node<T>(data, nullptr, nullptr, nullptr, nullptr, Size , 0 , 0);
	if (!this->Root)
	{
		Size++;
		this->Root = new_node;
		return;
	}
	Node<T>* temp = this->Root;
	Node<T>* par = this->Root;
	int key_parent = (Size - 1) / 2;

	while (temp->Next)
	{
		if (temp->Key == key_parent)
		{
			par = temp;
		}
		temp = temp->Next;
	}
	temp->Next = new_node;
	new_node->Parent = par;
	if (Size % 2 == 0)
		par->Right = new_node;
	else
		par->Left = new_node;


	heapify_up(new_node);

	Size++;
	return;
}
template<class T>
void MHeap<T>::Insert(T data , int last_key , int r)
{
	Node<T>* new_node = new Node<T>(data, nullptr, nullptr, nullptr, nullptr, Size , last_key , r);
	if (!this->Root)
	{
		Size++;
		this->Root = new_node;
		return;
	}
	Node<T>* temp = this->Root;
	Node<T>* par = this->Root;
	int key_parent = (Size - 1) / 2;

	while (temp->Next)
	{
		if (temp->Key == key_parent)
		{
			par = temp;
		}
		temp = temp->Next;
	}
	temp->Next = new_node;
	new_node->Parent = par;
	if (Size % 2 == 0)
		par->Right = new_node;
	else
		par->Left = new_node;


	heapify_up(new_node);

	Size++;
	return;
}

template<class T>
void MHeap<T>::Destructor(Node<T> * root)
{
	if (root)
	{
		Destructor(root->Right);
		Destructor(root->Left);
		root->~Node();
		return;
	}

}
template<class T>
MHeap<T>::MHeap<T>()
{
	this->Root = nullptr;
	Size = 0;

	return;
}
template<class T>
MHeap<T>::~MHeap<T>()
{
	Destructor(this->Root);

	return;
}
*/

int main()
{
	MHeap<int> m1;

	int n = 0, k = 0, input = 0;
	cin >> n >> k;
	int** arr = new int* [n];


	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[k];
		for (int j=0 ; j<k ; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i=0 ; i<n ; i++)
	{
		m1.Insert(arr[i][0] , 1 , i);
	}

	for (int i=0 ; i<n*k ; i++)
	{
		
		cout << m1.getMin() << " ";
		int row_index = m1.getRow();
		int next_index = m1.Pop();


		if (next_index<k)
		{
			m1.Insert(arr[row_index][next_index], next_index + 1, row_index);
		}
		else
		{
			m1.Insert(2147483647, row_index, next_index + 1);

		}
		

	}




	return 0;
}

