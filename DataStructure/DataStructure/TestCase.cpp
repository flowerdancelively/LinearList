#include "TestCase.h"



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
