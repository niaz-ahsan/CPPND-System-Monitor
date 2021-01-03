#ifndef FILE_PROC_UPTIME_H
#define FILE_PROC_UPTIME_H

#include "file_reader.h"
#include <string>
#include <vector>

using namespace std;

class File_Process_Up_Time : public File_Reader {
public: 
    File_Process_Up_Time(const string& path) : File_Reader(path) {}
    string get_desired_value() {
        File_Reader::read_file();
        File_Reader::parse_file_data_whitespace();
        vector<string> data = File_Reader::get_parsed_data_collection();
        return data[21]; // 22th value
    }
};

#endif