#ifndef FILE_PROCESS_MEMORY_H
#define FILE_PROCESS_MEMORY_H

#include "file_reader.h"
#include <string>

using namespace std;

class File_Process_Memory : public File_Reader {
public:
    File_Process_Memory(const string& path) : File_Reader(path) {}
    string get_desired_value(string);
private:
    int unit_conversion(int);    
}; 

#endif