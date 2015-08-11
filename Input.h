#ifndef _INPUT_CLASS
#define _INPUT_CLASS

#include <string>
#include <vector>
#include <fstream>
#include "Resource.h"
#include "Date.h"
#include "RawHours.h"

class SingleInput{
public:
	long comparekey; // FirstName+LastName+ProjectName
	Resource resource;
	Date post_date;
	Date period_end;
	std::string project_name;
	RawHours<float> raw_hours;
	bool ALL_FILLED;
	SingleInput(){
		ALL_FILLED = false;
	}
};


// defines the column number where each of these items
// are present
struct Position{
	int resource;
	int post_date;
	int period_end;
	int project_name;
	RawHours<int> raw_hours;
	Position(){
		resource = 0;
		post_date = 0;
		period_end = 0;
		project_name = 0;
	}
};

class Input{
public:
	std::vector<SingleInput> l;
	Position pos;
	bool POSITION_FILLED;
	std::ifstream input_file;
	std::ofstream output_file;
public:
	Input(){
		POSITION_FILLED = false;
	}

	// Constructor to take in and save the input and output file path
	Input(const std::string& input_file_name, const std::string& output_file_name){
	  if (input_file.is_open()) input_file.close();
	  input_file.open(input_file_name.c_str());
	  if (output_file.is_open()) output_file.close();
	  output_file.open(output_file_name.c_str());
	  POSITION_FILLED = false;
	}

	// Destructor (closes all the files that are open)
	~Input(){
		if (input_file.is_open()) input_file.close();
		if (output_file.is_open()) output_file.close();
	}

	typedef std::vector<SingleInput>::iterator Iterator;

	// Function to input the position of the columns for each required fields
	int InputPositions(std::string& str); 
	// Display the positions of each required field
	void DisplayPositions();
	// Function to input the data in the structure
	int PushData(std::string& str);
	// Insert the data at the correct position in the vector
	Iterator InsertData(const SingleInput& inp, Iterator first, Iterator last);

	// Function to conduct the whole operation
	// i.e. save the required fields from an input file as the data and 
	// save the output file
	//TODO: Add functionality to change the folder name
	// return of 0 = operation successful
	// 
	int Operate();

};

#endif
