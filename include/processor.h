#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <vector>
 
using namespace std; 

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
    float calculation(vector<int>&);
};

#endif