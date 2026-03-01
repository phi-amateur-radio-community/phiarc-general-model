// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// include/pagm/math/Matrix.hpp
// Header file of PAGM Matrix.

#pragma once

#include <cstdlib>
#include <memory_resource>
#include <bits/basic_string.h>

using namespace std;

class Matrix {
    float* data_;
public:
    size_t rows_;
    size_t cols_;

    Matrix(size_t rows, size_t cols);

    Matrix(size_t rows, size_t cols, const int* fd);

    Matrix(float** data, size_t rows, size_t cols);

    [[nodiscard]] float getData(size_t row, size_t col) const;

    void setData(size_t row, size_t col, float data) const;

    [[nodiscard]] float *getRow(size_t row) const;

    [[nodiscard]] vector<float, pmr::polymorphic_allocator<float>> getRowCopy(size_t col) const;

    [[nodiscard]] string toString() const;

    [[nodiscard]] bool saveFile(const string& fileName, size_t fileSize) const;
};
