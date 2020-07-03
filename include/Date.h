#ifndef W5N_DATE_H
#define W5N_DATE_H

#include <string>

struct Date
{
    unsigned year;
    unsigned month;
    unsigned day;
    Date();
    Date(unsigned year, unsigned month, unsigned day);
    void set_from_string_date(const std::string& date);
	std::string get_date_string();
}; 
#endif
