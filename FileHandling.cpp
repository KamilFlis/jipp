#include "pch.h"
#include "FileHandling.h"
#include "Student.h"
#include "Employee.h"

FileHandling::FileHandling()
{
}

FileHandling::~FileHandling()
{
}

Person *FileHandling::read(ifstream &file) {
	
	int type;
	file.read(reinterpret_cast<char *>(&type), sizeof(int));
	if (type == 0) {
		return Employee::read(file);
	}
	else if (type == 1) {
		return Student::read(file);
	}
	return 0;
}