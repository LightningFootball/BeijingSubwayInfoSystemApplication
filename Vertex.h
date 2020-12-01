#pragma once

#include "Arc.h"

using namespace std;

class Vertex
{
public:
	

	Vertex();
	bool copyFirstArc(Arc* firstArc);
	bool newFirstArc(const Vertex& otherVertex);
	bool appendArc(Arc* arc);
	~Vertex();

private:
	Arc* firstArc = nullptr;
};

Vertex::Vertex() {
	this->firstArc = nullptr;
}

bool Vertex::copyFirstArc(Arc* firstArc)	//��ȫ��ֵ�Ĺ��캯��
{
	this->firstArc = firstArc;
	return true;
}

bool Vertex::newFirstArc(const Vertex& otherVertex)	//�������
{
	if (this != &otherVertex && 0!= &otherVertex )
	{
		this->firstArc = new Arc(*otherVertex.firstArc);
	}
	return true;
}

bool Vertex::appendArc(Arc* arc)
{
	if (firstArc==nullptr)
	{
		firstArc = arc;
		return true;
	}
	Arc* buoy;		//buoy ����
	buoy = firstArc;
	while (buoy->nextArc != nullptr)
	{
		buoy = buoy->nextArc;
	}
	buoy->nextArc = arc;
	return true;
}

Vertex::~Vertex()
{
}