#ifndef _SERIE_H
#define _SERIE_H
#include "Media.h"
class Media;
class Serie : virtual public Media {
public:

	const int MIN = 0;

	Serie(const Media& media, int numOfSeasons = 1);
	Serie(const string&, const int rate, const eGenre genre, const int NumOfSeasons);

	void setNumOfSeasons(const int NumOfSeasons);
	int getNumOfSeasons() const;

	void toOs(ostream & os, bool flag = false) const;

protected:
	int numOfSeasons;
};

#endif //_SERIE_H