#ifndef _DATE_H
#define _DATE_H
#include <iostream>
using namespace std;

class Date {
public:

	const int DAY_MAX = 31;
	const int DAY_MONTH_MIN = 1;
	const int MONTH_MAX = 12;
	const int YEAR_MIN = 1970;
	const int YEAR_MAX = 2019;

	Date(int year = 1970, int month = 1, int day = 1);

	void setDay(const int day);
	void setMonth(const int month);
	void setYear(const int year);

	const int getDay() const;
	const int getMonth() const;
	const int getYear() const;

	friend ostream& operator<<(ostream& os, const Date& date);

protected:
	int day;
	int month;
	int year;
};


#endif //_DATE_H