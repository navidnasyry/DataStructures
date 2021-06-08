#ifndef BST_ASDFSDAF
#define BST_ASDFSDAF

#include "Node.h"

#define  ulli unsigned long long int

template<class T>
class BST
{
	Node<T>* Root;
	ulli Size;

	 friend class Node<T>;

public:
	BST<T>();
	~BST<T>();
	void Distructor(Node<T>* root);
	void Insert(T new_data);
	void PrintInOrder(Node<T>* temp);
	void PrintInOrder();
	void setWeight(string adrs , T new_w);
	Node<T>& Search(Node<T>* temp , T k);
	Node<T>& Search(T k);



	
};

template<class T>
void BST<T>::Distructor(Node<T>* root)
{
	if (root)
	{
		Distructor(root->Right);
		Distructor(root->Left);
		root->~Node();
		root = nullptr;
		delete root;

	}

}

template<class T>
Node<T>& BST<T>::Search(T k)
{
	return Search(this->Root, k);
}

template<class T>
Node<T>& BST<T>::Search(Node<T>* temp , T k)
{
	if (temp->key == k || !temp)
	{
		return temp;
	}
	if (k > temp->key)
		return Search(temp->Right, k);
	else
		return Search(temp->Left, k);


}

template<class T>
void BST<T>::PrintInOrder()
{
	PrintInOrder(this->Root);
}

template<class T>
BST<T> :: BST<T>()
{
	this->Root = nullptr;
	this->Size = 0;
}


template<class T>
BST<T> ::~BST<T>()
{
	Distructor(this->Root);
	return;
}
template<class T>
void BST<T> :: Insert(T new_data)
{
	Size++;

	if (this->Root)
	{
		Node<T>* temp = this->Root;
		while (true)
		{
		
			if (new_data > temp->Data)
			{
				if (!temp->Right)
				{
					Node<T>* new_node = new Node<T>(new_data, nullptr, nullptr, temp);
					temp->Right = new_node;
					return;

				}
				temp = temp->Right;
			}
			else
			{

				if (!temp->Left)
				{
					Node<T>* new_node = new Node<T>(new_data, nullptr, nullptr, temp);
					temp->Left = new_node;
					return;

				}
				temp = temp->Left;
			}
		}



	}
	
	Node<T>* new_bst = new Node<T>(new_data , nullptr , nullptr , nullptr);
	this->Root = new_bst;
	return;
	
}


template<class T>
void BST<T> :: PrintInOrder(Node<T>* temp)
{
	/*if (!this->Root)
	{
		cout << "BST is empity !\n\n";
		return;
	}*/
	//if (start)
		//temp = this->Root;
	if (!temp)
	{
		return;
	}


	if (temp->Left)
	{
		PrintInOrder(temp->Left);
	}

	cout << temp->Data<<endl;

	if (temp->Right)
	{
		PrintInOrder(temp->Right);
	}


	return;
}

template<class T>
void BST<T> :: setWeight(string adrs , T new_w)
{

	Node<T> *temp = this->Root;
	for (int i = 0; i < adrs.length(); i++)
	{
		if (adrs[i] == 'l' )
		{
			if(temp->Left != nullptr)
				temp = temp->Left;
			else
			{
				Node<T>* new_node = new Node<T>(new_w, nullptr, nullptr, temp);
				temp->Left = new_node;
				break;
			}


		}
		else if (adrs[i] == 'r')
		{
			if (temp->Right != nullptr)
				temp = temp->Right;
			else
			{
				Node<T>* new_node = new Node<T>(new_w, nullptr, nullptr, temp);
				temp->Right = new_node;
				break;
			}
		}

	}

	return;

}

























#endif