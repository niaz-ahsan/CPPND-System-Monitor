#include "file_processor.h"
#include "file_reader.h"

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

void File_Processor::parse_and_store_cpu_data() {
    File_Reader::read_file();
    File_Reader::parse_file_data_new_line(1);
    vector<string> data = File_Reader::get_parsed_data_collection();
    string_parsing(data[0]);
}

void File_Processor::string_parsing(string& data) {
    data = data.substr(data.find(" ")+1); // cropping "cpu from string"
    istringstream streamer(data);
    string each_data;
    while(streamer >> each_data) {
        cpu_data.push_back(stoi(each_data));
    }
}