#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "BSTNode.hpp"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

template<class X, class Y>
class BST
{
public:

	BST();
	~BST();
	void insert(X newmorse, Y newchar);
	void print();
	X search(Y charItem);

private:
	Node<X,Y>* mp_root;
	void insert(Node<X,Y>*pTree,X newmorse, Y newchar);
	void print(Node<X, Y>* pTree);
	X search(Node<X, Y>* pTree, Y charItem);
	void treegone(Node<X, Y>* pTree);


};
template <class X, class Y>
BST<X,Y>::BST()
{
	mp_root = nullptr;
	fstream MorseTable;
	if (!MorseTable.is_open())
	{							// had to use stackoverflow and TutorialsPoint code to be able to read the file correctly
		MorseTable.open("MorseTable.txt", std::ios::in);
		while (!MorseTable.eof())
		{
			X morse[20] = "";
			Y engchar = '\0';
			string temp[20] = "";
			MorseTable.get(engchar);
			MorseTable.getline(temp);
			MorseTable.getline(morse);
			insert(morse, engchar);
		}
	}
	MorseTable.close();
}
template <class X, class Y>
BST<X, Y>::~BST()
{
	//since a destructor cant have parameters, ill call a different function using mp_root
	treegone(mp_root);
}
template<class X, class Y>
void BST<X, Y>::insert(X newmorse, Y newchar)
{
	insert(mp_root, newmorse, newchar);// this shall recursively do the inserting
}
template <class X, class Y>
void BST<X, Y>::insert(Node<X, Y>* pTree, X newmorse, Y newchar)//private recursive insert function
{
	if (mp_root == nullptr) // base case / tree is completely empty
	{
		mp_root = new Node<X, Y>(newmorse, newchar); // making the root the newdata
	}
	else if (newchar > pTree->getchar())
	{
		if (pTree->getRightptr() == nullptr)
		{
			pTree->setRightptr(new Node<X, Y>(newmorse, newchar));
		}
		else
		{
			insert(pTree->getRightptr(), newmorse, newchar);

		}
	}
	else if (newchar < pTree->getchar())//newdata is less than current node
	{
		if (pTree->getLeftptr() == nullptr)
		{
			pTree->setLeftptr(new Node<X, Y>(newmorse, newchar));
		}
		else
		{
			insert(pTree->getLeftptr(), newmorse, newchar);

		}
	}
	else
	{

	}
}
template<class X, class Y>
void BST<X, Y>::print()
{
	print(mp_root);
}
template<class X, class Y>
void BST<X, Y>::print(Node<X, Y>* pTree)
{
	if (mp_root != nullptr)
	{
		print(pTree->getLeftptr());
		cout << pTree->getchar() << endl;
		cout << pTree->getmorse() << endl;
		print(pTree->getRightptr());
	}
}
template<class X, class Y>
X BST<X, Y>::search(Y charItem)
{
	search(mp_root, charItem);
}
template<class X, class Y>
X BST<X, Y>::search(Node<X, Y>* pTree, Y charItem)
{
	if (mp_root != nullptr)
	{
		if (charItem == pTree->getchar())//how can it traverse?
		{
			return pTree->getmorse();
		}
	}
}

template<class X, class Y>
void BST<X, Y>::treegone(Node<X, Y>* pTree)
{
	if (mp_root != nullptr)
	{
		treegone(pTree->getLeftptr());
		treegone(pTree->getRightptr());
		delete pTree;
	}
}
