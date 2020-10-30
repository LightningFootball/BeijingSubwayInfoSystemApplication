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
	struct exchangeStation* next = NULL;
};

struct exchangeStation
{
	int stationNum=-1;
	int distance=0;
	struct exchangeStation* next = NULL;
};

int dataProcess() {
	QFile infoFile("SubwayInfoDatabase.txt");
	infoFile.open(QIODevice::ReadOnly);		//open file

	
	QString totalLineNumSTRING = infoFile.readLine();
	int totalLineNum = totalLineNumSTRING.toInt();

	QTextStream cout(stdout, QIODevice::WriteOnly);		//allow qstring could cout
	cout << totalLineNum << endl;	//console
	
	QVector<station> stationList;
	for (int i = 0; i < totalLineNum; i++)
	{
		QString aLineSTRING = infoFile.readLine();
		QString aLineSTRING_TRIMMED = aLineSTRING.trimmed();		//tail trimmed
		QStringList readLineSpilted = aLineSTRING_TRIMMED.split(' ');		//spilt by space

		int lineNum = readLineSpilted.at(0).toInt();
		cout << lineNum << endl;	//console
		QString lineName = readLineSpilted.at(1);
		cout << lineName << endl;	//console
		int lineTotalStationNum = readLineSpilted.at(2).toInt();
		cout << lineTotalStationNum << endl;

		for (int i = 3; i < readLineSpilted.size(); i = i + 2)
		{
			station curStation;
			curStation.stationName = readLineSpilted.at(i);
			//curStation.stationNameSplit = curStation.stationName.split("");
			
			exchangeStation curExchangeStation;
			if (readLineSpilted.at(i + 1).toInt()!=0 && (i < readLineSpilted.size() - 3))
			{	
				curStation.next = &curExchangeStation;
				curExchangeStation.distance = readLineSpilted.at(i + 1).toInt();
				curExchangeStation.stationNum = stationList.size() + 1;
			}
			else if ( (readLineSpilted.at(i + 1).toInt() != 0) && (i>=readLineSpilted.size()-3) )  //error
			{
				curExchangeStation.stationNum = stationList.size()-lineTotalStationNum+1;
			}
			else if (readLineSpilted.at(i + 1).toInt() == 0)
			{

			}

			stationList.append(curStation);			
			
			cout<< stationList.size()-1 <<' '<< curStation.stationName << ' ' /*<< curStation.stationNameSplit.size() << ' '*/ << curExchangeStation.stationNum << ' ' << curExchangeStation.distance << endl;
		}
	}
	
	


	//for (int i = 3; i < readLineSpilted.count(); i++)
	//{
	//	if (readLineSpilted.at(i).toInt()>0&&readLineSpilted.at(i).toInt()<99999)	//if num
	//	{
	//		stationList[(i - 2) / 2 - 1].nextStationDistance = readLineSpilted.at(i).toInt();
	//	}
	//	else
	//	{
	//		stationList[(i - 1) / 2 - 1].stationName = readLineSpilted.at(i);
	//	}
	//}
	//for (int i = 0; i < stationList.count(); i++)
	//{
	//	cout << stationList[i].stationName << stationList[i].nextStationDistance << endl;
	//}

	return 0;
}