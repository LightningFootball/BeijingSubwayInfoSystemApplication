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

using namespace std;

void dijkstra(ListGraph &list, int stationNum,int size)
{
	QVector<DijkstraNode> dijVector(size);	//dij存储vector
	
	dijVector[stationNum].distance = 0;	//起始节点初始
	dijVector[stationNum].prev = stationNum;
	PriorityQueue* bu;
	for (int i = 0; i < size-1; i++)	//遍历次数为所有非起始节点个数
	{
		bu = new PriorityQueue;
		for (int j = 0; j < size; j++)	//所有节点中
		{
			if (dijVector[j].prev!=-1)	//只要访问了
			{
				Arc* validPointer = list.verties[j].firstArc;	//访问节点的邻接
				while (validPointer != nullptr)
				{
					DijkstraNode temp(validPointer->distance, j);
					bu->push(temp);						//push邻接节点
					validPointer = validPointer->nextArc;
				}
			}
		}
		int numSmall = bu->at(0).prev;
		pop出最小
		dijVector[numSmall] = bu->at(0);
	}

	for (int i = 0; i < dijVector.size(); i++)
	{
		cout << dijVector.at(i).distance << endl;
	}
}