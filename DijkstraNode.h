#pragma once

class DijkstraNode
{
public:
	int distance = -1;
	int prev = -1;

	DijkstraNode();
	DijkstraNode(int distance, int prev);
	DijkstraNode operator=(const DijkstraNode& node);
	~DijkstraNode();

private:

};

DijkstraNode::DijkstraNode()
{
}

DijkstraNode::DijkstraNode(int distance, int prev)
{
	this->distance = distance;
	this->prev = prev;
}

DijkstraNode DijkstraNode::operator=(const DijkstraNode& node)
{
	this->distance = node.distance;
	this->prev = node.prev;
	
	return *this;
}

DijkstraNode::~DijkstraNode()
{
}