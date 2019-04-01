#include "Streaming.h"
#include "FilmSeries.h"
#include "User.h"
#include "Actor.h"
#include "LinkedList.h"
/*
void main()
{
int temp;
try
{
Date d(1992, 10, 5);
CreditCard cd(12345678, 8, 1992);
Person p("Moti", 1234, 22, 8, 1992);
Actor a(p);
Media m("Harry Potter", 9, Media::eGenre::SCIENCE_FICTION);
a.addMediaToMediaList(m);
cout << a << endl;
m.addActorToActorsList(a);
Movie movie(m, 2000);
cout << movie;
Media m2("Games of Thrones", 10, Media::eGenre::SCIENCE_FICTION);
Serie s(m2, 8);
s.addActorToActorsList(a);
cout << s;
Serie s2(m, 7);
FilmSeries fs(m, movie, s2);
cout << fs;
Streaming streaming;
streaming += s;
streaming += s2;
}
catch (const char* msg)
{
cout << msg << endl;
}
cin >> temp;
}
*/

void main() {
	try
	{
		//create new streaming
		Streaming *netflix = Streaming::getInstance();
		//create new movie->Media,actor->person
		Person person1("amit", 2030, 10, 5, 1992);
		Actor actor(person1);
		User amit("amit", 2030, 10, 5, 1992, 12345678, 11, 2019);
		cout << amit << endl;
		netflix->registerObserver(&amit);
		Movie americanPaiMovie(Media("American pai", 8, Media::eGenre::COMEDY), 2001);
		Media harryMedia("harry potter", 9, Media::eGenre::SCIENCE_FICTION);
		Media got("GOT", 10, Media::eGenre::SCIENCE_FICTION);
		Media grownups("Grown ups", 4, Media::eGenre::COMEDY);
		Movie harryMovie(harryMedia, 1990);
		Serie harrySerie(harryMedia);
		FilmSeries filmHarry(harryMedia, harryMovie, harrySerie);
		//amit.watchMedia(americanPaiMovie);
		*netflix += harrySerie;
		*netflix += americanPaiMovie;
		*netflix += got;
		*netflix += grownups;
		cout << (americanPaiMovie < harryMovie) << endl;
		cout << harryMovie;
		LinkedList<Media*> list;
		list.insert(&americanPaiMovie);
		list.insert(&harrySerie);
		list.print();
		list.remove(&harrySerie);
		list.print();
		int size = 4;
		vector<Media*>* vec = (*netflix).getTopRatedMediaByN(size);
		vector<Media*>::iterator itrBegin = vec->begin();
		vector<Media*>::iterator itrEnd = vec->end();
		cout << "Top 4 medias:" << endl;
		for (; itrBegin != itrEnd; ++itrBegin)
		{
			Media* m = *itrBegin;
			cout << *m << endl;
		}
		cout << "Serie with max episodes: " << *((*netflix).getSerieWithMaxEpisodes()) << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	system("pause");
}

