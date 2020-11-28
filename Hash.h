#pragma once

//����������0.75Ϊ�ˣ���վ������400+������Hash��С����Ϊ530Ϊ��
//����Qstring�洢��UTF-16���룬�������ı��뷶ΧΪ4E00-9FBF����Χ��С19968
//��hash�㷨�����۵�����ͨ����ϵ��ʹ��table��С���ӽ���������

#include <qstring.h>
#include <qvector.h>

class Hash	//����������ڶ�Qstring�ĵ�һ���ֽ���Hash�������ƹ�
{
public:
	Hash();
	Hash(int dataScale);
	int hashSpaceRequire();
	int doHash(QString string);
	~Hash();

protected:

	int dataScale;

};

Hash::Hash() {
	dataScale = 0;
}

Hash::Hash(int dataScale)	//int�͹��캯��
{
	this->dataScale = dataScale;
}

int Hash::hashSpaceRequire()	//����hash�����С
{
	return dataScale/0.75;
}

int Hash::doHash(QString string)	//����hashֵ
{
	int hashRaw = string.at(0).unicode();
	int hashFinal = hashRaw / 120;
	
	return hashFinal;
	
}

Hash::~Hash()
{
}