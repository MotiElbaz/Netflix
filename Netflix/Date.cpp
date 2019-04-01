#pragma warning( disable : 4290 )
#include "Date.h"

Date::Date(int year, int month, int day)
{
	this->setDay(day);
	this->setMonth(month);
	this->setYear(year);
}

void Date::setDay(int day)throw(const string&)
{
	if (day > DAY_MAX || day < DAY_MONTH_MIN)
	{
		throw "Invalid day input.";
	}
	this->day = day;
}

void Date::setMonth(int month)throw(const string&)
{
	if (month > MONTH_MAX || month < DAY_MONTH_MIN)
	{
		throw "Invalid month input.";
	}
	this->month = month;
}

void Date::setYear(int year)throw(const string&)
{
	if (year > YEAR_MAX || year < YEAR_MIN)
	{
		throw "Invalid year input.";
	}
	this->year = year;
}

const int Date::getDay() const
{
	return this->day;
}

const int Date::getMonth() const
{
	return this->month;
}

const int Date::getYear() const
{
	return this->year;
}

ostream & operator<<(ostream & os, const Date & date)
{
	os << "Date : " << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
	return os;
}
