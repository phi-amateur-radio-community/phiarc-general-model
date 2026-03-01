// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// include/pagm/model/Transformer.hpp
// Header file of model body.

#pragma once

#include <string>

#include "Forward.hpp"

using namespace std;

class Transformer {
    Forward forward;
public:
    explicit Transformer(string file_path);
};