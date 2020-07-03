#include "../include/Time.h"
#include <sstream>
#include <ctime>
#include <iomanip>

Time::Time(unsigned hour, unsigned minute, unsigned second): hour(hour), minute(minute), second(second){

}

Time::Time(): hour(0), minute(0), second(0) {

}

void Time::set_from_string_time(const std::string& time){
	std::stringstream string_to_convert(time);
	char delimiter;
	string_to_convert >> hour;
	string_to_convert >> delimiter;
	string_to_convert >> minute;
	string_to_convert >> delimiter;
	string_to_convert >> second;
}

std::string Time::get_time_string() {
	std::stringstream str;
	str << std::setfill('0') << std::setw(2) << hour;
	str << ':';
	str << std::setfill('0') << std::setw(2) << minute;
	str << ':';
	str << std::setfill('0') << std::setw(2) << second;
	return str.str();
}