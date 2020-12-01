#pragma once

#include "Hash.h"

#include <qvector.h>
#include <qstring.h>

/*Vector�У�sizeΪVectorʵ���Ѿ�ʹ�ÿռ䣬capacityΪVectorʵ���Ѿ�����Ĵ�С�ռ�*/

class HashTable
{
public:

	QVector<QString> hTable;
	Hash hash;
	int volume;

	HashTable();
	HashTable(int dataScale);
	
	bool resize();
	bool resize(int dataScale);
	
	int insert(QString string);
	int search(QString string);
	
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
	volume = 0;
	hTable.resize(hash.hashSpaceRequire());
}

int HashTable::insert(QString string)	//�����򷵻ز���λ�ã������򷵻�false
{
	//������hashλ��Ϊ���򴢴棬�ǿ������Ƿ���ͬ����ͬ�򷵻�false������ͬ��ȥ����һλ��
	//��һλ�õ�̽Ѱ����Ϊ�������̽��
	int hashPointer=hash.doHash(string);
	while(hashPointer >= hTable.size())
	{
		resize(hashPointer);
	}

	for (int i = 0; !hTable.at(hashPointer).isEmpty(); ++i)
	{
		if (hTable.at(hashPointer)==string)
		{
			return hashPointer;
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

int HashTable::search(QString string)
{
	//����string������hash
	//����hashλ�ã���-δ��ѯ������-����Ƿ���ȣ����-���ش�ʱhashλ�á�����ȣ���һ��hashλ��
	int hashPointer = hash.doHash(string);
	for (int i=0;!hTable.at(hashPointer).isEmpty(); ++i)
	{
		if (hTable.at(hashPointer) == string)
		{
			return hashPointer;
		}
		hashPointer = (hashPointer + i * i) % hTable.size();
	}
	return false;
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