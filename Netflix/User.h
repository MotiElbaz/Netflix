#ifndef _USER_H
#define _USER_H
#include <iostream>
#include "Person.h"
#include "ProxyCard.h"
#include "Media.h"
#include "IObserver.h"
using namespace std;
class Media;
class ProxyCard;
class User : public IObserver , public Person
{
public:

	User(const string& name, const int id, const  int day, const int month, const int year, const int creditCardNumber, const int validMonth, const int validYear);
	
	const ProxyCard getCreditCard() const;

	void watchMedia(Media& media);

	void toOs(ostream & os);

	virtual void notify(Media* media) override;

private:
	ProxyCard creditCard;
};
#endif //_USER_H