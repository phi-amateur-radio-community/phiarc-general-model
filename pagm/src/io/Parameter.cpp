// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// src/io/Parameter.cpp
// IO reader and writer of model parameter.

#include <unistd.h>
#include <io/Parameter.hpp>

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