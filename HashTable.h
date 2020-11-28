#pragma once

#include "Hash.h"

#include <qvector.h>
#include <qstring.h>


//size capacity 区分待看


class HashTable
{
public:

	QVector<QString> hTable;
	Hash hash;
	int volume;

	HashTable();
	HashTable(int dataScale);
	int insert(QString string);
	bool resize();
	bool resize(int dataScale);

	~HashTable();

private:

};

HashTable::HashTable()
{
	volume = 0;
	hTable.resize(10);
}

HashTable::HashTable(int dataScale)	//需要给出数据量的构造函数
{
	hTable.resize(hash.hashSpaceRequire());
}

int HashTable::insert(QString string)	//插入则返回插入位置，存在则返回false
{
	//检测如果hash位置为空则储存，非空则检测是否相同，相同则返回false，不相同则去到下一位置
	//下一位置的探寻规则为单向二次探查
	int hashPointer=hash.doHash(string);
	if (hashPointer >= hTable.size())
	{
		resize(hashPointer);
	}
	int i = 0;
	for (; !hTable.at(hashPointer).isEmpty(); ++i)
	{
		if (hTable.at(hashPointer)==string)
		{
			return false;
		}
		hashPointer = (hashPointer + i * i)%hTable.size();
	}
	
	hTable[hashPointer] = string;
	++volume;

	if (volume > hTable.size() * 0.8)	//插入后检测此时容量是否占用到最佳性能边界
	{
		resize();
	}

	return hashPointer;
}

bool HashTable::resize()
{
	hTable.resize(hTable.size() / 0.75);
	return true;
}

bool HashTable::resize(int dataScale)
{
	hTable.resize(dataScale / 0.75);
	return true;
}

HashTable::~HashTable()
{
}