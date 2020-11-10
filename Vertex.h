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

Vertex::Vertex(Arc* firstArc)	//��ȫ��ֵ�Ĺ��캯��
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