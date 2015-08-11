#ifndef _DATE_CLASS
#define _DATE_CLASS

#include <iostream>
#include <string>
#include <fstream>

// This is a storage class for the dates
// It is used to input the date and check if the 
// date is inputted correctly

class Date{
private:
	int _m;  // month  
	int _d;  // date
	int _y;  // year
public:
	bool Date_Entered;
	// Constructor to set the date with the given fields
	Date(int mm, int dd, int yy) : _m(mm), _d(dd), _y(yy){ Date_Entered = true; }
	// Constructor to set the date to beginning of time
	Date() : _m(1), _d(1), _y(1000){ Date_Entered = false; }
	
	// Function to check the inputted date
	// returns
	// 0 = the date is fine
	// 2 = The month (1 - 12) is not correct
	// 3 = The date (1-31) is not correct
	// 4 = The year (2000 - today's year) is not correct
	// 5 = The date is not entered yet
	int Check();

	// insert the Date
	void Insert(std::string& date);

	// Function to input the date
	template <class T>
	friend std::istream& operator>>(std::istream& is, Date& d);
	friend std::ostream& operator<<(std::ostream& os, Date& d);
	//friend std::ofstream& operator<<(std::ofstream& os, Date& d);
};
#endif