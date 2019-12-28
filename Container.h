#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Container {
private:
	vector<T> container;

public:
	void addElement(T);
	void displayList();
	void editPerson(size_t);
	void deletePerson(size_t);
	void saveToFile(string);
	void readFromFile(string);
	void saveToTxt(string);
	void freeMemoryAtIndex(size_t);
	void freeAllMemory();
};
