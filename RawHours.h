#ifndef _RAW_HOURS_CLASS
#define _RAW_HOURS_CLASS

template <class T>
struct RawHours{
public:
	T sat;
	T sun;
	T mon;
	T tues;
	T wed;
	T thurs;
	T fri;
	T junk;
	bool RawHours_Entered;
	RawHours(){ 
		sat = 0;
		sun = 0;
		mon = 0;
		tues = 0;
		wed = 0;
		thurs = 0;
		fri = 0;
		junk = 0;
		RawHours_Entered = false;
	}
	T& operator[](int j){
		if (j == 0) return sat;
		if (j == 1) return sun;
		if (j == 2) return mon;
		if (j == 3) return tues;
		if (j == 4) return wed;
		if (j == 5) return thurs;
		if (j == 6) return fri;
		else return junk = 0;
	}
};


#endif