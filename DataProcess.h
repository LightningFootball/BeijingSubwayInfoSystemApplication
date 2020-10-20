#pragma once

#include <string>
#include <fstream>
#include <vector>

//head for test
#include <iostream>

using namespace std;

struct station
{
	string stationName = NULL;
	int nextStationDistance = 0;
	int* exchangeListPtr = nullptr;
};

struct exchangeList
{
	int* exchangeLine1 = nullptr;
	int* exchangeLine2 = nullptr;
};

int dataProcess() {
	fstream fin;
	fin.open("SubwayInfoDatabase.txt", fstream::in);

	int totalLineNum;
	fin >> totalLineNum;
	cout << totalLineNum;

	fin.close();

	//vector<station> stationList(totalStationNum);

	return 0;
}