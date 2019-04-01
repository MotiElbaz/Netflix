#ifndef _STREAMING_H
#define _STREAMING_H
#include <algorithm>
#include <vector>
#include "Media.h"
#include "Serie.h"
#include "IObserver.h"
#include "User.h"
using namespace std;

class Streaming {
private:
	std::string name;
	vector<Media*> mediaList;
	static Streaming theStreaming;
	vector<User> viewers;

	Streaming(const string& name = "Netflix");

	void notifyAllRegistered(Media* media);

public:

	static Streaming* getInstance();

	void registerObserver(User * u);

	void setName(const string& name);
	const string& getName() const;

	vector<Media*>* getTopRatedMediaByN(const int quantity);
	Media* getSerieWithMaxEpisodes();

	const Streaming& operator+=(Media& media);
	const Streaming& operator-=(Media & media);
	operator const char*();

};

#endif //_STREAMING_H