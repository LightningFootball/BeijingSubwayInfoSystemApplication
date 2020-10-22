#pragma once



#define LINENUM(NUM)\
QString aLineSTRING##NUM = infoFile.readLine();\
QString aLineSTRING_TRIMMED##NUM = aLineSTRING##NUM.trimmed();\
QStringList readLineSpilted##NUM = aLineSTRING_TRIMMED##NUM.split(' ');\
stationHead line##NUM;\
line##NUM.lineNum = readLineSpilted##NUM.at(0).toInt();\
cout << line##NUM.lineNum << endl;\
line##NUM.lineName = readLineSpilted##NUM.at(1);\
cout << line##NUM.lineName << endl;\
line##NUM.totalStationNum = readLineSpilted##NUM.at(2).toInt();\
cout << line##NUM.totalStationNum << endl;\
QVector<station> stationList##NUM(line##NUM.totalStationNum);\
for (int i = 3; i < readLineSpilted##NUM.count(); i++)\
{\
	if (readLineSpilted##NUM.at(i).toInt() > 0 && readLineSpilted##NUM.at(i).toInt() < 99999)\
	{\
		stationList##NUM[(i - 2) / 2 - 1].nextStationDistance = readLineSpilted##NUM.at(i).toInt();\
	}\
	else\
	{\
		stationList##NUM[(i - 1) / 2 - 1].stationName = readLineSpilted##NUM.at(i);\
	}\
}\
for (int i = 0; i < stationList##NUM.count(); i++)\
{\
	cout << stationList##NUM[i].stationName << stationList##NUM[i].nextStationDistance << endl;\
}\

#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>

#include<qstring.h>
#include<qfile.h>
#include<qtextstream.h>

//#pragma execution_character_set("utf-8")


//head for test
#include <iostream>

using namespace std;

struct stationHead
{
	QString lineName;
	int lineNum;
	int totalStationNum;
	int* stationPtr = nullptr;
};

struct station
{
	QString stationName;
	int nextStationDistance = 0;
	int* exchangeListPtr = nullptr;
};

struct exchangeList
{
	int* exchangeLine1 = nullptr;
	int* exchangeLine2 = nullptr;
};

int dataProcess() {
	QFile infoFile("SubwayInfoDatabase.txt");
	infoFile.open(QIODevice::ReadOnly);		//open file
	QTextStream cout(stdout, QIODevice::WriteOnly);

	QString totalLineNumSTRING;
	totalLineNumSTRING = infoFile.readLine();
	int totalLineNum = totalLineNumSTRING.toInt();

	for (int i = 0; i < totalLineNum; i++)
	{
		LINENUM(i);
	}

	return 0;
}

//int dataProcess() {
//	QFile infoFile("SubwayInfoDatabase.txt");
//	infoFile.open(QIODevice::ReadOnly);		//open file
//
//	QString totalLineNumSTRING;
//	totalLineNumSTRING = infoFile.readLine();	//read first line as qstring
//	int totalLineNum = totalLineNumSTRING.toInt(nullptr, 10);	//qstring to int
//
//	QTextStream cout(stdout, QIODevice::WriteOnly);		//allow qstring could cout
//	cout << totalLineNum << endl;	//console
//
//	QString aLineSTRING = infoFile.readLine();
//	QString aLineSTRING_TRIMMED = aLineSTRING.trimmed();		//tail trimmed
//	QStringList readLineSpilted = aLineSTRING_TRIMMED.split(' ');		//spilt by space
//
//	stationHead line1;
//	line1.lineNum = readLineSpilted.at(0).toInt();
//	cout << line1.lineNum << endl;	//console
//	line1.lineName = readLineSpilted.at(1);
//	cout << line1.lineName << endl;	//console
//	line1.totalStationNum = readLineSpilted.at(2).toInt();
//	cout << line1.totalStationNum << endl;
//	
//
//	QVector<station> stationList(line1.totalStationNum);
//	for (int i = 3; i < readLineSpilted.count(); i++)
//	{
//		if (readLineSpilted.at(i).toInt()>0&&readLineSpilted.at(i).toInt()<99999)	//if num
//		{
//			stationList[(i - 2) / 2 - 1].nextStationDistance = readLineSpilted.at(i).toInt();
//		}
//		else
//		{
//			stationList[(i - 1) / 2 - 1].stationName = readLineSpilted.at(i);
//		}
//	}
//	for (int i = 0; i < stationList.count(); i++)
//	{
//		cout << stationList[i].stationName << stationList[i].nextStationDistance << endl;
//	}
//
//	return 0;
//}