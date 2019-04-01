#ifndef _FilmSeries_H
#define _FilmSeries_H

#include "Movie.h"
#include "Serie.h"
class FilmSeries : public Movie, public Serie {
public:
	FilmSeries(const Media& media,const Movie& movie, const Serie& serie) throw(const string&);
	void toOs(ostream & os);
	const string getType() const;
};

#endif //_FilmSeries_H