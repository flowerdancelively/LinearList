
#pragma once

#include <iostream>
using namespace std;

template<typename T>
struct CircLinkNode
{
	T data;
	CircLinkNode<T>* link;
	CircLinkNode<T>(CircLinkNode<T>*ptr = nullptr) { link = ptr; }
	CircLinkNode<T>(const T&item, CircLinkNode<T>*ptr = nullptr) { data = item; link = ptr; }
};

template <typename T>
class CircList
	//	public LinearCircList<T>
{
public:
	CircList();
	CircList(const T&x);
	CircList(CircList<T>&L);
	~CircList();
	int size()const;
	int length() const;
	CircLinkNode<T>* getHead();
	CircLinkNode<T>* search(T&x)const;
	CircLinkNode<T>* locate(int i)const;
	//int search(T&x)const ;
	//int locate(int i)const;
	bool getData(int i, T&x)const;
	bool setData(int i, T&x);
	bool insert(int i, T&x);
	bool remove(int i, T&x);
	bool isEmpty()const;
	bool isFull()const;
	void sort();
	void input();
	void output();
	CircList<T>& operator=(CircList<T>&L);
protected:
	LinkNode<T>* first,last;
};

template<typename T>
CircList<T>::CircList()
{
	first = new LinkNode<T>();
	//first->link = last;
}

template<typename T>
inline CircList<T>::CircList(const T & x)
{
	first = new LinkNode<T>(x);
}

template<typename T>
CircList<T>::CircList(CircList<T>& L)
{
	LinkNode<T>* p = L.getHead();
	LinkNode<T>* cur = first = new LinkNode<T>();
	T value;
	while (nullptr != p->link)
	{
		cur->link = new LinkNode<T>(p->link->data);
		cur = cur->link;
		p = p->link;
	}
	cur->link = nullptr;
}

template<typename T>
inline CircList<T>::~CircList()
{
	//should remove all linknodes
	LinkNode<T>*p, *q;
	// p = first->link;
	p = first;
	while (nullptr != p)
	{
		q = p;
		p = p->link;
		delete q;
	}
}

template<typename T>
inline int CircList<T>::size() const
{
	LinkNode<T> *p = first->link;
	int cnt = 0;
	while (nullptr != p)
	{
		++cnt;
		p = p->link;
	}
	return cnt;
}

template<typename T>
inline int CircList<T>::length() const
{
	LinkNode<T> *p = first->link;
	int cnt = 0;
	while (nullptr != p)
	{
		++cnt;
		p = p->link;
	}
	return cnt;
}

template<typename T>
inline CircLinkNode<T>* CircList<T>::getHead()
{
	return first;
}

template<typename T>
CircLinkNode<T>* CircList<T>::search(T & x) const
{
	LinkNode<T>*p = first->link;
	while (nullptr != p)
	{
		if (x == p->data)
			return p;
	}
	return nullptr;
}

template<typename T>
inline CircLinkNode<T>* CircList<T>::locate(int i) const
{
	//i is the index
	if (i < 0 || i>length() - 1)
		return nullptr;
	CircLinkNode<T>* p = first->link;
	int cnt = 0;
	while (nullptr != p)
	{
		if (cnt == i)
			return p;
		p = p->link;
		++cnt;
	}
	return nullptr; //
}

template<typename T>
inline bool CircList<T>::getData(int i, T & x) const
{
	//i is the index
	if (i < 0 || i>length() - 1)
		return false;
	CircLinkNode<T>* p = first->link;
	int cnt = 0;
	while (nullptr != p)
	{
		if (cnt == i)
		{
			x = p->data;
			return true;
		}
		p = p->link;
		++cnt;
	}
	return false;
}

template<typename T>
inline bool CircList<T>::setData(int i, T & x)
{
	//i is the index
	if (i < 0 || i>length() - 1)
		return false;
	CircLinkNode<T>* p = first->link;
	int cnt = 0;
	while (nullptr != p)
	{
		if (cnt == i)
		{
			p->data = x;
			return true;
		}
		p = p->link;
		++cnt;
	}
	return false;
}

template<typename T>
inline bool CircList<T>::insert(int i, T & x)
{
	//i is the index
	if (i < 0 || i>length())
		return false;
	CircLinkNode<T>* p = first;
	int cnt = 0;

	while (nullptr != p)
	{
		if (cnt == i)
		{
			CircLinkNode<T>* q = new LinkNode<T>(x);
			CircLinkNode<T>* q1;
			q1 = p->link;
			p->link = q;
			q->link = q1;
			return true;
		}
		p = p->link;
		++cnt;
	}
	return false;
}

template<typename T>
inline bool CircList<T>::remove(int i, T & x)
{
	//i is the index
	if (i < 0 || i>length() - 1)
		return false;
	CircLinkNode<T>* p = first;
	int cnt = 0;
	while (nullptr != p)
	{
		if (cnt == i)
		{
			CircLinkNode<T>* q = p->link;
			p->link = p->link->link;
			delete q;
			return true;
		}
		p = p->link;
		++cnt;
	}
	return false;
}

template<typename T>
inline bool CircList<T>::isEmpty() const
{
	return first->link == nullptr;
}

template<typename T>
inline bool CircList<T>::isFull() const
{
	return false;
}

template<typename T>
inline void CircList<T>::sort()
{
}

template<typename T>
inline void CircList<T>::input()
{
}

template<typename T>
inline void CircList<T>::output()
{
	CircLinkNode<T> *p = first->link;
	while (nullptr != p)
	{
		cout << p->data << " ";
		p = p->link;
	}
	cout << endl;
}

template<typename T>
inline CircList<T>& CircList<T>::operator=(CircList<T>& L)
{
	// TODO: 在此处插入 return 语句
	CircLinkNode<T>*cur = first = new CircLinkNode<T>();
	CircLinkNode<T>*p = L.getHead();
	while (nullptr != p->link)
	{
		cur->link = new CircLinkNode<T>(p->link->data);
		cur = cur->link;
		p = p->link;
	}
	cur->link = nullptr;
	return *this;
}

