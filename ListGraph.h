#pragma once

#include "Vertex.h"
#include "Arc.h"
#include "HashTable.h"

#include <qstring.h>

using namespace std;

class ListGraph		//���ڽӱ�����ñ���Ŀ������Ǩ����������Ŀ
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
	//�жϲ���λ���Ƿ�Խ��

	//����
	Arc* arc = new Arc(toStationNum, distance);
	verties[fromStationNum].appendArc(arc);

	return true;
}

ListGraph::~ListGraph()
{
}