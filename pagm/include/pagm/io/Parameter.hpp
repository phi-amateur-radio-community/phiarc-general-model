// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// include/pagm/io/Parameter.hpp
// Header file of parameter file handle.

#pragma once

#include <string>
#include <fstream>

using namespace std;

class Parameter {
    string fileName_;
    string fileExpand_;
    ofstream file_;
    size_t count_;
    size_t free_;
    size_t fileSize_;
    void createFd();
public:
    Parameter(const string& fileName, const string& fileExpand, const size_t& fileSize);
    void saveParameter(const float* data, const size_t& dataSize);
};

float* readParameter(size_t mem_size,  const int* fd);