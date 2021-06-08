#ifndef NODE_SDFFD
#define NODE_SDFFD


template<class T>
class Node
{
	T Data;
	size_t Key;
	
	Node* Next;
	Node* Left;
	Node* Right;
	Node* Parent;

	template<class T> friend class MHeap;


public:
	Node();
	Node<T>(T new_d, Node<T>* left, Node<T>* right, Node<T>* parent, Node<T>* next , size_t key);
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
		return true;
	}
	
	return false;
}

template<class T>
Node<T> ::Node<T>(T new_d, Node<T>* left, Node<T>* right, Node<T>* parent, Node<T>* next, size_t key)
{
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




#endif