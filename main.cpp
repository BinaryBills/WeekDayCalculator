/* Author: Binary Bills
* Creation Date : August 19, 2021
* Modification Date : August 21, 2021
* Purpose : This program calculates the weekday of any date that occurred after 1699 and before 2099.
*/

#include <iostream>
#include "wkDayCal.h"
#include <cstdlib>
using namespace std;

void menu();
void menuOverlay();
void calWeekDay();
void displayErrors(bool[]);

int main()
{
 /*******************************************************************
    Changes the Terminals's Text to Green and Calls the Menu Function
 *******************************************************************/
    system("Color 0A");
    menu();
}

void menu()
{
 /*******************************************************************
    Displays the Menu Options and allow the user to choose
 *******************************************************************/
    int userChoice;
    menuOverlay();
    cout << "Select one of the following options: ";
    cin >> userChoice;

    switch (userChoice)
    {
    case 1:
        cout << endl;
        calWeekDay();
        break;

    case 2:
        cout << "Thank you for using the program! Exiting the program...\n";
        system("pause");
        exit(EXIT_SUCCESS);
        break;

    default:
        cin.clear();
        cin.ignore(2576, '\n');
        system("cls"); 
        cerr << "----> ERROR: YOU ENTERED AN INVALID CHOICE. PLEASE TRY AGAIN. <----\n";
        menu();
        break;
    }
}

void calWeekDay()
{
  /*******************************************************************
        Initializing variables used throughout the function
  *******************************************************************/

    wkDayCal date;
    bool resumeLoop = true;
    char choice;
    bool errors[5] = { false,false,false,false,false };

/*******************************************************************
   Allowing the User to Input Their Date and Validating their input
 *******************************************************************/

    while (resumeLoop == true)
    {
        cout << "Enter a date that occurs after 1699 and before 2099 in the following format MM/DD/YYYY: ";
        cin >> date.month;

        //ERROR CHECK #1: Verifies that the user included a '/' in their input after writing the month.
        if (cin.get() != '/')
            errors[0] = true;

        //ERROR CHECK #2: Verifies that the user inputted a real month.
        if (date.verifyMonth() == false)
            errors[1] = true;

        cin >> date.day;

        //ERROR CHECK #3: Verifies that the user inputted a '/' in their input after writing the day of the month.
        if (cin.get() != '/')
            errors[2] = true;

        cin >> date.year;

        //ERROR CHECK #4: Verifies that the user entered a year that occurred after the 1699 and before 2099.

        if (date.verifyCentury() == false)
            errors[3] = true;

        //ERROR CHECK #5: Verifies that the day of the month chosen by the user exists.
        if (date.verifyDay() == false)
            errors[4] = true;

        //If there are no errors with the user's input, then the program will calculate the week-day of the given date.
        if (errors[0] == false && errors[1] == false && errors[2] == false && errors[3] == false && errors[4] == false)
        {
            date.setCenturyCode();
            date.setYearCode();
            date.setMonthCode();
            date.displayResult();

            while (resumeLoop == true)
            {
                cout << endl;
                cout << "Do you want to enter another date?(y for yes and n for no): ";
                cin >> choice;

                switch (choice)
                {
                case 'y':
                    calWeekDay();
                    break;
                case 'n':
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
         displayErrors(errors);
        return;
    }

}


    void displayErrors(bool err[])
    {
       
    /*******************************************************************
      Verifying how many errors occurred
    *******************************************************************/
        
        int count = 0;

        for (int i = 0; i < 5; i++)
        {
            if (err[i] == true)
                count++;
        }

        cout << endl;
        cerr << "--------------------------------------------------------------------------------------------------------\n";
        cerr << "There was a total of " << count << " error(s) your input:\n\n";


   /*******************************************************************
          Informing the user why the error happened
    *******************************************************************/

        if (err[0] == true)
            cerr << "- ERROR: YOU NEED TO TYPE A / AFTER YOU TYPE THE MONTH\n";


        if (err[1] == true)
            cerr << "- ERROR: THE NUMBER THAT YOU CHOSE FOR YOUR MONTH IS INVALID. THERE ARE ONLY 12 MONTHS IN A YEAR.\n";

        if (err[2] == true)
            cerr << "- ERROR: YOU NEED TO TYPE A / AFTER YOU TYPE THE DAY OF THE MONTH\n";

        if (err[3] == true)
            cerr << "- ERROR: THE YEAR THAT YOU CHOOSE MUST BE AFTER 1699 AND BEFORE 2099\n";

        if (err[4] == true)
            cerr << "- ERROR: THE DAYS THAT YOU CHOSE IS IMPOSSIBLE FOR THAT MONTH BASED ON THE YEAR YOU CHOSE \n";


        cerr << "--------------------------------------------------------------------------------------------------------\n";
        system("pause");
        system("CLS");
        cerr << "----> ERROR: YOU ENTERED A DATE THAT DOES NOT EXIST. PLEASE TRY AGAIN. <----\n";
        cin.clear();
        cin.ignore(2576, '\n');
        menu();
    }






    void menuOverlay()
    {
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
    }