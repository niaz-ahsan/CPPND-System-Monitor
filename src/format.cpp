#include <string>
#include <iostream>

#include "format.h"

#define HOUR 3600
#define MIN 60

using namespace std;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
    string output;
    int h = seconds / HOUR;
    int s = seconds % HOUR; // remaininng after we got hour... similar way to get remaining (min n sec)
    int m = s / MIN; 
    s %= MIN;
    output = formatPadding(h) + ":" + formatPadding(m) + ":" + formatPadding(s);
    return output; 
}

string Format::formatPadding(int& data) {
    string output = to_string(data);
    if(data < 10) {
        output = "0" + output;
    }
    return output;
}