#include "pch.h"
#include "Container.h"
#include "FileHandling.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <string>
#include <exception>
using namespace std;

template <class T>
void Container<T>::addElement(T element) {
	container.push_back(element);
}

template <class T>
void Container<T>::displayList() {
	cout << endl;
	if (container.empty()) {
		throw out_of_range("Empty list");
	}

	for (size_t i = 0; i < container.size(); i++) {
		cout << "Position: " << i << endl;
		container[i]->display();
	}

}

template <class T>
void Container<T>::editPerson(size_t index) {

	if(index > container.size()) {
		throw out_of_range("Out of range");
	}
		container[index]->edit();
}

template <class T>
void Container<T>::deletePerson(size_t index) {

	if (index > container.size()) {
		throw out_of_range("Out of range");
	}
	container.erase(container.begin() + index);	
}

template <class T>
void Container<T>::saveToFile(string filename) {
	
	if (container.empty()) {
		throw exception("Empty list");
	}
	
	ofstream file;
	file.open(filename, ios::out | ios::binary);
	if (!file) {
		throw string("Couldn't open file");
	}
	
	for (size_t i = 0; i < container.size(); i++) {
		container[i]->save(file);
	}

	file.flush();
	file.close();

	cout << "Successfully saved data to file" << endl;
}

template <class T>
void Container<T>::readFromFile(string filename) {
	ifstream file;
	file.open(filename, ios::in | ios::binary);
	if (!file.good()) {
		throw string("Couldn't open file");
	}

	while (file.peek() != EOF) {
		addElement(FileHandling::read(file));
	}

	file.close();
	cout << "Succesfully read data from file" << endl;
}

template <class T>
void Container<T>::saveToTxt(string filename) {
	
	if (container.empty()) {
		throw exception("Empty list");
	}
	
	ofstream file;
	file.open(filename);
	if (!file.good()) {
		throw string("Couldn't open file");
	}

	for (size_t i = 0; i < container.size(); i++) {
		container[i]->saveTxt(file);
	}

	file.close();
	cout << "Succesfully saved data to file" << endl;
}

template <class T>
void Container<T>::freeMemoryAtIndex(size_t index) {
	delete container[index];
}

template <class T>
void Container<T>::freeAllMemory() {
	for (size_t i = 0; i < container.size(); i++) {
		delete container[i];
	}
}