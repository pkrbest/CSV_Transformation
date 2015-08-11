#ifndef _COLUMN_NAMES
#define _COLUMN_NAMES

// This file defines the names of the columns
// In case the column name changes, you need
// to change this file only

#include <string>

typedef std::string String;

// Column names should be all in capital letters
// Only the content are compared
namespace ColumnNames{
	const String Resource = "RESOURCE";
	const String PostDate = "POST DATE";
	const String PeriodEnding = "PERIOD END";
	const String ProjectName = "PROJECT";
	const String RawHoursSat = "DAY 1 - SAT";
	const String RawHoursSun = "DAY 2 - SUN";
	const String RawHoursMon = "DAY 3 - MON";
	const String RawHoursTue = "DAY 4 - TUES";
	const String RawHoursWed = "DAY 5 - WED";
	const String RawHoursThu = "DAY 6 - THURS";
	const String RawHoursFri = "DAY 7 - FRI";
}

#endif