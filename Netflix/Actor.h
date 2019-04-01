#ifndef _ACTOR_H
#define _ACTOR_H
#include <vector>
#include "Person.h"
#include "Media.h"
class Media;
class Actor : public Person {
public:

	Actor(const Person& person);
	Actor(const string& name, const int id, const  int day, const int month, const int year);

	vector<Media*> getMediaList() const;

	bool addMediaToMediaList(Media& media);

	void toOs(ostream & os);

private:
	vector<Media*> mediaList;
};

#endif //_ACTOR_H