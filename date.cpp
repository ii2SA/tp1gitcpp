/** 
  * File:     date.cpp 
  * Author:   D. Ginhac (dginhac@u-bourgogne.fr)
  * Date:     Fall 2019 
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique 
  * Summary:  Implementation of the Date class
  */

#include <iostream>
#include "date.hpp"

Date::Date(int month, int day, int year) {
	_month = month;
	_day = day;
	_year = year;
}

Date::~Date() {
	// std::cout << "Destructor" << std::endl;
}

int Date::getMonth() {
	return _month;
}   

int Date::getDay() {
	return _day;
}

int Date::getYear() {
	int year;
	while(_year <= 0 || _year > 12){
		std::cout << "entrer une date valide";
		std::cin>>year;
	}
	_year = year;
	return _year;
}

std::string Date::toString() {
	std::string month[12] = {"Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec"};
	std::string to_display = std::to_string(_day) + "/ " + month[_month-1] + "/ " + std::to_string(_year) ;
	return to_display;
}


