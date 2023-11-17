#include "MaxHeap.h"

//************************** Constructor **********************//
// Default constructor
template <class T>
MaxHeap<T>::MaxHeap()
{
	make_heap(Heap.begin(), Heap.end());
}

// Argument constructor
// Precondition: an non-empty array
// Postcondition: create a heap base on the array
template<class T>
MaxHeap<T>::MaxHeap(const vector<T>& array) : Heap(array)
{
	make_heap(Heap.begin(), Heap.end());
}

//************************** Public Functions **********************//

//Precondition: NA
//Postcondition: return the size of the heap
template <class T>
int MaxHeap<T>::getSize()
{
	return Heap.size();
}

//Precondition: NA
//Postcondition: return true if the heap is empty otherwise false
template <class T>
bool MaxHeap<T>::checkEmpty()
{
	return Heap.empty();
}

//Precondition: NA
//Postcondition: return the front element of the heap
template <class T>
T MaxHeap<T>::getFront()
{
	return Heap.front();
}

//Precondition: the heap has to be not empty
//Postcondition: pop the front element of the heap
template <class T>
void MaxHeap<T>::popHeap()
{
	pop_heap(Heap.begin(), Heap.end());
	Heap.pop_back();
}

//Precondition: NA
//Postcondition: insert an element to the heap
template <class T>
void MaxHeap<T>::pushHeap(const T& value)
{
	Heap.push_back(value);
	push_heap(Heap.begin(), Heap.end());
}

//Precondition: the heap has to be not empty
//Postcondition: display the heap
template <class T>
void MaxHeap<T>::display()
{
	for (int i = 0; i < Heap.size(); i++)
	{
		cout << Heap[i] << " ";
	}
	cout << "\n";
}

//Precondition: the heap has to be not empty
//Postcondition: return true if the item is find in the heap, otherwise return false
template <class T>
bool MaxHeap<T>::search(const T& Item)
{
	for (int i = 0; i < Heap.size(); i++)
	{
		if (Heap[i] == Item)
		{
			return true;
		}
	}

	return false;
}

//Precondition: NA
//Postcondition: sort the heap
template <class T>
void MaxHeap<T>::sort()
{
	make_heap(Heap.begin(), Heap.end());
	sort_heap(Heap.begin(), Heap.end());
}

//Precondition: NA
//Postcondition: return true if a vector is a heap, otherwise return false
template <class T>
bool MaxHeap<T>::isHeap(const vector<T>&array)
{
	return is_heap(array.begin(), array.end());
}


//****************************** Overload Operator ****************************//
//Precondition: a MaxHeap object
//Postcondition: return true if this object is smaller than the parameter else return false
template <class T>
bool MaxHeap<T>::operator<(MaxHeap<T> obj)
{
	return Heap.size() < obj.getSize();
}