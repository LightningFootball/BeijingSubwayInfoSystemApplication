#pragma once

#include "Vertex.h"
#include "Arc.h"
#include "HashTable.h"

#include <qstring.h>
#include <qvector.h>

using namespace std;

class ListGraph		//���ڽӱ�����ñ���Ŀ������Ǩ����������Ŀ
{
public:
	ListGraph();
	ListGraph(int vertexNum);		//��ֵ����

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
	//�жϲ���λ���Ƿ�Խ��
	while(fromStationNum>=list.size())
	{
		resize(this->size() / 0.75);
	}
	
	//����
	Arc* arc = new Arc(toStationNum, distance);
	list[fromStationNum].appendArc(arc);
}

ListGraph::~ListGraph()
{
	
}