#ifndef FILE_READER_H
#define FILE_READER_H

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class File_Reader {
public:
    File_Reader(const string& path) : _path(path) {}
protected:
    void read_file();

    void parse_file_data_new_line(int); 

    void parse_file_data_whitespace();

    vector<string> get_parsed_data_collection() const {
        return _parsed_data_collection;
    }

    string get_raw_file_data() const {
        return _file_data;
    }
private:
    ifstream _file;
    string _path;
    string _file_data; // overall file data
    vector<string> _parsed_data_collection; 
};

#endif