#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <stddef.h>
using namespace std;

//int printLeftChild(size_t i, size_t j, int father);
//int printRightChild(size_t i, size_t j, int father);


int printRightChild(size_t i, size_t j, int father)
{
	if (i <= j)	
	{
		int middle = father[i][j];
		cout << "K" << middle << " is the right child of K" << father << endl;
		printLeftChild(i, middle - 1, middle);
		printRightChild(middle + 1, j, middle);
		return 0;
	}
	if (i == j - 1)
	{
		cout << "D" << i << "is the right child of K" << i << endl;
		return 0;
	}//the end of brunch
	return 0;
}

int printLeftChild(size_t i, size_t j, size_t father)
{	
	if (i <= j)
	{
		int middle = father[i][j];
		cout << "K" << middle << " is the left child of K" << father << endl;
		printLeftChild(i, middle - 1, middle);
		printRightChild(middle + 1, j, middle);
		return 0;//the next father
	}
	if (i == j - 1)
	{
		cout << "D" << i - 1 << "is the left child of K" << i << endl;
		return 0;
	}//the end of brunch
	return 0;
}

int main()
{
	int size = 0;
	cout << "input the size of btree" << endl;
	cin >> size;
	cout << "make sure your file is capable for " 
	<< size << " points btree" << endl;
	int father[size - 1][size - 1] = { 0 };
	ifstream fin("root.txt");

	if (fin)
	{
		for (int j = 0; j < size - 1; j++)
		{
			for (int i = 0; i < size - 1; i++)
			{
				fin >> father[i][j];//read in file stream
			}
		}
		/*for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << root[i][j] << " " << endl;
				//file inpuit examination
			}
		}*/
	}
	else
	{
		cout << "read file failed" << endl;
	}
	int rt = father[0][size - 1];
	cout << "the root is K" << rt << endl;

	printLeftChild(0, rt - 1, rt);
	printRightChild(rt + 1, size -1, rt);
	return 0;
}