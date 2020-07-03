#include "../include/Helpers.h"
#include "../include/Date.h"
#include <ctime>
#include <iostream>
#include <fstream>


std::string format_current_date(const std::string& format) {
	std::time_t time = std::time(nullptr);
	char result[1024];
	std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));
	return std::string(result);
}
std::string get_current_date() {
	return format_current_date("%d/%m/%Y");
}
std::string get_current_time(){
	return format_current_date("%H:%M:%S");
}

int show_usage(std::string program) {
    std::cerr << "Uso: " << program << " add <mensagem> or " << program << " list or " << program << " interactive or " << program<< "search <term>" << std::endl;
    return 1;
}

int file_error() {
    std::cerr << "Erro ao abrir o arquivo" << std::endl;
    return -1;
}

int dateExists(std::ifstream &infile, Date date_to_test){
    std::string lineofFile;
    while(!infile.eof()){
        std::getline(infile, lineofFile);
        if (lineofFile=="# "+date_to_test.get_date_string()){
            return 1;
        }
    }
    return -1;
}
