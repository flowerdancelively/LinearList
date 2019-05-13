#pragma once 
#include<iostream>
using std::cout;
static const int maxsize = 100;

template<typename T>
class MinHeap
{
public:
	MinHeap(int sz=maxsize);
	~MinHeap() { delete[] heap; }
	bool empty();
	bool full();
	void insert(T data);
	void remove(T&data);//delete the heap[0]
	void makeEmpty();
	T * heap;
	int currentSize;

private:
	//T * heap;
	//int currentSize;
	int maxHeapSize;
	void siftDown(int index, int m);
	void siftUp(int index);
};

template<typename T>
inline MinHeap<T>::MinHeap(int sz)
{
	maxHeapSize = sz > maxsize ? sz : maxsize;
	heap = new T[maxHeapSize];
	currentSize = 0;
}

template<typename T>
inline bool MinHeap<T>::empty()
{
	return currentSize ==0;
}

template<typename T>
inline bool MinHeap<T>::full()
{
	return currentSize == maxHeapSize;
}

template<typename T>
inline void MinHeap<T>::insert(T  data)
{
	if (currentSize >= maxHeapSize)
		return;
	heap[currentSize] = data;

	siftUp(currentSize);
	++currentSize;
}

template<typename T>
inline void MinHeap<T>::remove(T & data)
{
	auto temp = heap[0];
	data = temp;
	if (currentSize <= 0)
		return;
	data = heap[0];
	heap[0] = heap[currentSize - 1];
	--currentSize;
	siftDown(0, currentSize);
	
}

template<typename T>
inline void MinHeap<T>::makeEmpty()
{
	currentSize = 0;
}


template<typename T>
inline void MinHeap<T>::siftDown(int index, int m)
{
	int i = index;
	int j = 2 * index + 1;
	T temp = heap[i];
	while (j<=m)
	{
		if (j < currentSize && heap[j] > heap[j + 1]) ++j;
		if (temp < heap[j])break;
		else
		{
			heap[i] = heap[j];
		}
		i = j;
		j = 2 * i + 1;
	}
	heap[i] = temp;
}

template<typename T>
inline void MinHeap<T>::siftUp(int index)
{
	
	int i = index;
	int j = (i - 1) / 2;
	T temp = heap[i];
	while (i > 0)
	{
		if (temp >= heap[j])
			break;
		else
		{
			heap[i] = heap[j];
			i = j;
			j = (i - 1) / 2;
		}
			
	}
	heap[i] = temp;
	//int j = index;
	//cout << j << " - ";
	//int i = (j - 1) / 2;
	//T temp = heap[j];
	//while (j > 0)
	//{
	//	if (heap[i] <= temp)
	//		break;
	//	else
	//	{
	//		heap[j] = heap[i];
	//		j = i;
	//		i = (j - 1) / 2;
	//	}
	//}
	//cout << j << "\n";
	//heap[j] = temp;
}
