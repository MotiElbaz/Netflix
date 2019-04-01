#include "Person.h"

Person::Person(const string& name, const int id, const  int day, const int month, const int year) : birthday(year, month, day)
{
	this->setId(id);
	this->setName(name);
}

void Person::setName(const string& name)
{
	this->name = name;
}

void Person::setId(int id)
{
	if (id < ID_MIN)
	{
		throw "Invalid id input.";
	}
	this->id = id;
}

const string& Person::getName() const
{
	return this->name;
}

const int Person::getId() const
{
	return this->id;
}

const Date& Person::getBirthday() const
{
	return this->birthday;
}

void Person::toOs(ostream & os)
{
}

Person::operator const char*()
{
	return name.c_str();
}

ostream& operator<<(ostream& os,Person& p)
{
	os << "Person : " << p.getName().c_str() << " , ID : " << p.getId() << " , Birtday " << p.getBirthday();
	p.toOs(os);
	return os;
}
