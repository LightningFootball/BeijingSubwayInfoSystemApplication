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

class Dijkstra		//该类此时仅记录单站点dijkstra结果，后期可包装为一个存储所有站点dijkstra结果的类
{
public:
	QVector<QVector<int>> dijkstraList;		//第一列记录总距离信息，行记录路线信息，行值为终点Hash

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

	//从stationHash起始节点开始，访问list，看其可到达的点，加入buf，得到最小节点
	//看其到达点编号，路径放入头，终点加入尾部
	//此时两点可访问（头部一个0，一个有距离），看可到达点，加入buf，得最小点，
	//看其到达编号，讲上一站点数据拷贝过来，append上这个点。
	//递归，直到距离除了起始节点非零
	for (int i = 0; i < dijkstraList.size()-1; i++)		//dijkstra算法计算得路径数
	{
		PriorityQueue stationBuffer;	//单次路径计算初始化一次优先队列
		for (int j = 0; j < dijkstraList.size(); j++)	//单次路径需要遍历全部节点
		{
			if (j==stationHash||dijkstraList[j][0]!=0)	//节点中的起始站点或者是已访问节点
			{
				//Arc getArc(int arcNum);
				if(list->list[j].getArc(0).stationNum != -1)	//站点有至少一个节点，该条件可能不必要
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