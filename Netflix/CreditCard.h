#ifndef _CREDITCARD_H
#define _CREDITCARD_H
#include "IProxy.h"
#include "Date.h"
class IProxy;
class CreditCard : public IProxy
{
private:
	int number;
	Date validDate;
public:

	const int FOUR_DIGITS = 10000;
	const int MIN_NUMBER = 9999999; 
	const int MAX_NUMBER = 100000000;

	CreditCard(int number, int month, int year);

	void setNumber(int Number);

	const int getNumber() override;

	//friend ostream & operator<<(ostream & os, const CreditCard & card);

};

#endif //_CREDITCARD_H