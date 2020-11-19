#pragma once

#include "Hash.h"

#include <qvector.h>
#include <qstring.h>


class HashTable
{
public:

	QVector<QString> hTable;
	Hash hash;

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
	hTable.resize(10);
}

HashTable::HashTable(int dataScale)	//��Ҫ�����������Ĺ��캯��
{
	hTable.resize(hash.hashSpaceRequire());
}

int HashTable::insert(QString string)	//�����򷵻ز���λ�ã������򷵻�false
{
	//������hashλ��Ϊ���򴢴棬�ǿ������Ƿ���ͬ����ͬ�򷵻�false������ͬ��ȥ����һλ��
	//��һλ�õ�̽Ѱ����Ϊ�������̽��
	int hashPointer;
	int i = 0;
	for (hashPointer = hash.doHash(string); !hTable.at(hashPointer).isEmpty(); ++i)
	{
		if (hTable.at(hashPointer)==string)
		{
			return false;
		}
		hashPointer = hashPointer + i * i;
	}
	if (hashPointer>hTable.capacity())
	{
		resize(hashPointer);
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

bool HashTable::resize(int dataScale)
{
	hTable.resize(dataScale / 0.75);
	return true;
}

HashTable::~HashTable()
{
}