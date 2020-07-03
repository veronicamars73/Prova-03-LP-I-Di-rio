#ifndef W5N_APP_H
#define W5N_APP_H

#include "Diary.h"
#include "Message.h"


#include <string>
#include <vector>

struct App
{
    Diary diary;

    App(std::string filename);
    int run(int argc, char* argv[]);
    
    void add();
    void add(const std::string message);
    std::vector<Message*> search();
    std::vector<Message*> search(const std::string looked);
    void list_messages();
    void print_message(Message message);
    void result_search(std::vector<Message*> pointer);
    std::string get_print_string(std::string format, Message message);
    int call_option();
}; 
#endif
