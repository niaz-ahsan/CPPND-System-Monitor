#include "file_memory.h"
#include "file_reader.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

void File_Memory::store_data() {
    File_Reader::read_file();
    File_Reader::parse_file_data_new_line(4); // get 0-3 line data
    vector<string> collection = File_Reader::get_parsed_data_collection(); 
    for(string data : collection) {
        string key = data.substr(0, data.find(":"));
        string value = data.substr(data.find(":")+1, data.length()-key.length()-4); // avoiding space "kb" from the end
        _memory_data[key] = (float)(stoi(value));
    }   
}

float File_Memory::calculate_utilization() {
    store_data();
    float total_memory = _memory_data["MemTotal"] - _memory_data["Buffers"];
    float used_memory = total_memory - _memory_data["MemFree"];
    float utilization = 1.0 - (used_memory/total_memory);
    return utilization;
}


