#ifndef W5N_DIARY_H
#define W5N_DIARY_H

#include "Message.h"
#include <vector>
#include <string>

struct Diary
{
    Diary(const std::string& filename);
    std::string filename;
    std::vector<Message> messages;
    size_t message_size;
    size_t message_max;

    void add(const std::string& message);
    void write();
    std::vector<Message*> search(const std::string& message);
}; 
#endif
