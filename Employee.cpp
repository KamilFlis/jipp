#include "pch.h"
#include "Employee.h"
#include <string>

Employee::Employee() {
	name = " ";
	surname = " ";
	age = 0;
	companyName = " ";
	salary = 0;
	type = 0;
}

Employee::Employee(string name, string surname, int age, string companyName, double salary) {
	this->name = name;
	this->surname = surname;
	this->age = age;
	this->companyName = companyName;
	this->salary = salary;
	this->type = 0;
}

Employee::~Employee()
{
}

void Employee::setName(string name) {
	this->name = name;
}

void Employee::setSurname(string surname) {
	this->surname = surname;
}

void Employee::setAge(int age) {
	this->age = age;
}

void Employee::setSalary(double salary) {
	this->salary = salary;
}

void Employee::setCompanyName(string companyName) {
	this->companyName = companyName;
}

void Employee::display() {
	cout << "Type: Employee" << endl;
	cout << "Name: " << name << endl;
	cout << "Surname: " << surname << endl;
	cout << "Age: " << age << endl;
	cout << "Company name: " << companyName << endl;
	cout << "Salary: " << salary << endl;
	cout << endl;
}

void Employee::enterDataInteractive() {
	string name, surname, companyName;
	int age;
	double salary;

	cout << "Enter name: ";
	cin >> name;
	setName(name);

	cout << "Enter surname: ";
	cin >> surname;
	setSurname(surname);

	cout << "Enter age: ";
	cin >> age;
	while (cin.fail()) {
		cout << "Wrong input" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter age: ";
		cin >> age;
	}
	setAge(age);

	cout << "Enter company name: ";
	cin >> companyName;
	setCompanyName(companyName);

	cout << "Enter salary: ";
	cin >> salary;
	while (cin.fail()) {
		cout << "Wrong input" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter salary: ";
		cin >> salary;
	}
	setSalary(salary);

}

static void editMenu() {
	cout << "1 - Surname" << endl;
	cout << "2 - Age" << endl;
	cout << "3 - Salary" << endl;
	cout << "4 - Company name" << endl;
};

void Employee::edit() {
	int option, age;
	string surname, companyName;
	double salary;
	editMenu();
	cout << "Input option: ";
	cin >> option;
	switch (option) {
		case 1:
			cout << "New surname: ";
			cin >> surname;
			setSurname(surname);
			break;

		case 2:
			cout << "New age: ";
			cin >> age;
			while (cin.fail()) {
				cout << "Wrong input" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "New age: ";
				cin >> age;
			}
			setAge(age);
			break;

		case 3:
			cout << "New salary: ";
			cin >> salary;
			while (cin.fail()) {
				cout << "Wrong input" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "New salary: ";
				cin >> salary;
			}
			setSalary(salary);
			break;

		case 4:
			cout << "New company name: ";
			cin >> companyName;
			setCompanyName(companyName);
			break;

		default:
			cout << "Wrong option" << endl;
			break;
	}
}

void Employee::saveTxt(ofstream &file) {

	file << name << " " << surname << " " << age << " " << companyName << " " << salary << endl;
}

void Employee::save(ofstream &file) {

	size_t nameLenght = name.size();
	size_t surnameLenght = surname.size();
	size_t companyNameLenght = companyName.size();

	file.write(reinterpret_cast<char *>(&type), sizeof(int));
	file.write(reinterpret_cast<char *>(&nameLenght), sizeof(size_t));
	file.write(name.c_str(), nameLenght);
	file.write(reinterpret_cast<char *>(&surnameLenght), sizeof(size_t));
	file.write(surname.c_str(), surnameLenght);
	file.write(reinterpret_cast<char *>(&age), sizeof(int));
	file.write(reinterpret_cast<char *>(&companyNameLenght), sizeof(size_t));
	file.write(companyName.c_str(), companyNameLenght);
	file.write(reinterpret_cast<char *>(&salary), sizeof(double));
}

Employee *Employee::read(ifstream &file) {

	size_t nameLenght, surnameLenght, companyNameLenght;
	string emName, emSurname, emCompanyName;
	int emAge;
	double emSalary;

	file.read(reinterpret_cast<char *>(&nameLenght), sizeof(size_t));
	char *buff = new char[nameLenght + 1];

	file.read(buff, nameLenght);
	emName.assign(buff, nameLenght);

	file.read(reinterpret_cast<char *>(&surnameLenght), sizeof(surnameLenght));
	buff = new char[surnameLenght + 1];

	file.read(buff, surnameLenght);
	emSurname.assign(buff, surnameLenght);

	file.read(reinterpret_cast<char *>(&emAge), sizeof(int));

	file.read(reinterpret_cast<char *>(&companyNameLenght), sizeof(size_t));
	buff = new char[companyNameLenght + 1];
	file.read(buff, companyNameLenght);
	emCompanyName.assign(buff, companyNameLenght);

	file.read(reinterpret_cast<char *>(&emSalary), sizeof(double));

	delete[] buff;
	return new Employee(emName, emSurname, emAge, emCompanyName, emSalary);
}