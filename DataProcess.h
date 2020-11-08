#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>

#include<qstring.h>
#include<qfile.h>
#include<qtextstream.h>

//head for test
#include <iostream>

using namespace std;

struct station
{
	QString stationName;
	//QStringList stationNameSplit;
	struct exchangeStation* next = nullptr;
};

struct exchangeStation
{
	int stationNum=-1;
	int distance=-1;
	struct exchangeStation* next = nullptr;
};

int dataProcess() {
	QFile infoFile("SubwayInfoDatabase.txt");
	infoFile.open(QIODevice::ReadOnly);		//open file

	
	QString totalLineNumSTRING = infoFile.readLine();
	int totalLineNum = totalLineNumSTRING.toInt();

	QTextStream cout(stdout, QIODevice::WriteOnly);		//allow qstring could cout
	cout << totalLineNum << endl;	//console
	
	QList<station> stationList;

	for (int i = 0; i < totalLineNum; i++)
	{
		QString aLineSTRING = infoFile.readLine();
		QString aLineSTRING_TRIMMED = aLineSTRING.trimmed();		//tail trimmed
		QStringList readLineSpilted = aLineSTRING_TRIMMED.split(' ');		//spilt by space

		int lineNum = readLineSpilted.at(0).toInt();
		QString lineName = readLineSpilted.at(1);
		int lineTotalStationNum = readLineSpilted.at(2).toInt();
		
		for (int i = 3; i < readLineSpilted.size(); i = i + 2)
		{
			
			station* curStation = new station;
			exchangeStation nextExchangeStation, prevExchangeStation;
			stationList.append(curStation);

			

			curStation.stationName = readLineSpilted.at(i);
			
			if (readLineSpilted.at(i + 1).toInt()!=0 && (i < readLineSpilted.size() - 3))
			{	
				nextExchangeStation.distance = readLineSpilted.at(i + 1).toInt();
				nextExchangeStation.stationNum = stationList.size()+1;
			}
			else if ( (readLineSpilted.at(i + 1).toInt() != 0) && (i>=readLineSpilted.size()-3) )	//loop line last station
			{
				nextExchangeStation.distance = 0;	//last station
				nextExchangeStation.stationNum = stationList.size()-lineTotalStationNum+1;
			}
		}
		


		//for (int i = stationList.size() - lineTotalStationNum; i < stationList.size(); i++)
		//{
		//	if (i > stationList.size() - lineTotalStationNum)
		//	{
		//		stationList.at(i).next->next->distance = stationList.at(i - 1).next->distance;
		//	}
		//	else if (i = stationList.size() - lineTotalStationNum)
		//	{
		//		stationList.at(i).next->next->distance = 0;	//start station
		//	}
		//}
	}

	//for (int i = 0; i < stationList.size(); i++)
	//{
	//	cout << i /*station number of the whole vector*/ << ' ' << stationList.at(i).stationName << ' ' /*<< curStation.stationNameSplit.size() << ' '*/ << stationList.at(i).next->stationNum << ' ' << stationList.at(i).next->distance << ' ' << stationList.at(i).next->next->stationNum << ' ' << stationList.at(i).next->next->distance << endl;
	//}


	int* pointer[10];
	for (int i = 0; i < 10; i++)
	{
		int temp = i;
		pointer[i] = &temp;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << *pointer[i] << endl;
	}

	return 0;
}

