#ifndef W5N_HELPERS_H
#define W5N_HELPERS_H

#include <string>
#include "Date.h"

std::string format_current_date(const std::string& format);
std::string get_current_date();
std::string get_current_time();
int show_usage(std::string program);
int file_error();
int dateExists(std::ifstream &infile, Date date_to_test);

#endif