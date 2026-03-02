// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// include/pagm/model/Forward.hpp
// Header file of forward pass.

#pragma once

#include <math/Matrix.hpp>
#include <model/Tokenizer.hpp>

using namespace std;

class Forward {
    Matrix embedding_;
    size_t rows_;
    size_t cols_;
    static Token* encodeString(const string& content, size_t len);
    Matrix makeEmbedding(const Token* tokens, size_t len) const;
public:
    Matrix makeForward(string& content);
};

// TODO(Forward) Get QKV Matrix and make RoPE