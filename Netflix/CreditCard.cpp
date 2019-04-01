#include "CreditCard.h"

CreditCard::CreditCard(int number, int month, int year) : validDate(year, month)
{
	this->setNumber(number);
}

void CreditCard::setNumber(int number) throw(const string&)
{
	if (number < MIN_NUMBER || number > MAX_NUMBER)
	{
		throw "Invalid credit card number input.";
	}
	this->number = number;
}

const int CreditCard::getNumber()
{
	return this->number % FOUR_DIGITS;
}

