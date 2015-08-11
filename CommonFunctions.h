#ifndef _COMMON_FUNCTIONS
#define _COMMON_FUNCTIONS

#include <string>
#include <fstream>
#include "Input.h"

// Contains all the common functions

// Finds the number of occurences of character c in 
// String str
int FindAll(const char& c, const std::string& str);

// returns true if a number is even
bool Even(const int& num);

//Gets a line in a csv file assuming that the word inside quotes (") 
// is a single word -- even if the strings are located in two lines
bool GetALine(std::ifstream& fs, std::string& s);


// Completely capitalizes a string (Used for comparisions)
void Capitalize(std::string& str);

// Finds the next item in the string
std::string FindNextItem(std::string& str);

// Convert String to Numbers
template <class T> 
T  ConvertStringToNumber(const std::string& str){
	std::string s = str;
	size_t pos = s.find(",");
	if (pos != -1) s.erase(pos, 1);
	T tmp;
	std::istringstream iss(s);
	return iss >> tmp ? tmp : 0;
}

// Output the first and the second half of the input
// The separater between the first and the second half is raw hours
void Output_FirstHalf(std::ofstream& output_file, SingleInput& inp);
void Output_SecondHalf(std::ofstream& output_file, SingleInput& inp);

// Output all the required fields
void Output_All(std::ofstream& output_file, SingleInput& inp);

#endif
