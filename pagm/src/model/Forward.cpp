// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// src/model/Forward.cpp
// Forward pass.

#include <model/Forward.hpp>

Token* Forward::encodeString(const string& content, const size_t len) {
    auto* tokens = new Token[len];
    size_t i = 0;
    for (char c : content) {
        if (i == len) {
            break;
        }
        tokens[i++] = Token(c);
    }
    return tokens;
}

Matrix Forward::makeEmbedding(const Token* tokens, const size_t len) const {
    auto** embedding = new float*[len];
    for (size_t i = 0; i < len; i++) {
        const int code = encodeToken(tokens[i]);
        embedding[i] = embedding_.getRow(code);
    }
    const Matrix matrix(embedding, rows_, cols_);
    return matrix;
}
