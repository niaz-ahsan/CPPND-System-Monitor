#ifndef FILE_UP_TIME_H
#define FILE_UP_TIME_H

#include <string>
#include "file_reader.h"

using namespace std;

class File_Up_Time : public File_Reader {
public:
    File_Up_Time(const string& path) : File_Reader(path) {}

    long get_desired_value();   
};

#endif