#pragma once
#include "Person.h"
#include <iostream>
using namespace std;

class Employee :public Person {
	string companyName;
	double salary;	

public:
	void setName(string name);
	void setSurname(string surname);
	void setAge(int age);
	void setSalary(double salary);
	void setCompanyName(string companyName);
	
	Employee();
	Employee(string name, string surname, int age, string companyName, double salary);
	~Employee();
	void enterDataInteractive();

	void display();
	void edit();
	void saveTxt(ofstream &);
	void save(ofstream &);
	static Employee *read(ifstream &);
};

