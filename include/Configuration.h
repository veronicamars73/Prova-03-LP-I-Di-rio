#ifndef W5N_CONFIGURATION_H
#define W5N_CONFIGURATION_H
 
#include <unordered_map> 
#include <string>

std::unordered_map<std::string, std::string> read_configuration_file();
std::string get_path();
std::string get_print_format();

#endif