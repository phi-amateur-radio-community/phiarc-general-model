// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// tests/PagmTest.cpp
// Tests of PAGM.

#include <fcntl.h>
#include <gtest/gtest.h>
#include <pagm/math/Matrix.hpp>
#include <pagm/model/Tokenizer.hpp>

using namespace std;

TEST(MatrixTest, ToString) {
    const Matrix matrix(3, 2);
    const string s = matrix.toString();
    EXPECT_EQ("       0.000        0.000\n       0.000        0.000\n       0.000        0.000", s);
}

TEST(MatrixTest, SetValue) {
    const Matrix matrix(2, 2);
    matrix.setData(1, 1, 1.0f);
    const string s = matrix.toString();
    EXPECT_EQ("       0.000        0.000\n       0.000        1.000", s);
}

TEST(MatrixTest, SaveLoad) {
    const Matrix matrix(2, 2);
    matrix.setData(0, 0, 3.3f);
    matrix.setData(0, 1, 1.9f);
    matrix.setData(1, 0, 3.7f);
    matrix.setData(1, 1, 1.2f);
    EXPECT_EQ(matrix.saveFile("test", 100), true);

    const int fd = open("test_0", O_RDONLY);
    const Matrix matrix_saved(2, 2, &fd);
    EXPECT_EQ(matrix_saved, matrix);

    matrix.setData(1, 1, 1.3f);
    EXPECT_NE(matrix_saved, matrix);
}

TEST(TokenizerTest, Encode) {
    EXPECT_EQ(encodeToken(Token(SpecialToken::BOS)), 0);
    EXPECT_EQ(encodeToken(Token('>')), 3);
    EXPECT_EQ(encodeToken(Token('A')), 4);
    EXPECT_EQ(encodeToken(Token('Z')), 29);
    EXPECT_EQ(encodeToken(Token('a')), 30);
    EXPECT_EQ(encodeToken(Token('0')), 56);
    EXPECT_EQ(encodeToken(Token('.')), 66);
}