#pragma once

//负载因子以0.75为宜，总站点数在400+，所以Hash大小设置为530为宜
//对于Qstring存储的UTF-16编码，其中中文编码范围为4E00-9FBF，范围大小19968
//本hash算法采用折叠法并通过乘系数使更table大小更接近负载因子

#include <qstring.h>

using namespace std;

class Hash
{
public:

	Hash(int seed);
	Hash(unsigned short seed);
	unsigned short doHash(QString string);
	~Hash();

private:

	unsigned short seed = 1000;

};

Hash::Hash(int seed)	//int型构造函数
{
	this->seed = seed;
}

Hash::Hash(unsigned short seed)		//unsigned short型构造函数
{
	this->seed = seed;
}

unsigned short Hash::doHash(QString string)
{
	unsigned short hashRaw = string.at(0).unicode();
	unsigned short hashFinal = ((hashRaw / 100) + (hashRaw % 1000)) * (seed / 0.75 / 1000);
	
	return hashFinal;
	
}

Hash::~Hash()
{
}

class HashTable
{
public:
	HashTable();
	~HashTable();

private:

};

HashTable::HashTable()
{
}

HashTable::~HashTable()
{
}