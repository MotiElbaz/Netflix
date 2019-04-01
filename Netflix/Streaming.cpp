#include "Streaming.h"

Streaming Streaming::theStreaming;

Streaming::Streaming(const string& name)
{
	this->setName(name);
}

void Streaming::notifyAllRegistered(Media* media)
{
	vector<User>::iterator itrBegin = this->viewers.begin();
	vector<User>::iterator itrEnd = this->viewers.end();
	for (; itrBegin != itrEnd; ++itrBegin)
	{
		(*itrBegin).notify(media);
	}
}

Streaming* Streaming::getInstance()
{
	return &theStreaming;
}

void Streaming::registerObserver(User * u)
{
	viewers.push_back(*u);
}

const string& Streaming::getName() const
{
	return this->name;
}

vector<Media*>* Streaming::getTopRatedMediaByN(const int quantity)
{
	vector<Media*> *tempList = new vector<Media*>();
	sort(this->mediaList.begin(),this->mediaList.end());
	vector<Media*>::iterator itrBegin = this->mediaList.begin();
	vector<Media*>::iterator itrEnd = this->mediaList.end();
	for (int i = 0 ; itrBegin != itrEnd && i < quantity; ++itrBegin ,i++)
	{
		tempList->push_back(*itrBegin);
	}
	return tempList;
}

Media* Streaming::getSerieWithMaxEpisodes()
{
	Serie* serieWithMax = nullptr;
	vector<Media*>::iterator itrBegin = this->mediaList.begin();
	vector<Media*>::iterator itrEnd = this->mediaList.end();
	for (int i = 0; itrBegin != itrEnd ; ++itrBegin)
	{
		Serie* temp = dynamic_cast<Serie*>(*itrBegin);
		if (temp)
		{
			if (serieWithMax == nullptr)
			{
				serieWithMax = temp;
			}
			else
			{
				if (serieWithMax->getNumOfSeasons() < temp->getNumOfSeasons())
				{
					serieWithMax = temp;
				}
			}
		}
	}
	return serieWithMax;
}

void Streaming::setName(const string& name)
{
	this->name = name;
}

const Streaming& Streaming::operator+=(Media& media)
{
	vector<Media*>::iterator itrBegin = this->mediaList.begin();
	vector<Media*>::iterator itrEnd = this->mediaList.end();
	for (; itrBegin != itrEnd; ++itrBegin)
	{
		if (*itrBegin == &media)
		{
			throw string("Media already exist.");
		}
	}
	this->mediaList.push_back(&media);
	this->notifyAllRegistered(&media);
	return *this;
}

const Streaming& Streaming::operator-=(Media & media)
{
	vector<Media*> temp;
	vector<Media*>::iterator itrBegin = this->mediaList.begin();
	vector<Media*>::iterator itrEnd = this->mediaList.end();
	for (; itrBegin != itrEnd; ++itrBegin)
	{
		if (*itrBegin != &media)
		{
			temp.push_back(&media);
		}
	}
	this->mediaList = temp;
	return *this;
}

Streaming::operator const char*()
{
	return name.c_str();
}
