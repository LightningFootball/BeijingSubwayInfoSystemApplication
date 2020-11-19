#pragma once

#include "Arc.h"

using namespace std;

class Vertex
{
public:
	Arc* firstArc = nullptr;

	Vertex();
	bool copyFirstArc(Arc* firstArc);
	bool newFirstArc(const Vertex& otherVertex);
	bool appendArc(Arc* arc);
	~Vertex();

private:

};

Vertex::Vertex() {

}

bool Vertex::copyFirstArc(Arc* firstArc)	//完全赋值的构造函数
{
	this->firstArc = firstArc;
}

bool Vertex::newFirstArc(const Vertex& otherVertex)	//深拷贝函数
{
	if (this != &otherVertex && 0!= &otherVertex )
	{
		this->firstArc = new Arc(*otherVertex.firstArc);
	}
}

bool Vertex::appendArc(Arc* arc)
{
	Arc* appendLocation;
	appendLocation = firstArc;
	while (appendLocation!=nullptr)
	{
		appendLocation = appendLocation->nextArc;
	}
	appendLocation = arc;
}

Vertex::~Vertex()
{
}