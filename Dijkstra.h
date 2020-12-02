#pragma once

#include "ListGraph.h"
#include "PriorityQueue.h"
#include "Arc.h"
#include "HashTable.h"
#include "DijkstraNode.h"

#include <qvector.h>
#include <string>
#include <stdio.h>
#include <qstring.h>

class Dijkstra		//�����ʱ����¼��վ��dijkstra��������ڿɰ�װΪһ���洢����վ��dijkstra�������
{
public:
	QVector<QVector<int>> dijkstraList;		//��һ�м�¼�ܾ�����Ϣ���м�¼·����Ϣ����ֵΪ�յ�Hash

	Dijkstra();
	Dijkstra(int size);

	void Dijkstra::operate(ListGraph* list, int stationHash);

	~Dijkstra();

private:
	
};

Dijkstra::Dijkstra()
{
	dijkstraList.resize(600);
	for (int i = 0; i < dijkstraList.size(); i++)
	{
		dijkstraList[i].resize(50);
	}
}

Dijkstra::Dijkstra(int size)
{
	dijkstraList.resize(size);
	for (int i = 0; i < dijkstraList.size(); i++)
	{
		dijkstraList[i].resize(50);
	}
}

void Dijkstra::operate(ListGraph* list, int stationHash)
{
	//initialize
	for (int i = 0; i < dijkstraList.size(); i++)		//distance=0
	{
		dijkstraList[i][0] = 0;
	}
	for (int i = 0; i < dijkstraList.size(); i++)		//initial station=stationHash
	{
		dijkstraList[i][1] = stationHash;
	}

	//��stationHash��ʼ�ڵ㿪ʼ������list������ɵ���ĵ㣬����buf���õ���С�ڵ�
	//���䵽����ţ�·������ͷ���յ����β��
	//��ʱ����ɷ��ʣ�ͷ��һ��0��һ���о��룩�����ɵ���㣬����buf������С�㣬
	//���䵽���ţ�����һվ�����ݿ���������append������㡣
	//�ݹ飬ֱ�����������ʼ�ڵ����
	for (int i = 0; i < dijkstraList.size()-1; i++)		//dijkstra�㷨�����·����
	{
		PriorityQueue stationBuffer;	//����·�������ʼ��һ�����ȶ���
		for (int j = 0; j < dijkstraList.size(); j++)	//����·����Ҫ����ȫ���ڵ�
		{
			if (j==stationHash||dijkstraList[j][0]!=0)	//�ڵ��е���ʼվ��������ѷ��ʽڵ�
			{
				//Arc getArc(int arcNum);
				if(list->list[j].getArc(0).stationNum != -1)	//վ��������һ���ڵ㣬���������ܲ���Ҫ
				{
					for (int i = 0; list->list[j].getArc(i).stationNum!=-1 ; i++)
					{
						DijkstraNode* tempNode = new DijkstraNode;
						tempNode->prev = j;
						tempNode->distance = list->list[j].getArc(i).distance;
						stationBuffer.push(*tempNode);
					}
				}
			}
		}
		dijkstraList[stationBuffer.at(0).distance][0] += stationBuffer.at(0).distance;
		dijkstraList[stationBuffer.at(0).prev].append(stationBuffer.at(0).prev);
	}
}

Dijkstra::~Dijkstra()
{
}