#include "file_os.h"
#include "file_reader.h"

#include <string>
#include <vector>

using namespace std;
    
string File_OS::get_desired_value(string search_key) {
    File_Reader::read_file();
    File_Reader::parse_file_data_new_line(5); // get 0-4 line data
    vector<string> collection = File_Reader::get_parsed_data_collection();
    string key;
    string value;
    string delim = "=";
    for (string data : collection) {
        key = data.substr(0, data.find(delim));
        value = data.substr(data.find(delim)+2, data.length()-key.length()-3); // adding subtracting 2 or 3 to avoid double quotes
        if(key.compare(search_key) == 0) {
            break;
        }        
    }
    return value;
}
