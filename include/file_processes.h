#ifndef FILE_PROCESSES_H
#define FILE_PROCESSES_H

#include "file_reader.h"
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class File_Processes : public File_Reader {
public:
    File_Processes(const string& path) : File_Reader(path) {}
    int find_process_counts(const string&);
private:     
    
};

#endif