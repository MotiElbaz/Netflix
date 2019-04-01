#include "Actor.h"

Actor::Actor(const string& name, const int id, const  int day, const int month, const int year) :
	Person(name, id, day, month, year)
{
}

Actor::Actor(const Person& person) : Person(person)
{

}

bool Actor::addMediaToMediaList(Media & media)
{
	vector<Media*>::iterator itrBegin = this->mediaList.begin();
	vector<Media*>::iterator itrEnd = this->mediaList.end();
	for (; itrBegin != itrEnd; ++itrBegin)
	{
		if (*itrBegin == &media)
		{
			throw "Media already exist.";
		}
	}
	this->mediaList.push_back(&media);
	return true;
}

vector<Media*> Actor::getMediaList() const
{
	return this->mediaList;
}

void Actor::toOs(ostream & os)
{
	os << " , Played in the movies : ";
	vector<Media*>::iterator itrBegin = this->mediaList.begin();
	vector<Media*>::iterator itrEnd = this->mediaList.end();
	for (; itrBegin != itrEnd; )
	{
		Media* temp = *itrBegin;
		os << *temp->getName().c_str();
		++itrBegin;
		if (itrBegin != itrEnd)
			os << " , ";
	}
}