#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template <class T>
class MaxHeap
{
private:
	vector <T> Heap;
public:
	
	// Constructors
	MaxHeap();
	MaxHeap(const vector<T>& array);

	// Public member functions
	int getSize();
	bool checkEmpty();
	T getFront();
	void popHeap();

	void pushHeap(const T &value);
	void display();
	bool search(const T &Item);

	void sort();
	bool isHeap(const vector<T>& array);

	bool operator<(MaxHeap<T> obj);
};

