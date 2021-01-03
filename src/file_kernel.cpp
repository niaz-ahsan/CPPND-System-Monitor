#include "file_kernel.h"
#include "file_reader.h"

#include <string>
#include <vector>

using namespace std;

string File_Kernel::get_desired_value() {
    File_Reader::read_file();
    File_Reader::parse_file_data_whitespace();
    vector<string> collection = File_Reader::get_parsed_data_collection();
    return collection[2];
}
