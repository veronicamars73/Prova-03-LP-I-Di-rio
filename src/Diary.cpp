#include "../include/Diary.h"
#include "../include/Message.h"
#include "../include/Date.h"
#include "../include/Time.h"
#include "../include/Helpers.h"
#include <fstream>
#include <string>
#include <vector>


Diary::Diary(const std::string& filename) : filename(filename), message_size(0) {

    std::ifstream archive(filename);
    if(archive.fail()){
        //file_error();
    }else{
        std::string lineofFile;
        Date date_read(0,0,0);
        Time time_read(0,0,0);

        while(!archive.eof()){
            std::getline(archive, lineofFile);
            if(lineofFile.size()==0){
                continue;
            }
            if(lineofFile[0]=='#'){
                char delimiter;
                std::string date;
                date = lineofFile.substr(2);
                date_read.set_from_string_date(date);
                continue;
            }
            char delimiter;
            std::string time, text;
            time = lineofFile.substr(2,9);
            text = lineofFile.substr(11);
            time_read.set_from_string_time(time);
            Message m_aux(text, date_read, time_read);

            messages.push_back(m_aux);
            message_size = message_size + 1;
        }
        
    }
    archive.close();
}

void Diary::add(const std::string& message) {
    Date now_date(0,0,0);
    Time now_time(0,0,0);
    now_date.set_from_string_date(get_current_date());
    now_time.set_from_string_time(get_current_time());
    Message aux(message,now_date,now_time);

    messages.push_back(aux);
    write();
    message_size = message_size + 1;
    
}

void Diary::write(){
    std::ifstream archive(filename);
    int exist;
    if(archive.fail()){
        //file_error();
        exist=-1;
    }else{
        exist = dateExists(archive, messages[message_size].date);
    }
    
    archive.close();
    std::ofstream record(filename,std::ios::app);
    if(record.fail()){
        file_error();
        return;
    }else{
        if (exist==-1){
            record << "\n# " << messages[message_size].date.get_date_string() << std::endl;
        }
        record <<"- "<< messages[message_size].time.get_time_string()<< " " << messages[message_size].content << std::endl;
        
    }
    record.close();
}

std::vector<Message*> Diary::search(const std::string& looked_str) {
    std::vector<Message*> result;
    for (int i = 0; i < message_size; ++i) {
        if ((messages[i].content).find(looked_str) != std::string::npos) {
            result.push_back(&messages[i]);
        }
    }
    return result;
}

