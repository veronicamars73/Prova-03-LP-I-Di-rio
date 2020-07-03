#include "../include/App.h"
#include "../include/Date.h"
#include "../include/Time.h"
#include "../include/Helpers.h"
#include "../include/Message.h"
#include "../include/Configuration.h"
#include "../include/Interactive.h"

#include <iostream>
#include <string>
#include <vector>

App::App(std::string filename) : diary(filename) {
}

int App::run(int argc, char* argv[])
{
    if (argc == 1) {
        return show_usage(argv[0]);
    }

    std::string action = argv[1];

    if (action == "add") {
        if (argc == 2) {
            add();
        } else {
            add(argv[2]);
        }
    } else if (action == "list") {
        if (argc == 2)
        {
            list_messages();
        }else{
            show_usage(argv[0]);
        }
        
    } else if (action == "search") {
        std::vector<Message*> pointer;
        if (argc == 2) {
            pointer = search();
        } else {
            pointer = search(argv[2]);
        }
        result_search(pointer);
    } else {
        if (action == "interactive") {
            int op;
            do{
                print_menu();
                op = call_option();
            }while(op!=0);
        }else{
            return show_usage(argv[0]);
        }
    }

    return 0;
}

void App::add()
{
    std::string message;
    std::cout << "Enter your message:" << std::endl;
    std::getline(std::cin, message);

    add(message);
}


void App::add(const std::string message)
{
    diary.add(message);
    
}

int App::call_option(){
    int op;
    // std::vector<Message*> pointer;
    std::cin >> op;
    switch(op){
        case 0:
            std::cout << "Bye!" << std::endl;
            break;
        case 1:
            list_messages();
            break;
        // case 2:
        //     std::cin.ignore();
            
        //     pointer = search();
        //     result_search(pointer);
        //     break;
        case 2:
            std::cin.ignore();
            add();
            break;
        default:
            std::cout << "Invalid option." << std::endl;
    }
    return op;
}

std::vector<Message*> App::search()
{
    std::string looked;
    std::cout << "Enter the text to be searched: " << std::endl;
    std::getline(std::cin, looked);

    return search(looked);
}

std::vector<Message*> App::search(const std::string looked)
{
    return diary.search(looked);
    
}

void App::list_messages()
{
    for (size_t i = 0; i < diary.message_size; ++i) {
        Message message = diary.messages[i];
        print_message(message);
    }
}

std::string App::get_print_string(std::string format, Message message){
    int indexdate, indextime, indexcontent;
    std::string formated = "";
    for(std::string::size_type i = 0; i < format.size(); ++i) {
        if(format[i]=='%' && i<format.size()-1){
            if (format[i+1]=='d'){
                formated = formated + message.date.get_date_string();
                i = i+1;
                continue;
            }else{
                if(format[i+1]=='t'){
                    formated = formated + message.time.get_time_string();
                    i = i+1;
                    continue;
                }else{
                    if(format[i+1]=='m'){
                        formated = formated + message.content;
                        i = i+1;
                        continue;
                    }
                }
            }
        }
        formated = formated + format[i];
    }

    return formated;
}

void App::print_message(Message message) {
    std::string format = get_print_format();
    std::string formated = get_print_string(format, message);

    std::cout << formated << std::endl;
}

void App::result_search(std::vector<Message*> pointer){
    if (!pointer.empty()){
        for(auto msg : pointer){
            std::cout << "Term found at the " << msg - (&diary.messages[0]) + 1 << "th message of the diary.\n";
            std::cout << "The message content is:" << std::endl;
            print_message(*msg);
        }
        return;
    }
    std::cout << "Term not found" << std::endl;
}