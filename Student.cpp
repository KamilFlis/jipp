#include "pch.h"
#include "Student.h"
#include <string>
#include <fstream>

Student::Student() {
	name = " ";
	surname = " ";
	age = 0;
	faculty = (FACULTY) 0;
	type = 1;
}

Student::Student(string name, string surname, int age, FACULTY faculty) {
	this->name = name;
	this->surname = surname;
	this->age = age;
	this->faculty = faculty;
	this->type = 1;
}

Student::~Student()
{
}

void Student::setName(string name) {
	this->name = name;
}

void Student::setSurname(string surname) {
	this->surname = surname;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setFaculty(FACULTY faculty) {
	this->faculty = faculty;
}

string faculties[] = {			//array with names of faculties for display
	"Information Technology",
	"Mathematics",
	"Physics"
};

void Student::display() {

	cout << "Type: Student" << endl;
	cout << "Name: " << name << endl;
	cout << "Surname: " << surname << endl;
	cout << "Age: " << age << endl;
	cout << "Faculty: ";
	switch (faculty) {
	
		case Information_Technology:
			cout << faculties[Information_Technology] << endl;
			break;
	
		case Mathematics:
			cout << faculties[Mathematics] << endl;
			break;

		case Physics:
			cout << faculties[Physics] << endl;
			break;

		default:
			cout << "No faculty" << endl;
	}
	cout << endl;
}

static void facultyMenu() {
	cout << "0 - " << faculties[Information_Technology] << endl;
	cout << "1 - " << faculties[Mathematics] << endl;
	cout << "2 - " << faculties[Physics] << endl;
}

void Student::enterDataInteractive() {

	string name, surname;
	int age, facultyOption;
	FACULTY faculty;

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

	start:
	facultyMenu();
	cout << "Enter faculty: " << endl;
	cin >> facultyOption;
	while (cin.fail()) {
		cout << "Wrong input" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter faculty: ";
		cin >> facultyOption;
	}
	switch (facultyOption) {
		case Information_Technology:
			faculty = Information_Technology;
			break;
			
		case Mathematics:
			faculty = Mathematics;
			break;

		case Physics:
			faculty = Physics;
			break;

		default:
			cout << "Wrong faculty" << endl;
			goto start;
	}

	setFaculty(faculty);
}

static void editMenu() {
	cout << "1 - Surname" << endl;
	cout << "2 - Age" << endl;
	cout << "3 - Faculty" << endl;
};


void Student::edit() {
	int option, age;
	string surname;
	FACULTY faculty;
	editMenu();
	cout << "Input option: ";
	cin >> option;
	while (cin.fail()) {
		cout << "Wrong input" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Input option: ";
		cin >> option;
	}
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
			start:
			facultyMenu();
			cout << "New faculty: ";
			cin >> option;
			while (cin.fail()) {
				cout << "Wrong input" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "New faculty: ";
				cin >> option;
			}
			switch (option) {
				case Information_Technology:
					faculty = Information_Technology;
					break;

				case Mathematics:
					faculty = Mathematics;
					break;

				case Physics:
					faculty = Physics;
					break;

				default:
					cout << "Wrong faculty" << endl;
					goto start;
			}
			setFaculty(faculty);
			break;

		default:
			cout << "Wrong option" << endl;
			break;
	}
}

void Student::saveTxt(ofstream &file) {

	file << name << " " << surname << " " << age << " ";
	switch (faculty) {
		case Information_Technology:
			file << "Information Technology\n";
			break;
		case Mathematics:
			file << "Mathematics\n";
			break;
		case Physics:
			file << "Physics\n";
	}
}

void Student::save(ofstream &file) {

	size_t nameLenght = name.size();
	size_t surnameLenght = surname.size();
	
	file.write(reinterpret_cast<char *>(&type), sizeof(int));
	file.write(reinterpret_cast<char *>(&nameLenght), sizeof(size_t));
	file.write(name.c_str(), nameLenght);
	file.write(reinterpret_cast<char *>(&surnameLenght), sizeof(size_t));
	file.write(surname.c_str(), surnameLenght);
	file.write(reinterpret_cast<char *>(&age), sizeof(int));
	file.write(reinterpret_cast<char *>(&faculty), sizeof(FACULTY));
}


Student *Student::read(ifstream &file) {

	size_t nameLenght, surnameLenght;
	string stName, stSurname;
	FACULTY stFaculty;
	int stAge;

	file.read(reinterpret_cast<char *>(&nameLenght), sizeof(size_t));
	char *buff = new char[nameLenght + 1];

	file.read(buff, nameLenght);
	stName.assign(buff, nameLenght);

	file.read(reinterpret_cast<char *>(&surnameLenght), sizeof(surnameLenght));
	buff = new char[surnameLenght + 1];

	file.read(buff, surnameLenght);
	stSurname.assign(buff, surnameLenght);

	file.read(reinterpret_cast<char *>(&stAge), sizeof(int));
	file.read(reinterpret_cast<char *>(&stFaculty), sizeof(FACULTY));

	delete[] buff;
	return new Student(stName, stSurname, stAge, stFaculty);
}