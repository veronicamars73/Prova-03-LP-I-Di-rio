#include "../include/Configuration.h"
#include <iostream> 
#include <unordered_map>
#include <fstream>
#include <string> 

std::unordered_map<std::string, std::string> read_configuration_file(){
    std::unordered_map<std::string, std::string> config;
    std::ifstream config_file("diary.config");
    if(config_file.fail()){
        config_file.close();
        std::ofstream write_config("diary.config");
        if (write_config.fail()) {
            std::cerr << "Something is wrong." << std::endl;
            return config;
        }else{
            write_config << "path=diary.md\n";
            write_config << "default_format=%d %t: %m";
            config["path"] = "diary.md";
            config["default_format"] = "%d %t: %m";
        }
        write_config.close();
    }else{
        while(!config_file.eof()){
            std::string lineofFile, key, value;
            std::getline(config_file, lineofFile);
            if(lineofFile.size()==0){
                continue;
            }
            key = lineofFile.substr(0, lineofFile.find("="));
            value = lineofFile.substr(lineofFile.find("=")+1, lineofFile.length());
            config[key] = value;
        }
    }
    return config;
}

std::string get_path(){
    std::unordered_map<std::string, std::string> config = read_configuration_file();
    return config["path"];
}

std::string get_print_format(){
    std::unordered_map<std::string, std::string> config = read_configuration_file();
    return config["default_format"];
}