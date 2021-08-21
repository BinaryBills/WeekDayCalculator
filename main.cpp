/* Author: Binary Bills
* Creation Date : August 19, 2021
* Modification Date : August 20, 2021
* Purpose : This program calculates the weekday of any date that occurred after the 1600s and before 2099.
*/

#include <iostream>
#include "wkDayAlgorithm.h"
#include "windows.h"
#include "stdlib.h"
using namespace std;

void menu(); 
void calWeekDay();
void displayErrors(bool []);


int main()
{
	
	system("Color 0A");
	menu();
	system("pause");
	return 0;

}




void menu()
{
	int choice;
	cout << R"(
8============================================================================================================================================================================================================8
                              .______    __  .__   __.      ___      .______     ____    ____    .______    __   __       __          _______.__     _______.                                            
                              |   _  \  |  | |  \ |  |     /   \     |   _  \    \   \  /   /    |   _  \  |  | |  |     |  |        /       (_ )   /       |                                            
                              |  |_)  | |  | |   \|  |    /  ^  \    |  |_)  |    \   \/   /     |  |_)  | |  | |  |     |  |       |   (----`|/   |   (----`                                            
                              |   _  <  |  | |  . `  |   /  /_\  \   |      /      \_    _/      |   _  <  |  | |  |     |  |        \   \          \   \                                                
                              |  |_)  | |  | |  |\   |  /  _____  \  |  |\  \----.   |  |        |  |_)  | |  | |  `----.|  `----.----)   |     .----)   |                                               
                              |______/  |__| |__| \__| /__/     \__\ | _| `._____|   |__|        |______/  |__| |_______||_______|_______/      |_______/                                                
                                                                                                                                                                                                         
____    __    ____  _______  _______  __  ___             _______       ___   ____    ____      ______     ___       __        ______  __    __   __          ___   .___________.  ______   .______      
\   \  /  \  /   / |   ____||   ____||  |/  /            |       \     /   \  \   \  /   /     /      |   /   \     |  |      /      ||  |  |  | |  |        /   \  |           | /  __  \  |   _  \     
 \   \/    \/   /  |  |__   |  |__   |  '  /   ______    |  .--.  |   /  ^  \  \   \/   /     |  ,----'  /  ^  \    |  |     |  ,----'|  |  |  | |  |       /  ^  \ `---|  |----`|  |  |  | |  |_)  |    
  \            /   |   __|  |   __|  |    <   |______|   |  |  |  |  /  /_\  \  \_    _/      |  |      /  /_\  \   |  |     |  |     |  |  |  | |  |      /  /_\  \    |  |     |  |  |  | |      /     
   \    /\    /    |  |____ |  |____ |  .  \             |  '--'  | /  _____  \   |  |        |  `----./  _____  \  |  `----.|  `----.|  `--'  | |  `----./  _____  \   |  |     |  `--'  | |  |\  \----.
    \__/  \__/     |_______||_______||__|\__\            |_______/ /__/     \__\  |__|         \______/__/     \__\ |_______| \______| \______/  |_______/__/     \__\  |__|      \______/  | _| `._____|                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
By: https://github.com/BinaryBills
8============================================================================================================================================================================================================8    

                                              o8==========8o                                                   o8==========8o                                                                
                                               |    (1)   |                                                     |   (2)    |
                                               |   BEGIN  |                                                     |   EXIT   |
                                              o8==========8o                                                   O8==========8O                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
)";

	cout << endl;
	cout << "Select one of the following options: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << endl;
		calWeekDay();
		break;

	case 2:
	cout << "Thank you for using the program! Exiting the program...\n";
	return;
	 break;

	default:


		cin.clear();
		cin.ignore(2576, '\n');
		system("cls"); //NOTE: This line of code makes a call to the operating system to clear the screen. Some operating systems do not support this, but Windows 10 does. 
		cerr << "----> ERROR: YOU ENTERED AN INVALID CHOICE. PLEASE TRY AGAIN. <----\n";
		menu();
	}
}

void calWeekDay()
{
	
	wkDayAlgorithm date;
	bool resumeLoop = true;
	bool choiceLoop;
	bool error[5] = { false,false,false,false,false};
	char choice;

	while (resumeLoop == true)
	{
		cout << "Enter a date that occurs after the 1600s and before 2099 in the following format MM/DD/YYYY: ";
		cin >> date.month;
		
	//CHECK ONE: Verifies that the user included a '/' in their input after writing the month
		if (cin.get() != '/')
			error[0] = true;

	//CHECK TWO: Verifies that user inputted a real month [1-12]
		if (date.verifyMonth() == false)
			error[1] = true;

		cin >> date.day;

	//CHECK THREE: Verifies that the user included a '/' in their input after writing the day of the month
		if (cin.get() != '/')
			error[2] = true;

		cin >> date.year;

	//CHECK FOUR: Verifies that the year chosen by the user is after the 1600s and before 2099
		
		if (date.verifyCentury() == false)
			error[3] = true;

	//CHECK FIVE: Given the year, we will figure out if the day of the month chosen by the user makes sense for the year they chose.
		if (date.verifyDay() == false)
			error[4] = true;

		if (error[0] == false && error[1] == false && error[2] == false && error[3] == false && error[4] == false)
		{
			date.setCenturyCode();
			date.setYearCode();
			date.setMonthCode();
			date.displayResult();
			choiceLoop = true;

			while (choiceLoop == true)
			{
				cout << endl;
				cout << "Do you want to enter another date?(y for yes and n for no): ";
				cin >> choice;

				switch (choice)
				{
				case 'y':
					resumeLoop = true;
					choiceLoop = false;
					break;
				case 'n':
					resumeLoop = false;
					choiceLoop = false;
					system("CLS");
					menu();
					break;
				default:
					cin.clear();
					cin.ignore(2576, '\n');
					cerr << "Invalid option" << endl;
					break;
				}

				cout << endl;

			}

		}
		else
			displayErrors(error);

	}


}

void displayErrors(bool err[])
{
	int count = 0;

	for (int i = 0; i < 5; i++)
	{
		if (err[i] == true)
			count++;
	}

	cout << endl;
	cerr << "--------------------------------------------------------------------------------------------------------\n";
	cerr << "There was a total of " << count << " error/s your input:\n\n";


		if (err[0] == true)
			cerr << "- ERROR: YOU NEED TO TYPE A / AFTER YOU TYPE THE MONTH\n";


		if (err[1] == true)
			cerr << "- ERROR: THE NUMBER THAT YOU CHOSE FOR YOUR MONTH IS INVALID. THERE ARE ONLY 12 MONTHS IN A YEAR.\n";

		if (err[2] == true)
			cerr << "- ERROR: YOU NEED TO TYPE A / AFTER YOU TYPE THE DAY OF THE MONTH\n";

		if (err[3] == true)
			cerr << "- ERROR: THE YEAR THAT YOU CHOOSE MUST BE AFTER THE 1600S AND BEFORE 2099\n";

		if (err[4] == true)
			cerr << "- ERROR: THE DAYS THAT YOU CHOSE IS IMPOSSIBLE FOR THAT MONTH BASED ON THE YEAR YOU CHOSE \n";
	
	
		cerr << "--------------------------------------------------------------------------------------------------------\n";
		system("pause");
		system("CLS");
		cerr << "----> ERROR: YOU ENTERED A DATE THAT DOES NOT EXIST. PLEASE TRY AGAIN. <----\n";
		menu();


}