// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// src/math/Matrix.hpp
// Implementation of PAGM Matrix.

#include <Matrix.hpp>
#include <cstdlib>
#include <cstring>
#include <format>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

Matrix::Matrix(const size_t rows, const size_t cols) {
    data_ = static_cast<float *>(calloc(rows * cols, sizeof(float)));
    rows_ = rows;
    cols_ = cols;
}

Matrix::Matrix(const size_t rows, const size_t cols, const int* fd) {
    data_ = static_cast<float *>(malloc(rows * cols * sizeof(float)));
    size_t index = 0;
    size_t total = 0;
    const size_t size = rows * cols * sizeof(float);
    while (total < size) {
        if (const ssize_t n = read(fd[index], reinterpret_cast<char *>(data_) + total, size); n < 0) {
            perror("read");
            exit(1);
        } else if (n == 0) {
            index ++;
        } else {
            total += n;
        }
    }
    rows_ = rows;
    cols_ = cols;
}

Matrix::Matrix(float** data, const size_t rows, const size_t cols) {
    data_ = static_cast<float *>(malloc(rows * cols * sizeof(float)));
    rows_ = rows;
    cols_ = cols;
    for (size_t i = 0; i < rows; i ++) {
        memcpy(data_ + i * cols, data[i], sizeof(float) * cols);
    }
}

[[nodiscard]] float Matrix::getData(const size_t row, const size_t col) const {
    return data_[row * cols_ + col];
}

[[nodiscard]] float* Matrix::getRow(const size_t row) const {
    return &data_[row * cols_];
}

[[nodiscard]] pmr::vector<float> Matrix::getRowCopy(const size_t col) const {
    pmr::vector<float> row(getRow(col), getRow(col + 1));
    return row;
}

[[nodiscard]] string Matrix::to_string() const {
    string s;
    s.reserve(13 * this->rows_ * this->cols_);
    for (size_t i = 0; i < this->rows_ ; i ++) {
        for (size_t j = 0; j < this->cols_; j ++) {
            s += format("{:>12.3f}", this->getData(i, j));
            s += j == this->cols_-1 ? '\n' : ' ';
        }
    }
    s.pop_back();
    return s;
}