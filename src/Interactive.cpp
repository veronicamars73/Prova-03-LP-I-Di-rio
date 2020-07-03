#include "../include/Interactive.h"

#include <iostream>
#include <string> 

void print_menu(){
    std::cout << "-----------------------------" << std::endl;
    std::cout << "            MENU             " << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Type the number of desired option:" << std::endl;
    std::cout << "1- List Messages" << std::endl;
    // std::cout << "2- Search term" << std::endl;
    std::cout << "2- Add Message" << std::endl;
    std::cout << "0- Quit" << std::endl;
}

int get_option(){
    int op;
    std::cin >> op;
    return op;
}
