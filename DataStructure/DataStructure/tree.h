#pragma once

template<typename T>
struct TreeNode
{
	T data;
	TreeNode*left, *right;
	TreeNode() {  left = right = nullptr; }
	TreeNode(const T & val, TreeNode*L=nullptr, TreeNode*R=nullptr) { data = val; left = L;right = R; }

};

template<typename T>
class Tree
{
public:
	Tree();
	~Tree();
	TreeNode<T>*&getRoot();
	void clearTree(TreeNode<T>*root);
	void insert(TreeNode<T>* &root, const T&val);
	void preOrder(TreeNode<T>*root);
	void inOrder(TreeNode<T>*root);

private:
	TreeNode<T>* _root;
};

template<typename T>
inline Tree<T>::Tree()
{
	_root = nullptr;
}

template<typename T>
inline Tree<T>::~Tree()
{
	clearTree(_root);
}

template<typename T>
inline TreeNode<T>* &Tree<T>::getRoot()
{
	return _root;
}

template<typename T>
inline void Tree<T>::clearTree(TreeNode<T>* root)
{
	TreeNode<T>* cur = root;
	if (nullptr != cur)
	{
		clearTree(cur->left);
		clearTree(cur->right);
		delete cur;
	}
}

template<typename T>
inline void Tree<T>::insert(TreeNode<T>* & root, const T & val)
{
	if (nullptr == root)
	{
		root = new TreeNode<T>(val);
		return;
	}
	else if (val > root->data)
	{
		insert(root->right, val);
	}
	else if (val < root->data)
	{
		insert(root->left, val);
	}
	else
		return;
}

template<typename T>
inline void Tree<T>::preOrder(TreeNode<T>* root)
{

	if (nullptr != root)
	{
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

template<typename T>
inline void Tree<T>::inOrder(TreeNode<T>* root)
{
	if (nullptr != root)
	{
		inOrder(root->left);
		cout << root->data << " ";
		inOrder(root->right);
	}
}
