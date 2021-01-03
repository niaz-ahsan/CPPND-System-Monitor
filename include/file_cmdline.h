#ifndef FILE_CMDLINE_H
#define FILE_CMDLINE_H

#include "file_reader.h"
#include <string>

using namespace std;

class File_CmdLine : public File_Reader {
public:
    File_CmdLine(const string& path) : File_Reader(path) {}
    string get_desired_value();
};

#endif