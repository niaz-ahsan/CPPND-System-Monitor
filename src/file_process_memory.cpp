#include "file_process_memory.h"
#include "file_reader.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string File_Process_Memory::get_desired_value(string search_key) {
    File_Reader::read_file();
    File_Reader::parse_file_data_new_line(18);
    vector<string> collection = File_Reader::get_parsed_data_collection();
    string key;
    string delim = ":";
    string title, val, unit, output;
    for (string data : collection) {
        key = data.substr(0, data.find(delim));    
        if(key.compare(search_key) == 0) {
            istringstream streamer(data);
            while(streamer >> title >> val >> unit) {
                output = val;
            }
            break;
        }        
    }
    if(output.length() > 0) {      
        output = to_string(unit_conversion(stoi(output)));
    }
    return output;
}

int File_Process_Memory::unit_conversion(int data) {
    return data * 0.001;
} 