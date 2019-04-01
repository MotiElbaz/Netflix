#ifndef _PERSON_H
#define _PERSON_H
#include "Date.h"
#include <string.h>
#include <algorithm>
using namespace std;

class Person {
public:

	const int ID_MIN = 999; 
	Person(const string& name, const int id, const  int day, const int month, const int year);

	void setName(const string& name);
	void setId(const int id);

	const string& getName() const;
	const int getId() const;
	const Date& getBirthday() const;

	virtual void toOs(ostream& os);
	friend ostream& operator<<(ostream& os,Person& p);
	operator const char*();

protected:
	std::string name;
	int id;
	Date birthday;
};

#endif //_PERSON_H