#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

char inputChar(string prompt, string options);
int inputInteger(string prompt);
int inputInteger(string prompt, bool posNeg);

template <class T>
class Heap {
private:
    vector<T> heap;

public:
    // Constructors
    Heap();

    // Public member functions
    void createDynamicArray(int size);
    void pushElement(T element);
    void makeHeap();
    void displayMaxElement();

    void pushHeap(T element);
    void popHeap();
    void sortHeap();
    bool isHeap();

    void isHeapUntil();
    void displayHeap();
    void menu();
};

#endif  
