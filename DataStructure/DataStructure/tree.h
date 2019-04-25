#pragma once
#include <stack>

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
	void postOrder(TreeNode<T>*root);

	void preOrderNoRecursive(TreeNode<T>*root);
	void inOrderNoRecursive(TreeNode<T>*root);
//	void postOrderNoRecursive(TreeNode<T>*root);


	int getHeight(TreeNode<T>*root);
	int getHeightNoRecursive(TreeNode<T>*root);

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

template<typename T>
inline void Tree<T>::postOrder(TreeNode<T>* root)
{
	if (nullptr != root)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data<<" ";
	}
}

template<typename T>
inline void Tree<T>::preOrderNoRecursive(TreeNode<T>* root)
{
	std::stack<TreeNode<T>*> stack;
	TreeNode<T>* cur;
	if (nullptr != root)
	{
		stack.push(root);
		
		while (!stack.empty())
		{
			cur = stack.top();
			if (nullptr != cur)
			{
				cout << cur->data << " ";
			}
			stack.pop();
			if (nullptr != cur)
			{
				stack.push(cur->right);
				stack.push(cur->left);
			}
		}
	}
	cout << "\n";
}

template<typename T>
inline void Tree<T>::inOrderNoRecursive(TreeNode<T>* root)
{
	std::stack<TreeNode<T>*> stack;
	TreeNode<T>* cur;
	
	while (!stack.empty() || nullptr != root)
	{

		while (nullptr != root)
		{
			stack.push(root);
			root = root->left;
		}

		root = stack.top();
		stack.pop();
		cout << root->data << " ";
		

		root = root->right;
				
 
		
	}
	
	
	cout << "\n";


}

template<typename T>
inline int Tree<T>::getHeight(TreeNode<T>* root)
{
	if (nullptr != root)
	{
		int i = 1 + getHeight(root->left);
		int j = 1 + getHeight(root->right);
		return i > j ? i : j;
	}
	return 0;
}

template<typename T>
inline int Tree<T>::getHeightNoRecursive(TreeNode<T>* root)
{
	return 0;
}

