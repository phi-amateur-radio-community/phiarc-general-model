// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// include/pagm/model/Tokenizer.hpp
// Header file of Tokenizer.

#pragma once

#include <array>
#include <variant>

using namespace std;

enum class SpecialToken {
    BOS = 0,
    EOS = 1,
    PAD = 2,
    UNK = 3,
};

struct Token {
    variant<char, SpecialToken> value;
};

int encodeToken(Token token);
Token decodeToken(int index);

constexpr array<int, 128> makeTokenEncoder() {
    array<int, 128> map{};
    fill(map.begin(), map.end(), 3);
    int index = 4;

    for (char c = 'A'; c <= 'Z'; c++) map[c] = index++;
    for (char c = 'a'; c <= 'z'; c++) map[c] = index++;
    for (char c = '0'; c <= '9'; c++) map[c] = index++;

    map['.'] = index++;
    map[','] = index++;
    map['?'] = index++;
    map['\''] = index++;
    map['!'] = index++;
    map['/'] = index++;
    map['('] = index++;
    map[')'] = index++;
    map['&'] = index++;
    map[':'] = index++;
    map[';'] = index++;
    map['='] = index++;
    map['+'] = index++;
    map['-'] = index++;
    map['_'] = index++;
    map['"'] = index++;
    map['$'] = index++;
    map['@'] = index++;

    return map;
}

constexpr auto tokenEncoder = makeTokenEncoder();

constexpr array<Token, 84> makeTokenDecoder() {
    array<Token, 84> map;

    map[0].value = SpecialToken::BOS;
    map[1].value = SpecialToken::EOS;
    map[2].value = SpecialToken::PAD;
    map[3].value = SpecialToken::UNK;

    for (char c = 'A'; c <= 'Z'; c++) map[c - 'A' + 4].value = c;
    for (char c = 'a'; c <= 'z'; c++) map[c - 'a' + 30].value = c;
    for (char c = '0'; c <= '9'; c++) map[c - '0' + 56].value = c;

    constexpr char symbols[] = {
        '.', ',', '?', '\'', '!', '/', '(', ')',
        '&', ':', ';', '=', '+', '-', '_', '"',
        '$', '@'
    };

    int index = 66;

    for (char c : symbols) {
        map[index++].value = c;
    }

    return map;
}

constexpr auto tokenDecoder = makeTokenDecoder();