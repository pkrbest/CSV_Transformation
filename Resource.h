#ifndef _RESOURCE_CLASS
#define _RESOURCE_CLASS

#include <iostream>
#include <string>

class Resource{
public:
	std::string first;
	std::string second;
	bool Resource_Entered;
	Resource():Resource_Entered(false){}
	Resource(std::string f, std::string s) : first(f), second(s){ Resource_Entered = true; }
	Resource(std::string res){
		Insert(res);
	}

	void Insert(std::string res){
		std::size_t pos = res.find(",");
		second = res.substr(0, pos);
		if (second[0] == '\"') second.erase(0, 1);
		if (pos == std::string::npos){
			// "," not found
			// todo1: exception(?)
			first = "";
		}
		else {
			first = res.substr(pos + 1);
			while (first[0] == ' ') first.erase(0, 1);
			pos = first.find("\"");
			if (pos != std::string::npos) 
			  first.erase(pos, 1);
		}
		Resource_Entered = true;
	}

	friend std::istream& operator>>(std::istream& is, Resource& r){
		std::string str1, str2;
		
		is >> str1;
		std::cout << str1 << std::endl;
		if (str1 == "\""){
			is >> str1;
		}
		else if (str1[0] == '\"') str1.erase(0,1);
		std::size_t pos = str1.find(",");
		r.second = str1.substr(0, pos);
		if (pos == std::string::npos){
			// "," not found
			// todo1: exception(?)
			r.first = "";
		}
		else {
			str1 = str1.substr(pos + 1);
			if (str1 == "" || str1 == " "){
				is >> str1;
			}
			else if (str1 == "\n" || str1 == "\""){
				str1 = "";
			}
			std::cout << str1 << std::endl;
			pos = str1.find("\"");
			r.first = str1.substr(0, pos);
		}
		r.Resource_Entered = true;
		return is;
	}
};


#endif
