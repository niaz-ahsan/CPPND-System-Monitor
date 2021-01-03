#ifndef FILE_UID_TO_USER_H
#define FILE_UID_TO_USER_H

#include "file_reader.h"
#include <sstream>
#include <algorithm>

using namespace std;

class File_UID_to_User : public File_Reader {
public:
    File_UID_to_User(const string& path, const string& uid) : File_Reader(path), uid(uid) {}
    
    string get_desired_value() {
        File_Reader::read_file();
        string data = File_Reader::get_raw_file_data();
        replace(data.begin(), data.end(), ':', ' ');
        istringstream streamer(data);
        string username, domain, value, output;
        while(streamer >> username >> domain >> value) {
            if(value == uid) {
                output = username;
                break;
            }
        }
        return output;
    }  
private:
    string uid;      
}; 

#endif