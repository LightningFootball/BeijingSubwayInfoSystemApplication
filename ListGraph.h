#pragma once

#include "Vertex.h"
#include "Arc.h"
#include "HashTable.h"

#include <qstring.h>

using namespace std;

class ListGraph		//���ڽӱ�����ñ���Ŀ������Ǩ����������Ŀ
{
public:
	ListGraph(int vertexNum);
	int capacity();
	bool resize(int size);
	bool appendArc(int fromStationNum,int toStationNum,int distance);
	~ListGraph();

protected:
	Vertex* verties;

private:

};

ListGraph::ListGraph(int vertexNum)
{
	this->verties = new Vertex[vertexNum];
}

int ListGraph::capacity()
{
	
}

bool ListGraph::resize(int size)
{

}

bool ListGraph::appendArc(int fromStationNum, int toStationNum, int distance)
{
	//�жϲ���λ���Ƿ�Խ��

	//����
	Arc* arc = new Arc(toStationNum, distance);
	verties[fromStationNum].copyFirstArc(arc);


	return true;
}

ListGraph::~ListGraph()
{
}

class MyClass
{
public:
	MyClass();
	~MyClass();

private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}