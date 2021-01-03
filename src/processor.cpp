#include "processor.h"
#include "file_processor.h"
#include "linux_parser.h"

#include <string>
#include <vector>

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 
    string path = LinuxParser::kProcDirectory + LinuxParser::kStatFilename;
    File_Processor processor = File_Processor(path);
    processor.parse_and_store_cpu_data();
    vector<int> cpu_data = processor.get_cpu_data();
    float output = calculation(cpu_data);
    return output;
}

float Processor::calculation(vector<int>& cpu_data) {
    // do the calc
    int user_time = cpu_data[0] - cpu_data[8];
    int nice_time = cpu_data[1] - cpu_data[9];
    int idle_time = cpu_data[3] + cpu_data[4];
    int sys_time = cpu_data[2] + cpu_data[5] + cpu_data[6];
    int virtual_time = cpu_data[8] + cpu_data[9];
    int total_time = user_time + nice_time + sys_time + idle_time + cpu_data[7] + virtual_time;
    int usage = total_time - idle_time;
    float percentage = (float) usage / total_time;
    return percentage;
}