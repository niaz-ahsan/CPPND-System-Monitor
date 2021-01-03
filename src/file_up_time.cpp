#include "file_up_time.h"
#include "file_reader.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

long File_Up_Time::get_desired_value() {
    File_Reader::read_file();
    File_Reader::parse_file_data_whitespace();
    vector<string> data = File_Reader::get_parsed_data_collection();
    return stoi(data[0]);
}