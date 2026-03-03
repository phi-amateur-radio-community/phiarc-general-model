// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// src/math/Matrix.hpp
// Implementation of PAGM Matrix.

#include <math/Matrix.hpp>
#include <cstdlib>
#include <cstring>
#include <format>
#include <string>
#include <vector>

using namespace std;

Matrix::Matrix(const size_t rows, const size_t cols) {
    data_ = static_cast<float *>(calloc(rows * cols, sizeof(float)));
    rows_ = rows;
    cols_ = cols;
    mem_size_ = rows * cols * sizeof(float);
}

Matrix::Matrix(const size_t rows, const size_t cols, const int* fd) {
    rows_ = rows;
    cols_ = cols;
    mem_size_ = rows * cols * sizeof(float);
    data_ = readParameter(mem_size_, fd);
}

Matrix::Matrix(float** data, const size_t rows, const size_t cols) {
    data_ = static_cast<float *>(malloc(rows * cols * sizeof(float)));
    rows_ = rows;
    cols_ = cols;
    mem_size_ = rows * cols * sizeof(float);
    for (size_t i = 0; i < rows; i ++) {
        memcpy(data_ + i * cols, data[i], sizeof(float) * cols);
    }
}

float Matrix::getData(const size_t row, const size_t col) const {
    return data_[row * cols_ + col];
}

void Matrix::setData(const size_t row, const size_t col, const float data) const {
    data_[row * cols_ + col] = data;
}

float* Matrix::getRow(const size_t row) const {
    return &data_[row * cols_];
}

pmr::vector<float> Matrix::getRowCopy(const size_t col) const {
    pmr::vector<float> row(getRow(col), getRow(col + 1));
    return row;
}

string Matrix::toString() const {
    string s;
    s.reserve(13 *rows_ * cols_);
    for (size_t i = 0; i < rows_ ; i ++) {
        for (size_t j = 0; j < cols_; j ++) {
            s += format("{:>12.3f}", getData(i, j));
            s += j == cols_-1 ? '\n' : ' ';
        }
    }
    s.pop_back();
    return s;
}

void Matrix::saveFile(Parameter& parameter) const {
    parameter.saveParameter(data_, mem_size_);
}

bool Matrix::operator==(const Matrix &matrix) const {
    return matrix.mem_size_ == mem_size_ && memcmp(data_, matrix.data_, mem_size_) == 0;
}

bool Matrix::operator!=(const Matrix &matrix) const {
    return !(*this == matrix);
}