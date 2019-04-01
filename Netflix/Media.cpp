#include "Media.h"

Media::Media(const Media & media)
{
	this->name = media.name;
	this->rate = media.rate;
	this->genre = media.genre;
}

Media::Media(const string& name, const int rate, const eGenre genre)
{
	this->setGenre(genre);
	this->setName(name);
	this->setRate(rate);
}

void Media::setName(const string& name)
{
	this->name = name;
}

void Media::setRate(int rate) throw(const string&)
{
	if (rate > MAX_RATE || rate < MIN_RATE)
	{
		throw "Invalid rate input.";
	}
	this->rate = rate;
}

void Media::setGenre(eGenre genre) throw (const string&)
{
	if (genre < COMEDY || genre > SCIENCE_FICTION)
	{
		throw " Invalid genre input.";
	}
	this->genre = genre;
}

const string& Media::getName() const
{
	return this->name;
}

int Media::getRate() const
{
	return this->rate;
}

Media::eGenre Media::getGenre() const
{
	return this->genre;
}

int Media::getNumOfViews() const
{
	return this->numOfViews;
}

bool Media::addActorToActorsList(Actor& actor) throw(const string&)
{
	this->actorList.insert(&actor);
	return true;
}

void Media::increaseViews()
{
	this->numOfViews++;
}

bool Media::operator<(const Media& other) const
{
	if (this->rate < other.rate)
	{
		return true;
	}
	return false;
}

void Media::toOs(ostream & os) const
{
}

Media::operator const char*()
{
	return name.c_str();
}

ostream & operator<<(ostream & os,Media & media)
{
	media.toOs(os);
	os << media.getName().c_str() << " , Rating : " << media.getRate() << " , Genre : " << media.GENRES[media.getGenre()].c_str() << " , Views : " << media.getNumOfViews();
	os << " , Actors : " << endl;
	media.actorList.print();
	return os;
}