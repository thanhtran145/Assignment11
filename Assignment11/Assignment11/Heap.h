#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <string>

using namespace std;

char inputChar(string prompt, string options);
int inputInteger(string prompt);
char inputChar(string prompt);
int inputInteger(string prompt, bool posNeg);

template <class T>
class Heap
{
private:
	vector <T> heap;
public:

	Heap();

	void menu();
};

