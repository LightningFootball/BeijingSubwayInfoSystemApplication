#pragma once

#include "Vertex.h"
#include "Arc.h"
#include "HashTable.h"

#include <qstring.h>

using namespace std;

class ListGraph		//该邻接表仅适用本项目，不可迁移至其他项目
{
public:
	ListGraph();
	ListGraph(int vertexNum);
	int capacity();
	bool resize(int size);
	bool insert(int fromStationNum,int toStationNum,int distance);
	~ListGraph();
	
	Vertex* verties;
protected:
	

private:

};

ListGraph::ListGraph()
{
	this->verties = new Vertex[1000];
}

ListGraph::ListGraph(int vertexNum)
{
	this->verties = new Vertex[vertexNum];
}

int ListGraph::capacity()
{
	return true;
}

bool ListGraph::resize(int size)
{
	return true;
}

bool ListGraph::insert(int fromStationNum, int toStationNum, int distance)
{
	//判断插入位置是否越界

	//插入
	Arc* arc = new Arc(toStationNum, distance);
	verties[fromStationNum].appendArc(arc);

	return true;
}

ListGraph::~ListGraph()
{
}