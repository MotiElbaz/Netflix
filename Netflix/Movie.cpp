#include "Movie.h"

Movie::Movie(const string& name, const int rate, const eGenre genre, const int producingYear) : Media(name, rate, genre)
{
	this->setProducingYear(producingYear);
}

Movie::Movie(const Media& media, const int producingYear) : Media(media)
{
	this->setProducingYear(producingYear);
}

void Movie::setProducingYear(const int producingYear)
{
	if (producingYear > YEAR_MAX || producingYear < YEAR_MIN)
	{
		throw "Invalid year input.";
	}
	this->producingYear = producingYear;
}

int Movie::getProducingYear() const
{
	return this->producingYear;
}

void Movie::toOs(ostream & os, bool flag) const
{
	if (flag)
	{
		os << "Movie : \n" << "Year : " << this->getProducingYear();
		return;
	}
	os << "Movie : \n" << "Year : " << this->getProducingYear() << " , Name : ";
}