#pragma once

#include "Hash.h"

#include <qvector.h>
#include <qstring.h>


class HashTable
{
public:

	QVector<QString> hTable;
	Hash hash;

	HashTable(int dataScale);
	int insert(QString string);
	bool resize();

	~HashTable();

private:

};

HashTable::HashTable(int dataScale)	//需要给出数据量的构造函数
{
	hTable.resize(hash.hashSpaceRequire());
}

int HashTable::insert(QString string)
{
	//检测如果hash位置为空则储存，非空则去到下一位置
	//下一位置的探寻规则为单向二次探查
	int hashPointer;
	int i = 0;
	for (hashPointer = hash.doHash(string); !hTable.at(hashPointer).isEmpty(); ++i)
	{
		hashPointer = hashPointer + i * i;
	}
	hTable[hashPointer] = string;

	if (hTable.size() > hTable.capacity() * 0.8)	//插入后检测此时容量是否占用到最佳性能边界
	{
		resize();
	}

	return hashPointer;
}

bool HashTable::resize()
{
	hTable.resize(hTable.capacity() / 0.75);
	return true;
}

HashTable::~HashTable()
{
}