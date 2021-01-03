#ifndef FILE_PROCESS_UTIL_H
#define FILE_PROCESS_UTIL_H

#include "file_reader.h"

using namespace std;

class File_Process_CPU_Utilization : public File_Reader {
public: 
    File_Process_CPU_Utilization(const string& path) : File_Reader(path) {}
    vector<int> get_desired_values() {
        vector<int> output;
        File_Reader::read_file();
        File_Reader::parse_file_data_whitespace();
        vector<string> data = File_Reader::get_parsed_data_collection();
        output = {stoi(data[13]), stoi(data[14]), stoi(data[15]), stoi(data[16]), stoi(data[21])};
        return output;
    }    
};

#endif