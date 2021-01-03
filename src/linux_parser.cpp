#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>

#include "linux_parser.h"

#include "file_os.h"
#include "file_kernel.h"
#include "file_memory.h"
#include "file_processes.h"
#include "file_up_time.h"
#include "file_cmdline.h"
#include "file_process_memory.h"
#include "file_process_up_time.h"
#include "file_process_cpu_utilization.h"
#include "file_process_user.h"
#include "file_uid_to_user.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  /*string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;*/
  // <------- customized ----->
  File_OS os = File_OS(kOSPath);
  string key = "PRETTY_NAME";
  return os.get_desired_value(key);

}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  /*string os, kernel;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> kernel;
  }
  return kernel;*/
  /************** customized *************/
  File_Kernel kernel = File_Kernel(kProcDirectory + kVersionFilename);
  return kernel.get_desired_value();
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      //cout << "File name --> " << filename << endl;
      if(std::all_of(filename.begin(), filename.end(), ::isdigit)) {
        //cout << "File name -->" << filename << endl;
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// TODO: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() { 
  File_Memory memory = File_Memory(kProcDirectory + kMeminfoFilename);
  return memory.calculate_utilization();
}

// TODO: Read and return the system uptime
long LinuxParser::UpTime() { 
  File_Up_Time uptime = File_Up_Time(kProcDirectory + kUptimeFilename); 
  return uptime.get_desired_value();  
}

// TODO: Read and return the number of jiffies for the system
/*long LinuxParser::Jiffies() { return 0; }

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid[[maybe_unused]]) { return 0; }

// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() { return 0; }

// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() { return 0; }

// TODO: Read and return CPU utilization
vector<string> LinuxParser::CpuUtilization() { return {}; } */

// TODO: Read and return the total number of processes
int LinuxParser::TotalProcesses() { 
  File_Processes processes = File_Processes(kProcDirectory + kStatFilename);
  return processes.find_process_counts(kProcessFlag);
}

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() { 
  File_Processes processes = File_Processes(kProcDirectory + kStatFilename);
  return processes.find_process_counts(kRunningProcessFlag);
}

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid) { 
  string file_path = kProcDirectory + to_string(pid) + kCmdlineFilename;
  File_CmdLine reader = File_CmdLine(file_path);
  return reader.get_desired_value();
}

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid) { 
  string file_path = kProcDirectory + to_string(pid) + kStatusFilename;
  File_Process_Memory instance = File_Process_Memory(file_path);
  return instance.get_desired_value("VmSize");
}

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid) {
    string file_path = kProcDirectory + to_string(pid) + kStatusFilename;
    File_Process_User instance = File_Process_User(file_path);
    return instance.get_desired_value();
}

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid) {
    string uid = Uid(pid);
    File_UID_to_User instance = File_UID_to_User(kPasswordPath, uid);
    return instance.get_desired_value();
}

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(int pid) {
  string file_path = kProcDirectory + to_string(pid) + kStatFilename;
  File_Process_Up_Time instance = File_Process_Up_Time(file_path); 
  long p_timestamp = stoi(instance.get_desired_value()) / sysconf(_SC_CLK_TCK);
  long p_uptime = UpTime() - p_timestamp;
  return p_uptime;  
}

float LinuxParser::CpuUtilization(int pid) {
    string file_path = kProcDirectory + to_string(pid) + kStatFilename;
    File_Process_CPU_Utilization instance = File_Process_CPU_Utilization(file_path);
    vector<int> data = instance.get_desired_values();
    float total_time = (float)(data[0] + data[1] + data[2] + data[3]) / sysconf(_SC_CLK_TCK);
    float seconds = (float)UpTime() - (float)(data[4] / sysconf(_SC_CLK_TCK));
    float percentage = (float)(total_time / seconds);
    return percentage;
}