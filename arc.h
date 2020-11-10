#pragma once

class Arc
{
public:
	int stationNum = -1;
	int distance = -1;
	Arc* nextArc = nullptr;

	Arc(int stationNum, int distance);
	Arc(int stationNum, int distance, Arc* nextArc);
	Arc(const Arc& otherArc);
	~Arc();

private:

};

Arc::Arc(int stationNum, int distance)	//���ڽӵĹ��캯��
{
	this->stationNum = stationNum;
	this->distance = distance;
}

Arc::Arc(int stationNum, int distance, Arc* nextArc)	//��ȫ��ֵ�Ĺ��캯��
{
	this->stationNum = stationNum;
	this->distance = distance;
	this->nextArc = nextArc;
}

Arc::Arc(const Arc& otherArc)	//ǳ�����Ĺ��캯��
{
	if (this != &otherArc && 0!=&otherArc)
	{
		this->stationNum = otherArc.stationNum;
		this->distance = otherArc.distance;
		this->nextArc = otherArc.nextArc;
	}
}

Arc::~Arc()
{
}