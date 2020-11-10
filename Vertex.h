#pragma once

#include "Arc.h"

using namespace std;

class Vertex
{
public:
	Arc* firstArc = nullptr;

	Vertex();
	Vertex(Arc* firstArc);
	Vertex(const Vertex& otherVertex);
	~Vertex();

private:

};

Vertex::Vertex() {

}

Vertex::Vertex(Arc* firstArc)	//完全赋值的构造函数
{
	this->firstArc = firstArc;
}

Vertex::Vertex(const Vertex& otherVertex)
{
	if (this != &otherVertex && 0!= &otherVertex )
	{
		this->firstArc = new Arc(*otherVertex.firstArc);
	}
}

Vertex::~Vertex()
{
}