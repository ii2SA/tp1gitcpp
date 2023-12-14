/** 
  * File:     date.h 
  * Author:   D. Ginhac (dginhac@u-bourgogne.fr)
  * Date:     Fall 2019 
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique 
  * Summary:  Declaration of the Date class
  */

#ifndef _date_h
#define _date_h

#include <string>             // required for using string

class Date {                  
public:                       // Always start with public section
	Date(int day, int month, int year); // Constructor and
	~Date();				  // Destructor
	int getMonth();           // Member functions are public
	int getDay();
	int getYear();              // Getters must be defined to access variables                  
	std::string toString();
protected:                      // then private section
	int _month;              // Always define private variables 
	int _day;
	int _year;				  
};
#endif