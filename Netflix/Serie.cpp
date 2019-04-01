#include "Serie.h"

Serie::Serie(const string& name, const int rate, const eGenre genre, const int numOfSeasons) : Media(name, rate, genre)
{
	this->setNumOfSeasons(numOfSeasons);
}

Serie::Serie(const Media& media, const int numOfSeasons) : Media(media)
{
	this->setNumOfSeasons(numOfSeasons);
}

void Serie::setNumOfSeasons(const int numOfSeasons)
{
	if (numOfSeasons < MIN)
	{
		throw "Invalid number of season input.";
	}
	this->numOfSeasons = numOfSeasons;
}

int Serie::getNumOfSeasons() const
{
	return this->numOfSeasons;
}

void Serie::toOs(ostream & os, bool flag) const
{
	if (flag)
	{
		os << "\nSerie : \n" << "Number of Seasons : " << this->getNumOfSeasons() << endl;
		return;
	}
	os << "\nSerie : \n" << "Number of Seasons : " << this->getNumOfSeasons() << " , Name : ";
}