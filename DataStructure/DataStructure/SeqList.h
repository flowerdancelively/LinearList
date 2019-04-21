#pragma once
#include "LinearList.h"
#include <iostream>
using namespace std;

const  int defaultSize = 100;

template <typename T>
class SeqList :
	public LinearList<T>
{
public:
	SeqList(int size=defaultSize);
	SeqList(SeqList<T>&L); 
	~SeqList();
	int size()const { return maxSize; }
	int length() const { return last+1; }
	int search(T&x)const;
	int locate(int i)const;
	bool getData(int i, T&x)const;
	bool setData(int i, T&x);
	bool insert(int i, T&x);
	bool remove(int i, T&x);
	bool isEmpty()const;
	bool isFull()const ;
	void sort() ;
	void input() ;
	void output() ;
	SeqList<T>& operator=(SeqList<T>&L);
protected:
	T*data;
	int maxSize;
	int last;
	void reSize(int newSize);
};

#include "SeqList.h"

template <typename T>
SeqList<T>::SeqList(int size)
{
	if (size > 0)
	{
		maxSize = size;
		last = -1;
		data = new T[size];
		if (nullptr == data)
		{

		}
	}
}

template <typename T>
SeqList<T>::SeqList(SeqList<T>&L)
{
	maxSize = L.size();
	last = L.length() - 1;;
	data = new T[maxSize];
	T value;
	for (int i = 0; i < last + 1; i++)
	{
		getData(i, value);
		data[i] = value;
	}
}

template<typename T>
SeqList<T>::~SeqList()
{
	delete[] data;
}

template<typename T>
int SeqList<T>::search(T & x) const
{
	for (int i = 0; i < length(); i++)
	{
		if (data[i] == x)
			return i;
	}
	return -1;
}

template<typename T>
int SeqList<T>::locate(int i) const
{
	if (i < 0)
		return -1;
	return i;
}

template<typename T>
bool  SeqList<T>::getData(int i, T&x)const
{
	if (i<0 || i>last)
		return false;
	x = data[i];
	return true;
}

template<typename T>
bool SeqList<T>::setData(int i, T & x)
{
	if (i<0 || i>last)
		return false;
	data[i] = x;
}

template<typename T>
bool SeqList<T>::insert(int i, T & x)
{
	if (i == size() - 1)
		return false;
	if (i<0 || i>last + 1)
		return false;
	for (int j = last + 1; j > i; j--)
		data[j] = data[j - 1];
	data[i] = x;
	++last;
	return true;
}

template<typename T>
bool SeqList<T>::remove(int i, T & x)
{
	if (i<0 || i>last)
		return false;
	x = data[i];
	for (int j = i; j < last; j++)
		data[j] = data[j + 1];
	--last;
	return true;
}

template<typename T>
bool SeqList<T>::isEmpty() const
{
	if (length() == 0)
		return true;
	return false;

}

template<typename T>
bool SeqList<T>::isFull() const
{
	if (last == size() - 1)
		return true;
	return false;

}

template<typename T>
void SeqList<T>::sort()
{
}

template<typename T>
void SeqList<T>::input()
{

}

template<typename T>
void SeqList<T>::output()
{
	for (int i = 0; i < length(); i++)
		cout << data[i] << " ";
	cout << endl;
}

template<typename T>
SeqList<T>& SeqList<T>::operator=(SeqList<T>& L)
{
	SeqList<T> list;
	list.maxSize = L.size();
	list.last = L.length() - 1;;
	list.data = new T[list.maxSize];
	T value;
	for (int i = 0; i < last + 1; i++)
	{
		getData(i, value);
		data[i] = value;
	}
	return list;
}

template<typename T>
void SeqList<T>::reSize(int newSize)
{

}
