#ifndef FILE_PROCESSOR_H
#define File_PROCESSOR_H

#include "file_reader.h"
#include <string>
#include <vector>

using namespace std;

class File_Processor : public File_Reader {
public:
    File_Processor(string& path) : File_Reader(path) {}
    void parse_and_store_cpu_data();
    vector<int> get_cpu_data() const { return cpu_data; }
private:
    vector<int> cpu_data;
    void string_parsing(string&);
};

#endif