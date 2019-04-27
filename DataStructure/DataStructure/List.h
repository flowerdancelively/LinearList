#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct LinkNode
{
	T data;
	LinkNode<T>* link;
	LinkNode<T>(LinkNode<T>*ptr = nullptr) { link = ptr; }
	LinkNode<T>(const T&item, LinkNode<T>*ptr=nullptr) { data = item; link = ptr; }
};

template <typename T>
class List 
//	public LinearList<T>
{
public:
	List();
	List(const T&x);
	List(List<T>&L);
	~List();
	int size()const;
	int length() const;
	LinkNode<T>* getHead();
	LinkNode<T>* search(T&x)const;
	LinkNode<T>* locate(int i)const;
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
	List<T>& operator=(List<T>&L);
	friend ostream& operator<<(ostream&out, List<T>& L)
	{

		LinkNode<T>* cur = L.getHead();
		while (nullptr != cur->link)
		{
			out << cur->link->data << " ";
			cur = cur->link;
		}
		out << "\n";
		return out;
	}
protected:
	LinkNode<T>* first;
};

template<typename T>
List<T>::List()
{
	first = new LinkNode<T>();
}

template<typename T>
inline List<T>::List(const T & x)
{
	first = new LinkNode<T>(x);
}

template<typename T>
 List<T>::List(List<T>& L)
{
	 LinkNode<T>* p = L.getHead();
	 if (first != nullptr)
	 {
		 delete first;
		 first = nullptr;
	 }

	 LinkNode<T>* cur = first = new LinkNode<T>();
	 while (nullptr != p->link)
	 {
		 cur->link = new LinkNode<T>(p->link->data);
		 cur = cur->link;
		 p = p->link;
	 }
	 cur->link = nullptr;
}

 template<typename T>
 inline List<T>::~List()
 {
	 //should remove all linknodes
	 LinkNode<T>*p,*q;
	 p = first;
	 while (nullptr!=p)
	 {
		 q = p;
		 p = p->link;
		 delete q;
	 }
 }

 template<typename T>
 inline int List<T>::size() const
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
 inline int List<T>::length() const
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
 inline LinkNode<T>* List<T>::getHead()
 {
	 return first;
 }

 template<typename T>
  LinkNode<T>* List<T>::search(T & x) const
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
 inline LinkNode<T>* List<T>::locate(int i) const
 {
	 //i is the index
	 if (i < 0 || i>length()-1)
		 return nullptr;
	 LinkNode<T>* p = first->link;
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
 inline bool List<T>::getData(int i, T & x) const
 {
	 //i is the index
	 if (i < 0 || i>length() - 1)
		 return false;
	 LinkNode<T>* p = first->link;
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
 inline bool List<T>::setData(int i, T & x)
 {
	 //i is the index
	 if (i < 0 || i>length() - 1)
		 return false;
	 LinkNode<T>* p = first->link;
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
 inline bool List<T>::insert(int i, T & x)
 {
	 //i is the index
	 if (i < 0 || i>length())
		 return false;
	 LinkNode<T>* p = first;
	 int cnt = 0;
	
	 while (nullptr != p)
	 {
		 if (cnt == i)
		 {
			 LinkNode<T>* q = new LinkNode<T>(x);
			 LinkNode<T>* q1;
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
 inline bool List<T>::remove(int i, T & x)
 {
	 //i is the index
	 if (i < 0 || i>length() - 1)
		 return false;
	 LinkNode<T>* p = first;
	 int cnt = 0;
	 while (nullptr != p->link)
	 {
		 if (cnt == i)
		 {
			 LinkNode<T>* q = p->link;
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
 inline bool List<T>::isEmpty() const
 {
	 return first->link == nullptr;
 }

 template<typename T>
 inline bool List<T>::isFull() const
 {
	 return false;
 }

 template<typename T>
 inline void List<T>::sort()
 {
 }

 template<typename T>
 inline void List<T>::input()
 {
 }

 template<typename T>
 inline void List<T>::output()
 {
	 LinkNode<T> *p = first->link;
	 while (nullptr != p)
	 {
		 cout << p->data << " ";
		 p = p->link;
	 }
	 cout << endl;
 }

 template<typename T>
 inline List<T>& List<T>::operator=(List<T>& L)
 {
	 // TODO: 在此处插入 return 语句
	 LinkNode<T>*cur = first =new LinkNode<T>(); 
	 LinkNode<T>*p = L.getHead();
	 while (nullptr != p->link)
	 {
		 cur->link = new LinkNode<T>(p->link->data);
		 cur = cur->link;
		 p = p->link;
	 }
	 cur->link = nullptr;
	 return *this;
 }

