// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// src/io/Parameter.cpp
// IO reader and writer of model parameter.

#include <format>
#include <ios>
#include <iostream>
#include <unistd.h>
#include <io/Parameter.hpp>

using namespace std;

Parameter::Parameter(const string& fileName, const string& fileExpand, const size_t& fileSize) {
    fileName_ = fileName;
    fileExpand_ = fileExpand;
    fileSize_ = fileSize;
    count_ = 0;
    free_ = fileSize_;
    createFd();
}

void Parameter::createFd() {
    const string fileName = fileName_ + to_string(count_++) + fileExpand_;
    file_ = ofstream(fileName, ios::binary | ios::trunc);
    if (!file_.is_open()) {
        cerr << "Error creating file " << fileName << endl;
        exit(1);
    }
    free_ = fileSize_;
}

void Parameter::saveParameter(const float* data, const size_t& dataSize) {
    size_t savedSize = 0;
    size_t unsaveSize = dataSize;
    for (;;) {
        const bool saveEnd = unsaveSize <= free_;
        const size_t saveSize = saveEnd ? unsaveSize : free_;
        file_.write(reinterpret_cast<const char *>(data) + savedSize, static_cast<streamsize>(saveSize));
        if (saveEnd) {
            free_ -= saveSize;
            break;
        }
        savedSize += saveSize;
        unsaveSize -= saveSize;
        createFd();
    }
};

float* readParameter(const size_t mem_size,  const int* fd) {
    auto* data = static_cast<float *>(malloc(mem_size * sizeof(float)));
    size_t index = 0;
    size_t total = 0;
    while (total < mem_size) {
        if (const ssize_t n = read(fd[index], reinterpret_cast<char *>(data) + total, mem_size); n < 0) {
            perror("read");
            exit(1);
        } else if (n == 0) {
            index ++;
        } else {
            total += n;
        }
    }
    return data;
}