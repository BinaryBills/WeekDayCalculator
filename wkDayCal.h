/*Author: BinaryBills
Creation Date: August 19, 2021
Modifcation Date: August 20, 2021
Purpose: This header file contains all of the variables and methods needed for the week-day algorithm to work properly.
*/

#pragma once

struct wkDayCal
{
/******************************************************
  1) User Input Variables
******************************************************/
  // These variables capture the user input.
	int day;
	int month;
	int year;

/******************************************************
 2) Special Variables Required for the Formula
******************************************************/
  // After the User Input Variables are validated, they are converted into a form that is understood by the algorithm.
	int monthCode;
	int yearCode;
	int centuryCode;
	bool leapYear;

/******************************************************
  3) User Input Validation Methods
******************************************************/
  // These methods validates the User Input Variables. 
	bool verifyMonth() { if (month < 1 || month > 12) return false; else return true; }
	bool verifyCentury() { if (year < 1700 || year > 2098) { return false; } else return true; }
	bool verifyDay() { if (day < 0 || day > getNumOfMaxDaysForAMonth())return false; else return true; }

/******************************************************
 4) Setter methods for the special variables
******************************************************/
  // These methods sets a value to the special variables required for the formula.
	void setMonthCode();
	void setCenturyCode();
	void setYearCode() { yearCode = year % 100; }
	
/******************************************************
	5) Getter Methods
******************************************************/
  // These methods grab the result of a calculation. 
	int getNumOfMaxDaysForAMonth();
	int getResult() const;

/******************************************************
   6) Helper Function
******************************************************/
	void displayResult();
};

