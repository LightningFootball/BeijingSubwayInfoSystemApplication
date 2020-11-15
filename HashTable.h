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

HashTable::HashTable(int dataScale)	//��Ҫ�����������Ĺ��캯��
{
	hTable.resize(hash.hashSpaceRequire());
}

int HashTable::insert(QString string)
{
	//������hashλ��Ϊ���򴢴棬�ǿ���ȥ����һλ��
	//��һλ�õ�̽Ѱ����Ϊ�������̽��
	int hashPointer;
	int i = 0;
	for (hashPointer = hash.doHash(string); !hTable.at(hashPointer).isEmpty(); ++i)
	{
		hashPointer = hashPointer + i * i;
	}
	hTable[hashPointer] = string;

	if (hTable.size() > hTable.capacity() * 0.8)	//��������ʱ�����Ƿ�ռ�õ�������ܱ߽�
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