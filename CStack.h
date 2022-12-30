#pragma once
#include <iostream>
using namespace std;
class CStack
{
private:
	int mLength;
	int size;
	string** mData;
	string** mTop;
	


public:
	CStack(int stackSize);
	CStack(CStack* oldStack);
	void Push(string newData);
	void Pop(string& oldData);
	bool IsEmpty();
	bool IsFull();
	void DisplayStack();
	void GetLength(int& length);
	void DisplayStackInReverse();
	int CountData(string searchString);
	int FindData(string searchString);
	void displayN(int n);
	bool findN(int n, string& foundString);
	bool allSame();
	void copyStack(CStack* newStack);
	~CStack();

};

