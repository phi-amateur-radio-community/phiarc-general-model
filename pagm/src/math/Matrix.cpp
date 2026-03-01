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
#include <fstream>

using namespace std;

Matrix::Matrix(const size_t rows, const size_t cols) {
    data_ = static_cast<float *>(calloc(rows * cols, sizeof(float)));
    rows_ = rows;
    cols_ = cols;
    mem_size_ = rows * cols * sizeof(float);
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
    mem_size_ = rows * cols * sizeof(float);
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

bool Matrix::saveFile(const string& fileName, const size_t fileSize) const {
    size_t unsave_size = this->mem_size_;
    size_t saved_size = 0;
    size_t index = 0;
    while (unsave_size > 0) {
        ofstream ofs(fileName + '_' + to_string(index), ios::binary | ios::trunc);
        if (!ofs.is_open()) {
            return false;
        }
        const size_t save_size = unsave_size < fileSize ? unsave_size : fileSize;
        ofs.write(reinterpret_cast<const char *>(this->data_) + saved_size, static_cast<streamsize>(save_size));
        ofs.close();
        index ++;
        unsave_size -= save_size;
        saved_size += save_size;
    }
    return true;
}

bool Matrix::operator==(const Matrix &matrix) const {
    return matrix.mem_size_ == this->mem_size_ && memcmp(this->data_, matrix.data_, mem_size_) == 0;
}
