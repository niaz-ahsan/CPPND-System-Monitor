#ifndef FILE_READER_CPP
#define FILE_READER_CPP

#include "file_reader.h"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void File_Reader::read_file() {
    _file.open(_path);
    string file_line;
    if(_file) {
        while(getline(_file, file_line)) {
            _file_data += file_line + "\n";
        }
    }
    _file.close();
}

void File_Reader::parse_file_data_new_line(int max_iter = 50) {
    stringstream streamer(_file_data);
    string substr;
    int iter = 0;
    while(streamer.good()) {
        if(iter == max_iter) {
            break;
        }
        getline(streamer, substr, '\n');
        _parsed_data_collection.push_back(substr);
        iter++;
    }
}

void File_Reader::parse_file_data_whitespace() {
    istringstream istreamer(_file_data);
    string word;
    while(istreamer) {
        istreamer >> word;
        _parsed_data_collection.push_back(word);
    }
}

#endif
    