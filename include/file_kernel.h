#ifndef FILE_KERNEL_H
#define FILE_KERNEL_H

#include <string>
#include "file_reader.h"

using namespace std;

class File_Kernel : public File_Reader {
public:
    File_Kernel(const string& path) : File_Reader(path) {}

    string get_desired_value();   
};

#endif