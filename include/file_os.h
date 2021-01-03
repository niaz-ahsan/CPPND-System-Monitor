#ifndef FILE_OS
#define FILE_OS

#include <string>
#include "file_reader.h"

using namespace std;

class File_OS : public File_Reader {
public:
    File_OS(const string& path) : File_Reader(path) {}
    
    string get_desired_value(string);    
};

#endif