#pragma once

#include "Vertex.h"
#include "Arc.h"
#include "HashTable.h"

#include <qstring.h>
#include <qvector.h>

using namespace std;

class ListGraph		//该邻接表仅适用本项目，不可迁移至其他项目
{
public:
	ListGraph();
	ListGraph(int vertexNum);		//赋值构造

	int size();
	void resize(int size);

	void insert(int fromStationNum,int toStationNum,int distance);

	QVector<Vertex> list;

	~ListGraph();
protected:
	

private:

};

ListGraph::ListGraph()
{
	list.resize(10);
}

ListGraph::ListGraph(int vertexNum)
{
	list.resize(vertexNum);
}

int ListGraph::size()
{
	return list.size();
}

void ListGraph::resize(int size)
{
	list.resize(size);
}

void ListGraph::insert(int fromStationNum, int toStationNum, int distance)
{
	//判断插入位置是否越界
	while(fromStationNum>=list.size())
	{
		resize(this->size() / 0.75);
	}
	
	//插入
	Arc* arc = new Arc(toStationNum, distance);
	list[fromStationNum].appendArc(arc);
}

ListGraph::~ListGraph()
{
	
}