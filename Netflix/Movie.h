#ifndef _MOVIE_H
#define _MOVIE_H
#include "Media.h"
class Media;
class Movie : virtual public Media {
public:

	const int YEAR_MIN = 1970;
	const int YEAR_MAX = 2019;

	Movie(const Media& media, const int producingYear);
	Movie(const string& name, const int rate, const eGenre genre, const int producingYear);

	void setProducingYear(const int producingYear);
	int getProducingYear() const;

	void toOs(ostream & os, bool flag = false) const;

protected:
	int producingYear;
};

#endif //_MOVIE_H