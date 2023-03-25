#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

template <class T, class C>
class Node
{
public:
	Node();
	Node(T *newmorse,C *newchar); // this may not work so get rid of * in case

	C getchar() const;
	T getmorse() const;
	Node<T,C>* getLeftptr() const;
	Node<T,C>* getRightptr() const;

	void setLeftptr(Node<T,C>* newleftptr);
	void setRightptr(Node<T,C>* newrightptr);
	void setchar(C const newchar);
	void setmorse(T const newmorse);

private:
	C* mp_engchar;
	T* mp_morse;
	Node<T,C>* mp_Right, * mp_Left;
};
template<class T,class C>
Node<T,C>::Node()
{
	mp_engchar = '\0';
	mp_morse = '\0';
	mp_Left = mp_Right = nullptr;
}
template<class T,class C>
Node<T,C>::Node(T *newmorse, C* newchar)
{
	mp_engchar = newchar;
	mp_morse = newmorse;

	mp_Left = mp_Right = nullptr;
}
template<class T, class C>
C Node<T,C>::getchar() const
{
	return *(mp_engchar);
}
template<class T, class C>
T Node<T,C>::getmorse() const
{
	return *(mp_morse);
}
template<class T, class C>
Node<T,C>* Node<T, C>::getLeftptr() const
{
	return *mp_Left;
}
template<class T, class C>
Node<T,C>* Node<T, C>::getRightptr() const
{
	return *mp_Right;
}
template <class T, class C>
void Node<T,C>::setLeftptr(Node<T,C>*newleftptr)
{
	mp_Left = newleftptr;
}
template <class T, class C>
void Node<T,C>::setRightptr(Node<T,C>* newrightptr)
{
	mp_Right = newrightptr;
}
template <class T, class C>
void Node<T, C>::setchar(C const newchar)
{
	mp_engchar = newchar;
}
template <class T, class C>
void Node<T, C>::setmorse(T const newmorse)
{
	mp_morse = newmorse;
}