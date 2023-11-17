#pragma once
#include<iostream>
#include<vector>
using namespace std;

template<class Item>
class MinHeap
{
private:
	vector<Item> Heap;
public:

	// Constructors
	MinHeap();
	MinHeap(const vector<Item>& array);

	// Public member functions
	int getSize();
	bool empty();
	void pushHeap(Item entry);

	Item getFront();
	void popHeap();
	void display();
	bool search(const Item& value);

	bool operator<(MinHeap<Item> obj);
};