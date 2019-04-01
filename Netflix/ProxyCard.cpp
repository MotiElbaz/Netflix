#include "ProxyCard.h"

ProxyCard::ProxyCard(int number, int month, int year) : realCard(new CreditCard(number,month,year))
{
}

const int ProxyCard::getNumber()
{
	int temp = this->realCard->getNumber() % this->FOUR_DIGITS;
	return temp;
}

ostream & operator<<(ostream & os, ProxyCard& card)
{
	os << "Card - 4 last digits : " << card.getNumber();
	return os;
}