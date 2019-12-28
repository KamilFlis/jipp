#pragma once
#include "Person.h"
#include <iostream>
using namespace std;

enum FACULTY {
	Information_Technology,
	Mathematics,
	Physics
};

class Student :public Person {
private:
	FACULTY faculty;

public:
	void setName(string name);
	void setSurname(string surname);
	void setAge(int age);
	void setFaculty(FACULTY faculty);

	Student();
	Student(string name, string surname, int age, FACULTY faculty);
	~Student();
	void enterDataInteractive();

	void display();
	void edit();
	void saveTxt(ofstream &);
	void save(ofstream &);
	static Student *read(ifstream &);
};

