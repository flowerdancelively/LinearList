#pragma once

template<typename T>
struct DbNode
{
	T data;
	DbNode<T>*lLink, *rLink;
	DbNode<T>(DbNode<T>*left = nullptr, DbNode<T>*right = nullptr) { lLink = left; rLink = nullptr; }
	DbNode<T>(T rdata, DbNode<T>*left = nullptr, DbNode<T>*right = nullptr) { data = rdata; lLink = left; rLink = nullptr; }

};

template<typename T>
class DbList
{
public:
	DbList();
	DbList( DbList<T> &L );
	
	~DbList();
	int size()const;
	int length() const;
	DbNode<T>* getHead();
	DbNode<T>* search(const T&x)const;
	DbNode<T>* locate(int i)const;
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
	DbList<T>& operator=( DbList<T>&L);
protected:
	DbNode<T>* first;
};


template<typename T>
inline DbList<T>::DbList()
{
	first = new DbNode<T>();
	first->lLink = first->rLink = first;
}

template<typename T>
DbList<T>::DbList( DbList<T> &L)
{
	DbNode<T>*cur = first = new DbNode<T>();
	first->lLink = first->rLink = first;

	DbNode<T>*pCur = L.getHead();
	while (L.getHead() != pCur->lLink)
	{
		DbNode<T>*temp = new DbNode<T>(pCur->lLink->data);
		temp->lLink = cur->lLink;
		cur->lLink->rLink = temp;
		temp->rLink = cur;
		cur->lLink = temp;
		pCur = pCur->lLink;
	}
	cur->lLink = first;
}


template<typename T>
inline DbList<T>::~DbList()
{
	DbNode<T>* cur = first;
	while (cur->lLink != first)
	{
		DbNode<T>* p = cur->lLink;
		cur->lLink = p->lLink;
		p->lLink->rLink = cur;
		
		delete p;
		cur = cur->lLink;
	}
	delete first;
}

template<typename T>
inline int DbList<T>::size() const
{
	DbNode<T>*cur = first;
	int cnt = 0;
	while (cur->lLink != first)
	{
		cur = cur->lLink;
		++cnt;
	}
	return cnt;
}

template<typename T>
inline int DbList<T>::length() const
{
	DbNode<T>*cur = first;
	int cnt = 0;
	while (cur->lLink != first)
	{
		cur = cur->lLink;
		++cnt;
	}
	return cnt;
}

template<typename T>
inline DbNode<T>* DbList<T>::getHead()
{
	return first;
}

template<typename T>
inline DbNode<T>* DbList<T>::search(const T & x) const
{
	DbNode<T>* cur = first;
	while (cur->lLink != first)
	{
		if (x == cur->lLink->data)
		{
			return cur->lLink;
		}
	}
	return nullptr;
}

template<typename T>
inline DbNode<T>* DbList<T>::locate(int i) const
{
	if (i<0 || i>length() - 1)
		return nullptr;

	DbNode<T>*cur = first;
	int cnt = 0;
	while (cur->lLink != first)
	{
		if (cnt == i)
		{
			return cur->lLink;
		}
		++cnt;
		cur = cur->lLink;
	}
	return nullptr;
}

template<typename T>
inline bool DbList<T>::getData(int i, T & x) const
{
	DbNode<T>*cur = locate(i);
	if (nullptr == cur)
		return false;
	x = cur->data;
	return true;
}

template<typename T>
inline bool DbList<T>::setData(int i, T & x)
{

	DbNode<T>*cur = locate(i);
	if (nullptr == cur)
		return false;
	cur->data = x;
	return true;
}

template<typename T>
inline bool DbList<T>::insert(int i, T & x)
{
	/*DbNode<T>*p = locate(i);
	if (nullptr == p)
		return false;*/
	if (i<0 || i>length())
	{
		return false;
	}
	int cnt = 0;
	DbNode<T>*p = first;
	DbNode<T>*q = new DbNode<T>(x);
	if (i==0)
	{
		q->lLink = p->lLink;
		p->lLink->rLink = q;
		q->rLink = p;
		p->lLink = q;

	}
	else
	{
		while (p->lLink != first || cnt <= i )
		{
			
			if (cnt == i)
			{
				
				q->lLink = p->lLink;
				p->lLink->rLink = q;
				q->rLink = p;
				p->lLink = q;

				return true;
			}
			p = p->lLink;
			++cnt;
		}
	}
	
	
	return false;
}

template<typename T>
inline bool DbList<T>::remove(int i, T & x)
{
	DbNode<T>*p = locate(i);
	if (nullptr == p)
		return false;

	p->rLink->lLink = p->lLink;
	p->lLink->rLink = p->rLink;
	return true;

}

template<typename T>
inline bool DbList<T>::isEmpty() const
{
	return first->lLink == first->rLink;
}

template<typename T>
inline bool DbList<T>::isFull() const
{
	return false;
}

template<typename T>
inline void DbList<T>::sort()
{
}

template<typename T>
inline void DbList<T>::input()
{
}

template<typename T>
inline void DbList<T>::output()
{
	DbNode<T>* cur = first;
	while (cur->lLink != first)
	{
		cout << cur->lLink->data << " ";
		cur = cur->lLink;
	}
	cout << endl;
}

template<typename T>
inline DbList<T>& DbList<T>::operator=(DbList<T>& L)
{
	// TODO: 在此处插入 return 语句
	DbNode<T>*cur = first = new DbNode<T>();
	first->lLink = first->rLink = first;
	DbNode<T>*pCur = L.getHead();
	while (L.getHead() != pCur->lLink)
	{
		DbNode<T>*temp = new DbNode<T>(pCur->lLink->data);

		temp->lLink = cur->lLink;
		cur->lLink->rLink = temp;
		temp->rLink = cur;
		cur->lLink = temp;

		pCur = pCur->lLink;
	}
	cur->lLink = first;
	return *this;
}
