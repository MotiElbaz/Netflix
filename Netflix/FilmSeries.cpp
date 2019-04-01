#include "FilmSeries.h"

FilmSeries::FilmSeries(const Media& media, const Movie& movie, const Serie& serie) throw(const char*) : Media(media), Movie(movie), Serie(serie)
{

}

void FilmSeries::toOs(ostream & os)
{
	os << "Film Serie : \n";
	Movie::toOs(os, true);
	Serie::toOs(os, true);
}

const string FilmSeries::getType() const { return "FilmSeries"; }

