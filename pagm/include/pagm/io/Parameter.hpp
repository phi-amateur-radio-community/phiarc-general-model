// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// include/pagm/io/Parameter.hpp
// Header file of parameter file handle.

#pragma once

#include <string>

using namespace std;

bool multiOutstream();

float* readParameter(size_t mem_size,  const int* fd);