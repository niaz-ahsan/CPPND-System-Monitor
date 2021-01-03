#ifndef FILE_MEMORY_H
#define FILE_MEMORY_H

#include <string>
#include <unordered_map>
#include "file_reader.h"

using namespace std;

class File_Memory : public File_Reader {
public:
    File_Memory(const string& path) : File_Reader(path) {}

    float calculate_utilization();   
private:
    unordered_map<string, float> _memory_data;
    void store_data(); 
};

#endif