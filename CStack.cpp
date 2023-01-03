#include "CStack.h"

CStack::CStack(int stackSize)
{

	mLength = 0;
	size = stackSize;
	mData = new string * [stackSize]; //Pointing mData to array of pointers to string
	mTop = mData; //Pointing mTop to mData's first entry

	for (int i = 0; i < size; i++) //Setting all pointers from mData to nullptr
	{
		mData[i] = nullptr;
	}

}

CStack::CStack(CStack* oldStack) //Copy constructor
{

	mLength = 0;
	size = oldStack->size; //Initialising size to the existing stack's size
	mData = new string * [size]; //Pointing mData to array of pointers to string
	mTop = mData; //Pointing mTop to mData's first entry

	for (int i = 0; i < size; i++) //Setting all pointers from mData to nullptr
	{
		mData[i] = nullptr;
	}

	//for (string** i = oldStack->mData; i < oldStack->mTop; i++) //Since we are pushing data from the other stack, we use i with oldStack's mData and mTop
	//{
	//	Push(**i);
	//}

}

CStack::~CStack()
{
	if (!IsEmpty())
	{
		while (mTop > mData)
		{
			mTop--;  //Decrement mTop so it points to the last value
			delete* mTop; //delete dereferenced mTop so that deletes the value
		}

	}

	//Delete mData and set the pointers used to nullptr
	delete mData;
	mData = nullptr;
	mTop = nullptr;

}

void CStack::GetLength(int& length)
{
	int localLength = 0;
	for (int i = 0; i < size; i++) //Length is calculated by counting the number of pointers that are not nullptr in the stack
	{
		if (mData[i] != nullptr)
		{
			localLength++;
		}
	}

	length = localLength;
	mLength = localLength;

}

void CStack::Push(string newData)
{
	if (!IsFull())
	{
		*mTop = new string(newData); // A new string gets created dynamically at the location mTop is pointing to
		++mTop; //mTop then get incremented to point to the next empty location in the stack
	}
	else
	{
		cout << "\nStack is full\n\n";
	}
}

void CStack::Pop(string& oldData)
{
	if (!IsEmpty())
	{
		--mTop; //mTop gets decremented so that instead of pointing to an empty location, it points to the element below
		oldData = **mTop; //oldData gets assigned the value that mTop is pointing to
		delete* mTop; //mTop gets dereferenced so it gives its target's value and this gets deleted dynamically

	}
	else
	{
		cout << "\n stack is empty" << endl;
		oldData = "";
	}
}

//Checking if stack is full by checking if mTop is bigger than mData(first address in memory for the dynamic array) plus size

bool CStack::IsFull()
{
	return(mTop >= (mData + size));
}

//Checking if stack is empty by checking if mTop is smaller than mData
bool CStack::IsEmpty()
{
	return(mTop <= mData);
}

void CStack::DisplayStack()
{

	cout << "\n";

	//If the first element in mData is nullptr, that means the stack is empty and there's nothing to display
	if (*mData == nullptr)
	{
		cout << "\nStack is empty!\n\n";
	}
	else
	{
		for (string** i = mData; i < mTop; ++i)
		{
			cout << **i << endl;
		}
	}

}

void CStack::DisplayStackInReverse()
{
	cout << "\n";

	//If the first element in mData is nullptr, that means the stack is empty and there's nothing to display
	if (*mData == nullptr)
	{
		cout << "\nStack is empty!\n\n";
	}
	else
	{
		for (string** i = mTop - 1; i >= mData; i--)
		{
			cout << **i << endl;
		}
	}

}

int CStack::CountData(string searchString)
{
	int counter = 0;

	for (string** i = mData; i < mTop; ++i)
	{
		if (**i == searchString)
		{
			counter++;
		}
	}

	return counter;

}

int CStack::FindData(string searchString)
{
	int index = -1;

	for (string** i = mData; i < mTop; ++i)
	{
		index++;

		if (**i == searchString)
		{
			return index;
		}
	}


}

void CStack::displayN(int n)
{
	int i;
	GetLength(i);

	if (n < 0 || n > i)
	{
		cout << "Index provided is out of bounds\n\n";

	}
	else
	{
		int index = 0;

		for (string** i = mData; i < mTop; ++i)
		{
			index++;

			if (n == index)
			{
				cout << "The item at index " << n << " is " << **i << "\n\n";
			}
		}
	}

}

bool CStack::findN(int n, string& foundString)
{
	//First we get the length of the stack (elements in it)
	int i;
	GetLength(i);

	//If index given is out of bounds, return false
	if (n < 0 || n > i)
	{
		return false;

	}

	//Else proceed with the rest of the function
	else
	{
		int index = 0;

		for (string** i = mData; i < mTop; ++i)
		{
			index++;

			if (n == index)
			{
				foundString = **i;
				return true;
			}
		}
	}

}

//Function that checks if all elements are the same, implemented using the double slit window approach
bool CStack::allSame()
{
	int counter = 0;

	for (string** i = mData; i < mTop; i++)
	{
		string** j = mTop - 1;

		if (**i == **j)
		{
			counter++;
		}

		j--;

	}
	if (counter == mLength)
	{
		return true;
	}

	return false;
}

//copyStack method now used deep copy to avoid destructor issues
void CStack::copyStack(CStack* newStack)
{
	newStack->mData = new string * [size];;
	newStack->mTop = mData;

	for (string** i = mData; i < mTop; i++)
	{
		newStack->Push(**i);
	}

}
