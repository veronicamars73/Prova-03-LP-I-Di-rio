#include "../include/Date.h"
#include <sstream>
#include <ctime>
#include <iomanip>


Date::Date(unsigned day, unsigned month, unsigned year): day(day), month(month), year(year) {
}

Date::Date(): day(0), month(0), year(0) {
	
}

void Date::set_from_string_date(const std::string& date){
	std::stringstream string_to_convert(date);
	char delimiter;
	string_to_convert >> day;
	string_to_convert >> delimiter;
	string_to_convert >> month;
	string_to_convert >> delimiter;
	string_to_convert >> year;
}


std::string Date::get_date_string() {
	std::stringstream str;
	str << std::setfill('0') << std::setw(2) << day;
	str << '/';
	str << std::setfill('0') << std::setw(2) << month;
	str << '/';
	str << year;
	return str.str();
}