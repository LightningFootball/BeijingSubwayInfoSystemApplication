#pragma once

#include "Hash.h"

#include <qvector.h>
#include <qstring.h>


//size capacity ���ִ���


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

HashTable::HashTable(int dataScale)	//��Ҫ�����������Ĺ��캯��
{
	hTable.resize(hash.hashSpaceRequire());
}

int HashTable::insert(QString string)	//�����򷵻ز���λ�ã������򷵻�false
{
	//������hashλ��Ϊ���򴢴棬�ǿ������Ƿ���ͬ����ͬ�򷵻�false������ͬ��ȥ����һλ��
	//��һλ�õ�̽Ѱ����Ϊ�������̽��
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

	if (volume > hTable.size() * 0.8)	//��������ʱ�����Ƿ�ռ�õ�������ܱ߽�
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