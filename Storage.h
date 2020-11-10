#pragma once

#include <qvector.h>
#include <qstring.h>

#include "Arc.h"

using namespace std;

class vertex
{
public:
	Arc* firstArc = nullptr;

	vertex(const Arc* firstArc);
	~vertex();

private:
	
};

vertex::vertex(const Arc* firstArc)
{

}

vertex::~vertex() {

}




vertex::~vertex()
{
}


template <typename T>
class stationList
{
public:
	stationList();
	~stationList();

private:
	
};

stationList::stationList()
{
}

stationList::~stationList()
{
}