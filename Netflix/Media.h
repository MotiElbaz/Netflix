#pragma warning( disable : 4290 )
#ifndef _MEDIA_H
#define _MEDIA_H
#include <iostream>
#include <string.h>
#include "LinkedList.h"
#include "Actor.h"
using namespace std;
class Actor;

class Media {
public:

	const string GENRES[4] = { "COMEDY", "ACTION", "DRAMA", "SCIENCE FICTION" };
	const int MIN_RATE = 0;
	const int MAX_RATE = 10;
	const enum eGenre { COMEDY, ACTION, DRAMA, SCIENCE_FICTION };

	Media(const Media& media);
	Media(const string& name, const int rate, const eGenre genre);

	void setName(const string& name);
	void setRate(int rate) throw(const char*);
	void setGenre(eGenre genre) throw(const char*);

	const string& getName() const;
	int getRate() const;
	eGenre getGenre() const;
	int getNumOfViews() const;

	friend ostream& operator<<(ostream& os, Media& media);
	bool operator<(const Media& other) const;
	virtual void toOs(ostream & os) const;
	operator const char*();

	void increaseViews();
	bool addActorToActorsList(Actor& actor);

protected:
	std::string name;
	int rate;
	mutable int numOfViews = 0;
	eGenre genre;
	LinkedList<Actor*> actorList;
};

#endif //_MEDIA_H