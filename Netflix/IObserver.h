#pragma once
#include <string>
#include "Media.h"
using namespace std;

class IObserver
{
public:
	virtual void notify(Media* media);
}; // IObserver
