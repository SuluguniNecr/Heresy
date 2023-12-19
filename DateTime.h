#pragma once
#include <string>       // std::string
#include <iostream>
#include <ctime>

using namespace std;

class CustomDateTime {
private:
	std::time_t timeMark;

	tm RebuildDays(tm Time);

public:
	void setDate(int Year, int Month, int Day, int Hour = 0, int Minutes = 0, int Seconds = 0);


	string getDate() const;

	//===============================

	CustomDateTime();
	~CustomDateTime();


	string toString();
};