#pragma once

#include "DijkstraNode.h"

#include<qvector.h>

class PriorityQueue {
public:

	PriorityQueue();
	~PriorityQueue();

	void push(const DijkstraNode& node);
	DijkstraNode pop();
	bool empty();
	DijkstraNode at(int num);

private:
	QVector<DijkstraNode> heap;
	int size;

};


PriorityQueue::PriorityQueue()
{
	size = 0;
}


PriorityQueue::~PriorityQueue()
{
	
}


void PriorityQueue::push(const DijkstraNode& node)
{
	int i = size++;
	heap.append(node);
	while (i > 0) {
		int father = (i - 1) / 2;
		if (heap[father].distance <= node.distance)
		{
			break;
		}
		heap[i] = heap[father];
		i = father;
	}
	heap[i] = node;
}


DijkstraNode PriorityQueue::pop()
{
	DijkstraNode ret = heap[0];
	DijkstraNode x = heap[--size];
	int i = 0;
	while (i * 2 + 1 < size) {
		int a = i * 2 + 1, b = i * 2 + 2;
		if (b < size && heap[b].distance < heap[a].distance)
		{
			a = b;
		}
		if (x.distance <= heap[a].distance)
		{
			break;
		}
		heap[i] = heap[a];
		i = a;
	}
	heap[i] = x;
	heap.pop_back();
	return ret;
}


DijkstraNode PriorityQueue::at(int num)
{
	return heap[num];
}


bool PriorityQueue::empty()
{
	return size == 0;
}