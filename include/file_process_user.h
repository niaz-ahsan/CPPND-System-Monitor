#ifndef FILE_PROCESS_USER_H
#define FILE_PROCESS_USER_H

#include "file_reader.h"
#include <sstream>

using namespace std;

class File_Process_User : public File_Reader {
public:
    File_Process_User(const string& path) : File_Reader(path) {}
    
    string get_desired_value() {
        File_Reader::read_file();
        File_Reader::parse_file_data_new_line(9);
        vector<string> data = File_Reader::get_parsed_data_collection();
        istringstream streamer(data[8]);
        int iter = 0;
        string val;
        while(streamer >> val) {
            if(iter == 2) {
                break;
            }
        }
        return val;
    }
};

#endif