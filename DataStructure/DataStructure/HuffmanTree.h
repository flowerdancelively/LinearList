#include"heap.h"

template<typename T>
struct HuffmanNode
{
	T data;
	HuffmanNode*left, *right,*parent;
	HuffmanNode() :data(0),left(nullptr), right(nullptr), parent(nullptr) {}
	HuffmanNode(T da,HuffmanNode*l,HuffmanNode*r,HuffmanNode*p):data(da),left(l),right(r),parent(p){}
	bool operator<=(const HuffmanNode& node) { return data <= node.data; }
	bool operator<(const HuffmanNode& node) { return data < node.data; }
	bool operator>(const HuffmanNode& node) { return data > node.data; }
	bool operator>=(const HuffmanNode& node) { return data >= node.data; }
	//bool &operator[](const HuffmanNode& node) { return data; }

};

template<typename T>
class HuffmanTree
{
public:
	HuffmanTree(T *w,int n);
	~HuffmanTree() { deleteHuffmanTree(root); }
	HuffmanNode<T>*getRoot();
	void print();
	void preOrder(HuffmanNode<T>* root);
private:
	HuffmanNode<T>*root;
	void deleteHuffmanTree(HuffmanNode<T>*root);
	void mergeHuffmanTree(HuffmanNode<T>&th1, HuffmanNode<T>&th2, HuffmanNode<T>*&parent);
};

template<typename T>
inline HuffmanTree<T>::HuffmanTree(T *w, int n)
{
	//int w[] = { 5,29,7,8,14,23,3,11 };
	MinHeap<HuffmanNode<T>> hp;
	
	for (int i= 0; i < n; i++)
	{
		HuffmanNode<T> work;

		work.data = w[i];
		work.left = nullptr;
		work.right = nullptr;
		work.parent = nullptr;
		hp.insert(work);
	}
	for (int i = 0; i < n; i++)
	{
		cout << hp.heap[i].data << " ";
	}
	cout << "\n";
	HuffmanNode<T>  *parent = nullptr, first, second;

	for (int i = 0; i < n - 1; i++)
	{
		hp.remove(first);
		hp.remove(second);
		cout << "first " << first.data << " second: " << second.data << "\n";

		mergeHuffmanTree(first, second, parent);
		HuffmanNode<T> temp = *parent;
		hp.insert(temp);
		HuffmanNode<T> temp1;
		for (int i = 0; i < hp.currentSize; i++)
		{
			//cout << hp.heap[i].data << " ";
			temp1 = hp.heap[i];
		}
	}

	root = parent;
	preOrder(root);
}

template<typename T>
inline HuffmanNode<T>* HuffmanTree<T>::getRoot()
{
	return root;
}

template<typename T>
inline void HuffmanTree<T>::preOrder(HuffmanNode<T>* root)
{
	if (nullptr != root)
	{
		cout << root->data << endl;
		preOrder(root->left);
		preOrder(root->right);
	}
	return;
}

template<typename T>
inline void HuffmanTree<T>::print()
{
	preOrder(root);
}

template<typename T>
inline void HuffmanTree<T>::mergeHuffmanTree(HuffmanNode<T> & th1, HuffmanNode<T> & th2, HuffmanNode<T> *& parent)
{
	parent = new HuffmanNode<T>();
	parent->left = &th1;
	parent->right = &th2;
	parent->data = th1.data + th2.data;
	//th1.parent = th2.parent = parent;
}

template<typename T>
inline void HuffmanTree<T>::deleteHuffmanTree(HuffmanNode<T>* root)
{
	if (nullptr != root)
	{
		HuffmanNode<T>*temp = root;
		deleteHuffmanTree(root->left);
		deleteHuffmanTree(root->right);
		delete root;
	}
}

