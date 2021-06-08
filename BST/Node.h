#ifndef NODE_ASDFDAS
#define NODE_ASDFDAS

template <class T>
class Node
{
	T Data;
	Node<T>* Left;
	Node<T>* Right;
	Node<T>* Parent;

	template<class T> friend class BST;

public:
	Node<T>();
	Node<T>(T new_d, Node<T>* left, Node<T>* right, Node<T>* parent);

	~Node<T>();



};

template<class T>
Node<T> :: Node<T>()
{

	this->Left = nullptr;
	this->Right = nullptr;
	this->Parent = nullptr;


}

template<class T>
Node<T> :: ~Node<T>()
{
	this->Left = nullptr;
	this->Right = nullptr;
	this->Parent = nullptr;
}


template<class T>
Node<T> ::Node<T>(T new_d, Node<T>* left, Node<T>* right, Node<T>* parent)
{
	this->Data = new_d;
	this->Left = left;
	this->Right = right;
	this->Parent = parent;

}

#endif 
