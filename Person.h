#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Person {
	
public:
	string name;
	string surname;
	int age;
	int type;	// 0-employee, 1-student
	
//	virtual Person& enterDataInteractive();
	virtual void display() = 0;
	virtual void edit() = 0;
	virtual void save(ofstream &) = 0;
	virtual void saveTxt(ofstream &) = 0;
	Person();
	~Person();
};
