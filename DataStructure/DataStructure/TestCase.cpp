#include "TestCase.h"
#include"SeqList.h"
#include"List.h"
#include "DbNode.h"
#include "tree.h"

TestCase::TestCase()
{
}


TestCase::~TestCase()
{
}

void TestCase::testSeqList()
{
	cout << " --------------------------testSeqList:--------------------------- \n";
	SeqList<int> list;
	int a[10];
	cout << "isEmpty: " << list.isEmpty() << endl;;

	for (int i = 0; i < 10; i++)
	{
		a[i] = i;
		list.insert(list.length(), a[i]);
	}

	list.output();
	int a1;
	list.getData(1, a1);
	cout << a1 << endl;
	list.insert(10, a1);
	list.output();
	cout << "isEmpty: " << list.isEmpty() << endl;
	cout << list.locate(3) << endl;
	list.remove(1, a1);
	list.output();
	cout << " --------------------------testSeqList:--------------------------- \n";


}

void TestCase::testList()
{
	cout << " --------------------------testSeqList:--------------------------- \n";
	List<int> list;
	int a[10];
	cout << "isEmpty: " << list.isEmpty() << endl;;

	for (int i = 0; i < 10; i++)
	{
		a[i] = i;
		list.insert(i, a[i]);
	}


	list.output();
	int a1;
	list.getData(1, a1);
	cout << a1 << endl;
	list.insert(10, a1);
	list.output();
	cout << "isEmpty: " << list.isEmpty() << endl;
	cout << list.locate(3)->data << endl;
	list.remove(1, a1);
	list.output();
	List<int> list2 = list;
	
	list2.output();

	List<int> list3,list4;
	list4 = list3 =  list;
	list3.output();
	list4.output();
	cout << " --------------------------testSeqList:--------------------------- \n";
}

void TestCase::testDbList()
{
	cout << " --------------------------testSeqList:--------------------------- \n";
	DbList<int> list;
	int a[10];
	cout << "isEmpty: " << list.isEmpty() << endl;;

	for (int i = 0; i < 10; i++)
	{
		a[i] = i;
		int j = list.length();
		list.insert(j, a[i]);
	}

	list.output();
	DbList<int> list2;// = list;
	list2 = list;
	list2.output();
	/*int a1;
	list.getData(1, a1);
	cout << a1 << endl;
	list.insert(10, a1);
	list.output();
	cout << "isEmpty: " << list.isEmpty() << endl;
	cout << list.locate(3) << endl;
	list.remove(1, a1);
	list.output();*/
	cout << " --------------------------testSeqList:--------------------------- \n";

}

void TestCase::testTree()
{
	Tree<int> tree;
	tree.insert(tree.getRoot(), 3);
	tree.insert(tree.getRoot(), 1);
	tree.insert(tree.getRoot(), 5);


	tree.inOrder(tree.getRoot());
}
