#include <iostream>
#include "wkDayAlgorithm.h"
using namespace std;


/******************************************************
 Setter methods for the special variables
******************************************************/
void wkDayAlgorithm::setCenturyCode() 
{
	if (year >= 1700 && year <= 1799)
	   centuryCode = 5;
	else if (year >= 1800 && year <= 1899)
		centuryCode = 3;
	else if (year >= 1900 && year <= 1999)
		centuryCode = 1;
	else if (year >= 2000 && year <= 2099)
		centuryCode = 0;
}

void wkDayAlgorithm::setMonthCode() 
{
	if (month == 1)
		monthCode = 5;
	else if (month == 2)
		monthCode = 1;
	else if (month == 3)
		monthCode = 1;
	else if (month == 4)
		monthCode = 4;
	else if (month == 5)
		monthCode = 6;
	else if (month == 6)
		monthCode = 2;
	else if (month == 7)
		monthCode = 4;
	else if (month == 8)
		monthCode = 0;
	else if (month == 9)
		monthCode = 3;
	else if (month == 10)
		monthCode = 5;
	else if (month == 11)
		monthCode = 1;
	else if (month == 12)
		monthCode = 3;
}

/******************************************************
 Getter Methods
******************************************************/

int wkDayAlgorithm::getResult() const
{
	int result = (yearCode + (yearCode / 4) + 1 + centuryCode + monthCode + day);
	result = result % 7;
	return result;
}
/******************************************************
 Helper Function
******************************************************/

void wkDayAlgorithm::displayResult()
{
	int result = getResult();

	if (result == 0)
		cout << "The date " << month << "/" << day << "/" << year << " was on a Sunday.\n";
	else if (result == 1)
		cout << "The date " << month << "/" << day << "/" << year << " was on a Monday.\n";
	else if (result == 2)
		cout << "The date " << month << "/" << day << "/" << year << " was on a Tuesday.\n";
	else if (result == 3)
		cout << "The date " << month << "/" << day << "/" << year << " was on a Wednesday.\n";
	else if (result == 4)
		cout << "The date " << month << "/" << day << "/" << year << " was on a Thursday.\n";
	else if (result == 5)
		cout << "The date " << month << "/" << day << "/" << year << " was on a Friday.\n";
	else if (result == 6)
		cout << "The date " << month << "/" << day << "/" << year << " was on a Saturday.\n";
}


/*Source: includehelp.com
* Link: https://www.includehelp.com/cpp-programs/find-total-number-of-days-in-given-month-of-year.aspx
*Purpose: Returns the total number of days in a given month
*/
int wkDayAlgorithm::getNumOfMaxDaysForAMonth() const
{
	//leap year condition, if month is 2
	if (month == 2)
	{
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
			return 29;
		else
			return 28;
	}
	//months which has 31 days
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
		|| month == 10 || month == 12)
		return 31;
	else
		return 30;
}