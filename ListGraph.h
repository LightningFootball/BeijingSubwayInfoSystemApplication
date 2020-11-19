#pragma once

#include "Vertex.h"
#include "Arc.h"
#include "HashTable.h"

#include <qstring.h>

using namespace std;

class ListGraph		//该邻接表仅适用本项目，不可迁移至其他项目
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
	//判断插入位置是否越界

	//插入
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