#include "CommonFunctions.h"
#include "Date.h"

#include <cmath>
#include <sstream>

// Finds the number of occurences of character c in 
// String str
int FindAll(const char& c, const std::string& str){
	int a = 0;
	for (unsigned int i = 0; i < str.size(); ++i)
		if (str[i] == c) ++a;
	return a;
}

// returns true if a number is even
bool Even(const int& num){
	if (num % 2 == 0) return true;
	return false;
}

//Gets a line in a csv file assuming that the word inside quotes (") 
// is a single word -- even if the strings are located in two lines
bool GetALine(std::ifstream& fs, std::string& s){
	if (!getline(fs, s)) return false;
	while (!Even(FindAll('\"', s))){
		std::string str;
		if (!getline(fs, str)) return false;
		s = s + " " + str;
	}
	return true;
}

// Completely capitalizes a string (Used for comparisions)
void Capitalize(std::string& str){
	for (unsigned int i = 0; i < str.size(); ++i)
		str[i] = toupper(str[i]);
}

// Finds the next item in the string
std::string FindNextItem(std::string& str){
	bool res(false);
	std::string tmp;
	do{
		size_t pos = str.find(',');
		if (pos == std::string::npos) pos = str.size();
		tmp += str.substr(0, pos);
		if (pos != str.size()) str.erase(0, pos + 1);
		else str.erase(0, pos);
		res = Even(FindAll('\"', tmp));
		if (!res) tmp += ',';
	} while (!res && str.size() > 0);
	if (tmp[0] == '\"') tmp.erase(0, 1);
	int ii = tmp.size() - 1;
	if (tmp[ii] == '\"') tmp.erase(ii, 1);
	return tmp;
}

// Write the first half of the output stream (until the Raw Hours)
// "EmployeeID,PayCode,WorkDate,LastName,FirstName,RawHours,
// PeriodStartDate,PeriodEnding,TrackCode,ProjectUID,
// ProjectName,CostCenter,CostCenterName,VENDOR
void Output_FirstHalf(std::ofstream& output_file, SingleInput& inp){
	output_file << "\"" << inp.resource.second << ", " << inp.resource.first << "\","; // Employee ID
	output_file << "RT,"; //Pay Code
	output_file << inp.post_date << ","; // Work Date
	output_file << inp.resource.second << ","; // Last Name
	output_file << inp.resource.first << ","; // First Name
}

// Write the second half of the output stream (until the Raw Hours)
// "EmployeeID,PayCode,WorkDate,LastName,FirstName,RawHours,
// PeriodStartDate,PeriodEnding,TrackCode,ProjectUID,
// ProjectName,CostCenter,CostCenterName,VENDOR
void Output_SecondHalf(std::ofstream& output_file, SingleInput& inp){
	output_file << ","; // Period Start Date = empty
	output_file << inp.period_end << ","; // Period End Date
	output_file << ","; // Track Code = empty
	output_file << ","; // Project UID = empty
	output_file << "\"" << inp.project_name << "\","; // Project Name
	output_file << ","; // Cost Center = empty
	output_file << ","; //CostCenterName = empty
	output_file << " \n"; // Vendor Name = empty
}

// Write First Half + raw Hours + Second Half
// i.e. write all the fields
// "EmployeeID,PayCode,WorkDate,LastName,FirstName,RawHours,
// PeriodStartDate,PeriodEnding,TrackCode,ProjectUID,
// ProjectName,CostCenter,CostCenterName,VENDOR
void Output_All(std::ofstream& output_file, SingleInput& inp){
	
	for (int i = 0; i < 7; ++i){
		if (inp.raw_hours[i] > 0){
			Output_FirstHalf(output_file, inp);
			output_file << inp.raw_hours[i] << ",";
			Output_SecondHalf(output_file, inp);
		}
	}

	/*
	if (inp.raw_hours.sat > 0){
		Output_FirstHalf(output_file, inp);
		output_file << inp.raw_hours.sat << ",";
		Output_SecondHalf(output_file, inp);
	}
	
	if (inp.raw_hours.sun > 0){
		Output_FirstHalf(output_file, inp);
		output_file << inp.raw_hours.sun << ",";
		Output_SecondHalf(output_file, inp);
	}

	if (inp.raw_hours.mon > 0){
		Output_FirstHalf(output_file, inp);
		output_file << inp.raw_hours.mon << ",";
		Output_SecondHalf(output_file, inp);
	}

	if (inp.raw_hours.sat > 0){
		Output_FirstHalf(output_file, inp);
		output_file << inp.raw_hours.sat << ",";
		Output_SecondHalf(output_file, inp);
	}

	if (inp.raw_hours.sat > 0){
		Output_FirstHalf(output_file, inp);
		output_file << inp.raw_hours.sat << ",";
		Output_SecondHalf(output_file, inp);
	}

	if (inp.raw_hours.sat > 0){
		Output_FirstHalf(output_file, inp);
		output_file << inp.raw_hours.sat << ",";
		Output_SecondHalf(output_file, inp);
	}

	if (inp.raw_hours.sat > 0){
		Output_FirstHalf(output_file, inp);
		output_file << inp.raw_hours.sat << ",";
		Output_SecondHalf(output_file, inp);
	}
	*/
}
