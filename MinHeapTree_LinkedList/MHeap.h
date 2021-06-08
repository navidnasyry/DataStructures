#ifndef MHEAP_SDFFD
#define MHEAP_SDFFD


#include "Node.h"

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
	T Pop();
	T getMin();
	size_t size();
	
};
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
	T del= temp->Data;
	while (temp_last->Next&&temp_last->Next->Next)
	{
		temp_last = temp_last->Next;
	}
	temp = temp_last->Next;
	temp->swap(this->Root);

	if (Size % 2 == 0 && temp->Parent && temp)
		temp->Parent->Left = nullptr;
	else if(Size % 2 != 0 && temp && temp->Parent )
		temp->Parent->Right = nullptr;

	temp->Parent = nullptr;
	temp = nullptr;
	delete temp;
	temp_last->Next = nullptr;
	heapify_down(this->Root);

	Size--;
	return del;
}

template<class T>
void MHeap<T>::heapify_down(Node<T>* root)
{
	if (!root)
		return;
	
	if (root->Left && root->Left->Data < root->Data )
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
void MHeap<T>::heapify_up(Node<T>* root)
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
	Node<T>* new_node = new Node<T>(data,nullptr, nullptr, nullptr, nullptr, Size);
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
void MHeap<T>::Destructor(Node<T>* root)
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











#endif