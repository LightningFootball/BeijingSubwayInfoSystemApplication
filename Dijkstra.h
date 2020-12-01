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
	QVector<DijkstraNode> dijVector(size);	//dij�洢vector
	
	dijVector[stationNum].distance = 0;	//��ʼ�ڵ��ʼ
	dijVector[stationNum].prev = stationNum;
	PriorityQueue* bu;
	for (int i = 0; i < size-1; i++)	//��������Ϊ���з���ʼ�ڵ����
	{
		bu = new PriorityQueue;
		for (int j = 0; j < size; j++)	//���нڵ���
		{
			if (dijVector[j].prev!=-1)	//ֻҪ������
			{
				Arc* validPointer = list.verties[j].firstArc;	//���ʽڵ���ڽ�
				while (validPointer != nullptr)
				{
					DijkstraNode temp(validPointer->distance, j);
					bu->push(temp);						//push�ڽӽڵ�
					validPointer = validPointer->nextArc;
				}
			}
		}
		int numSmall = bu->at(0).prev;
		pop����С
		dijVector[numSmall] = bu->at(0);
	}

	for (int i = 0; i < dijVector.size(); i++)
	{
		cout << dijVector.at(i).distance << endl;
	}
}