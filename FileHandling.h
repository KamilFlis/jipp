#include "Person.h"
#pragma once
class FileHandling {
	
public:

	static Person *read(ifstream &);
	FileHandling();
	~FileHandling();
};

