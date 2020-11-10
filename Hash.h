#pragma once

//����������0.75Ϊ�ˣ���վ������400+������Hash��С����Ϊ530Ϊ��
//����Qstring�洢��UTF-16���룬�������ı��뷶ΧΪ4E00-9FBF����Χ��С19968
//��hash�㷨�����۵�����ͨ����ϵ��ʹ��table��С���ӽ���������

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

Hash::Hash(int seed)	//int�͹��캯��
{
	this->seed = seed;
}

Hash::Hash(unsigned short seed)		//unsigned short�͹��캯��
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