#pragma once
#include <string>
using namespace std;

class Sorter
{ 
private:
	int numAccess;
	int arraySize;
	int *array;
public:
	string sortAlg;
	Sorter(int arraySize, string sortAlgorithm);
	~Sorter();
};

