#include "DateTime.h"

/**
* Allows to set custom date from provided variables
*
*
* @Param - Enter Numeric values in format YYYY-MM-DD hh:mm:ss; Date is mandatory, Time is optional and defaults to 00:00:00
*/

void CustomDateTime::setDate(int Year, int Month, int Day, int Hours, int Minutes, int Seconds)
{
	//int tm_sec;   // seconds of minutes from 0 to 61
	//int tm_min;   // minutes of hour from 0 to 59
	//int tm_hour;  // hours of day from 0 to 24
	//int tm_mday;  // day of month from 1 to 31
	//int tm_mon;   // month of year from 0 to 11
	//int tm_year;  // year since 1900
	//int tm_wday;  // days since sunday
	//int tm_yday;  // days since January 1st
	//int tm_isdst; // hours of daylight savings time
	std::tm timeMaker;
	timeMaker.tm_sec = Seconds % 60;
	Minutes += Seconds / 60;
	timeMaker.tm_min = Minutes % 60;
	Hours += Minutes / 60;
	timeMaker.tm_hour = Hours % 24;
	Day += Hours / 24;
	timeMaker.tm_mday = Day;
	timeMaker.tm_mon = Month;
	timeMaker.tm_year = Year - 1900;
	timeMaker = this->RebuildDays(timeMaker);
	this->timeMark = mktime(&timeMaker);
}
/**
*Returns date in String Format
*
*
*/
string CustomDateTime::getDate() const
{
	return string(ctime(&this->timeMark));
}

//===============================

CustomDateTime::CustomDateTime()
{
	this->timeMark = time(0);
}
CustomDateTime::~CustomDateTime()
{

}


//===============================
	//===============================
	/**
	*Returns date in String Format
	*
	*
	*/
string CustomDateTime::toString()
{
	return this->getDate();
}

tm CustomDateTime::RebuildDays(tm time)
{
	int workSet = time.tm_mday;
	int longFeb = (time.tm_year % 4 == 0);
	while (time.tm_mday > 0)
	{
		if (time.tm_mon >= 12) {
			time.tm_year += time.tm_mon / 12;
			time.tm_mon = (time.tm_mon % 12);
			longFeb = (time.tm_year % 4 == 0);
		}
		switch (time.tm_mon + 1) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (time.tm_mday > 31) {
				time.tm_mday -= 31;
				time.tm_mon++;
			}
			else return time;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (time.tm_mday > 30) {
				time.tm_mday -= 30;
				time.tm_mon++;
			}
			else return time;
			break;
		case 2:
			if (time.tm_mday > 28 + longFeb) {
				time.tm_mday -= 28 + longFeb;
				time.tm_mon++;
			}
			else return time;
			break;
		default:
			return time;
			break;
		}
	}
	return time;
}