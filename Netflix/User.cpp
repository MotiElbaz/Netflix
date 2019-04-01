#include "User.h"

User::User(const string& name, const int id, const  int day, const int month, const int year, const int creditCardNumber, const int validMonth, const int validYear) : 
	Person(name, id, day, month, year) , creditCard(creditCardNumber, validMonth, validYear)
{

}

void User::watchMedia(Media& media)
{
	media.increaseViews();
}

const ProxyCard User::getCreditCard() const
{
	return this->creditCard;
}

void User::toOs(ostream & os)
{
	os << " , " << this->creditCard;
}

void User::notify(Media* media)
{
	this->watchMedia(*media);
}

