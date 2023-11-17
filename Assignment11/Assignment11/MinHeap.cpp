#include "MinHeap.h"

//************************** Constructor **********************//
// Default constructor
template<class Item>
MinHeap<Item>::MinHeap()
{
	make_heap(Heap.begin(), Heap.end(), greater<Item>());
}

// Argument constructor
// Precondition: an non-empty array
// Postcondition: create a heap base on the array
template<class Item>
MinHeap<Item>::MinHeap(const vector<Item>& array) : Heap(array)
{
	make_heap(Heap.begin(), Heap.end(), greater<Item>());
}


//************************** Public Functions **********************//
//Precondition: NA
//Postcondition: return the size of the heap
template<class Item>
int MinHeap<Item>::getSize()
{
	return Heap.size();
}

//Precondition: NA
//Postcondition: return true if the heap is empty otherwise false
template<class Item>
bool MinHeap<Item>::empty()
{
	return Heap.empty();
}

//Precondition: NA
//Postcondition: insert an element to the heap
template<class Item>
void MinHeap<Item>::pushHeap(Item entry)
{
	Heap.push_back(entry);
	make_heap(Heap.begin(), Heap.end(), greater<Item>());
}

//Precondition: NA
//Postcondition: return the front element of the heap
template<class Item>
Item MinHeap<Item>::getFront()
{
	return Heap.front();
}

//Precondition: the heap has to be not empty
//Postcondition: pop the front element of the heap
template<class Item>
void MinHeap<Item>::popHeap()
{
	pop_heap(Heap.begin(), Heap.end());
	Heap.pop_back();
}

//Precondition: the heap has to be not empty
//Postcondition: display the heap
template<class Item>
void MinHeap<Item>::display()
{
	for (int i = 0; i < Heap.size(); i++)
	{
		cout << Heap[i] << " ";
	}
	cout << "\n";
}

//Precondition: the heap has to be not empty
//Postcondition: return true if the value is find in the heap, otherwise return false
template <class Item>
bool MinHeap<Item>::search(const Item& value)
{
	for (int i = 0; i < Heap.size(); i++)
	{
		if (Heap[i] == value)
		{
			return true;
		}
	}

	return false;
}

//****************************** Overload Operator ****************************//
//Precondition: a MaxHeap object
//Postcondition: return true if this object is smaller than the parameter else return false
template <class Item>
bool MinHeap<Item>::operator<(MinHeap<Item> obj)
{
	return Heap.size() < obj.getSize();
}