#include "file_processes.h"
#include "file_reader.h"

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int File_Processes::find_process_counts(const string& flag) {
    File_Reader::read_file();
    string raw_data = File_Reader::get_raw_file_data();
    size_t start = raw_data.find(flag);
    if(start != string::npos) {
        string from_process_data = raw_data.substr(start); // everything after "processes"/"proc_running" keyword
        stringstream streamer(from_process_data);
        string line;
        getline(streamer, line, '\n'); // need only the 1st line
        int count = stoi(line.substr(line.find(" ")+1));
        return count;
    }
    return 0;
}

