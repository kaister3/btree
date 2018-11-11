#include <iostream>
#include <fstream>
#include <vector>
#include <stddef.h>
#include <string>
using std::vector;
using namespace std;
typedef vector<size_t> D1array;        //
typedef vector<vector<size_t>> D2array;//planar array
int printRightChild(size_t i, size_t j, size_t father, D2array tree);
int printLeftChild(size_t i, size_t j, size_t father, D2array tree);

int main()
{
	size_t size = 0;
	cout << "input the size of btree" << endl;
	cin >> size;
	cout << "make sure your file is capable for " 
	<< size << " points btree" << endl;

	D2array tree(size + 1, D1array(size + 1, 0));

	ifstream fin("root.txt");
	ofstream fout("tree.txt");
	if (!fin)
	{
		cout << "File do not exist!" << endl;
		exit(1);
	}
	for (int j = 1; j <= size; j++)
	{
		for (int i = 1; i <= size; i++)
		{
			fin >> tree[i][j];
		}
	}
	/*for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << tree[i][j];
			//file inpuit examination
		}
		cout << endl;
	}	*/

	size_t rt = tree[1][size];
	cout << "the root is K" << rt << endl;
	//printRightChild(2, 1, 1, tree);
	printLeftChild(1, rt - 1, rt, tree);
	printRightChild(rt + 1, size , rt, tree);
	return 0;
}


int printRightChild(size_t i, size_t j, size_t father, D2array tree)
{
	if (i <= j)	
	{
		size_t middle = tree[i][j];
		cout << "K" << middle << " is the right child of K" << father << endl;
		printLeftChild(i, middle - 1, middle, tree);
		printRightChild(middle + 1, j, middle, tree);
	}
	if (i == j + 1)
	{
		cout << "D" << j << " is the right child of K" << j << endl;
		return 0;
	}//the end of brunch
	return 0;
}

int printLeftChild(size_t i, size_t j, size_t father, D2array tree)
{	
	if (i <= j)
	{
		int middle = tree[i][j];
		cout << "K" << middle << " is the left child of K" << father << endl;
		printLeftChild(i, middle - 1, middle, tree);
		printRightChild(middle + 1, j, middle, tree);
		return 0;//the next father
	}
	if (i == j + 1)
	{
		cout << "D" << i - 1 << " is the left child of K" << i << endl;
		return 0;
	}//the end of brunch
	return 0;
}

