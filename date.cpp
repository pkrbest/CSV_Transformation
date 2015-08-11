#include "date.h"
#include "CommonFunctions.h"
#include <string>
#include <sstream>
#include <time.h>
#include <sstream>
using namespace std;

// Function to check if the date is correct
int Date::Check(){
	
	if (!Date_Entered) return 5; // 5 = date is not entered yet
	if (_m < 1 || _m > 12) return 2; // 2 = The month (1 - 12) is not correct
	if (_d < 1 || _d > 31) return 3; // 3 = The date (1-31) is not correct
	
	time_t theTime = time(NULL);
	struct tm *aTime;
	aTime = localtime(&theTime);

	int day = (aTime)->tm_mday;
	int month = (aTime)->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
	int year = (aTime)->tm_year + 1900; // Year is # years since 1900
	
	if (_y < 2000 || _y > year) return 4; // 4 = The year (2000 - today's year) is not correct

	// check if the date entered is not later than the current date 
	// 6 = The date is past the current date
	if (_y == year){
		if (_m > month) return 6;
		if (_m == month && _d > day) return 6;
	}
	
	return 0;

}

// Overloading the input operator
istream& operator>>(istream& is, Date& dd){
	int d, m, y;
	char c;
	// Date should be expressed as:
	// "mm / dd / yyyy"
	is >> m;
	is >> c;
	if (c != '/'){
		cout << "ERROR: The date is not expressed with a slash \'/\' \n";
		throw 1; // Exception = 1 if the date is not expressed correctly (with a '/')
	}

	is >> d;
	is >> c;
	if (c != '/'){
		cout << "ERROR: The date is not expressed with a slash \'/\' \n";
		throw 1; // Exception = 1 if the date is not expressed correctly (with a '/')
	}

	is >> y;

	dd = Date(m, d, y);
	dd.Date_Entered = true;

	int ret = dd.Check();
	if (ret != 0){
		cout << "ERROR: ";
		if (ret == 2) cout << "The month (1 - 12) is not correct\n";
		if (ret == 3) cout << "The date (1-31) is not correct\n";
		if (ret == 4) cout << "The year (2000 - today's year) is not correct\n";
		if (ret == 5) cout << "The date is not entered yet\n";
		if (ret == 6) cout << "The inputted date is past the current date\n";
		throw ret;
	}

	return is;
}

//Overloading the output operator
ostream& operator<<(ostream& os, Date& dd){
	os << dd._m << "/" << dd._d << "/" << dd._y;
	return os;
}

//Overloading the output file stream operator
/*
ofstream& operator<<(ofstream& os, Date& dd){
	os << dd._m << "/" << dd._d << "/" << dd._y;
	return os;
}
*/

// Function to insert the date using the date string
void Date::Insert(string& str){
	size_t p1;
	// The date should be expressed as mm/dd/yyyy
	p1 = str.find('/');
	string s("");
	if ((int)(p1) - 1 >= 0)
		if (str[p1 - 1] >= '0' && str[p1 - 1] <= '9') s = str[p1 - 1] + s;
    if ((int)(p1) - 2 >= 0)
		if (str[p1 - 2] >= '0' && str[p1 - 2] <= '9') s = str[p1 - 2] + s;

	_m = ConvertStringToNumber<int>(s); // mm
	str.erase(0, p1+1);
	
	p1 = str.find('/');
	s = str.substr(0,p1);
	_d = ConvertStringToNumber<int>(s); // dd

	s = str.substr(p1 + 1, 4);
	_y = ConvertStringToNumber<int>(s); // yyyy
	Date_Entered = true;

	//TODO: Handle the case where the date string is not in the proper format

	int ret = Check();
	if (ret != 0){
		cout << "ERROR: ";
		if (ret == 2) cout << "The month (1 - 12) is not correct\n";
		if (ret == 3) cout << "The date (1-31) is not correct\n";
		if (ret == 4) cout << "The year (2000 - today's year) is not correct\n";
		if (ret == 5) cout << "The date is not entered yet\n";
		if (ret == 6) cout << "The inputted date is past the current date\n";
		throw ret;
	}
}
