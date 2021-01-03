#include "file_cmdline.h"
#include "file_reader.h"
#include <string>
#include <iostream>

using namespace std;

string File_CmdLine::get_desired_value() {
    File_Reader::read_file();
    return File_Reader::get_raw_file_data();
}
