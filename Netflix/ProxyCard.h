#pragma once
#ifndef _PROXYCARD_H
#define _PROXYCARD_H
#include "IProxy.h"
#include "Date.h"
#include "CreditCard.h"
class CreditCard;
class ProxyCard : public IProxy
{
private:
	IProxy* realCard;
public:

	const int FOUR_DIGITS = 10000;

	ProxyCard(int number, int month, int year);

	const int getNumber() override;

	friend ostream & operator<<(ostream & os, ProxyCard & card);
};

#endif //_PROXYCARD_H