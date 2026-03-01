// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// tests/PagmTest.cpp
// Tests of PAGM.

#include <gtest/gtest.h>
#include <pagm/math/Matrix.hpp>

using namespace std;

TEST(MatrixTest, ToString) {
    const Matrix matrix(3, 2);
    string s = matrix.to_string();
    EXPECT_EQ("       0.000        0.000\n       0.000        0.000\n       0.000        0.000", s);
}