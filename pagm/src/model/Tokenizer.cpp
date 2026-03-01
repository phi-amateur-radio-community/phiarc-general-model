// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// src/model/Tokenizer.cpp
// Token encoder and decoder.

#include <Tokenizer.hpp>

using namespace std;

int encodeToken(const Token token) {
    return visit([&]<typename T0>(T0&& val) -> int {
        using T = decay_t<T0>;
        if constexpr (is_same_v<T, char>) {
            return tokenEncoder[val];
        } else {
            return static_cast<int>(val);
        }
    }, token.value);
}

Token decodeToken(const int index) {
    return tokenDecoder[index];
}