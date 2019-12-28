// JiPP_projekt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Person.h"
#include "Student.h"
#include "Employee.h"
#include "Container.h"
#include "Container.cpp"
#include <iostream>

void menu();

int main() {
	
	Container<Person *> list;
/*
	// testowe
	Student student1("Kamil", "Flis", 20, Information_Technology);
	Student student2("Patryk", "Borchowiec", 21, Information_Technology);
	Employee pracownik1("Jakub", "Chwastek", 20, "C#FIRMA", 200000);
	Employee pracownik2("Alek", "Drozdz", 20, "ALKOBUS", 250000);

	list.addElement(&student1);
	list.addElement(&student2);
	list.addElement(&pracownik1);
	list.addElement(&pracownik2);
*/

	Student *student = NULL;
	Employee *employee = NULL;
	int option, optionAdd;

	while (true) {
		menu();
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
				startAdd:
				cout << "1 - Student" << endl;
				cout << "2 - Employee" << endl;
				cout << "Input option: ";
				cin >> optionAdd;
				while (cin.fail()) {
					cout << "Wrong input" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Input option: ";
					cin >> optionAdd;
				}
				switch (optionAdd) {
					case 1:
						student = new Student();
						student->enterDataInteractive();
						list.addElement(student);
						break;
						
					case 2:
						employee = new Employee();
						employee->enterDataInteractive();
						list.addElement(employee);
						break;

					default:
						cout << "Wrong option" << endl;
						goto startAdd;

				}
				cout << "Successfully added person to the list" << endl;
				break;
				
			case 2:
				size_t index;
				try {
					list.displayList();
					cout << "Input index of person you want to edit: ";
					cin >> index;
					while (cin.fail()) {
						cout << "Wrong input" << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Input index of person you want to edit: ";
						cin >> index;
					}
					list.editPerson(index);
					cout << "Successfully edited person at index: " << index << endl;
				}
				catch (out_of_range ex) {
					cout << "Error: " << ex.what() << endl;
				}
				break;

			case 3:
				try {
					list.displayList();
					cout << "Input index of person you want to delete: ";
					cin >> index;
					while (cin.fail()) {
						cout << "Wrong input" << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Input index of person you want to delete: ";
						cin >> index;
					}
					list.deletePerson(index);
					list.freeMemoryAtIndex(index);
					cout << "Successfully deleted person at index: " << index << endl;
				}
				catch (out_of_range ex) {
					cout << "Error: " << ex.what() << endl;
				}
				break;

			case 4:
				try {
					list.displayList();
				}
				catch (out_of_range ex) {
					cout << "Error: " << ex.what() << endl;
				}
				break;

			case 5:
				try {
					list.saveToTxt("textData.txt");
				}
				catch (string ex) {
					cout << "Error: " << ex << endl;
				}
				catch (exception ex) {
					cout << "Error: " << ex.what() << endl;
				}
				break;

			case 6:
				try {
					list.saveToFile("data.bin");
				}
				catch (string ex) {
					cout << "Error: " << ex << endl;
				}
				catch (exception ex) {
					cout << "Error: " << ex.what() << endl;
				}
				break;

			case 7:
				try {
					list.readFromFile("data.bin");
				}
				catch (string ex) {
					cout << "Error: " << ex << endl;
				}
				break;

			case 10:
				cout << "EXIT" << endl;
				list.freeAllMemory();
				system("pause");
				return 0;

			default:
				cout << "Wrong option" << endl;
				break;
		}
	}
}

void menu() {
	cout << endl << "1 - Add person" << endl;
	cout << "2 - Edit person" << endl;
	cout << "3 - Delete person" << endl;
	cout << "4 - Print list" << endl;
	cout << "5 - Save to text file" << endl;
	cout << "6 - Save to binary file" << endl;
	cout << "7 - Read from binary file" << endl;
	cout << "10 - Exit" << endl;
}
