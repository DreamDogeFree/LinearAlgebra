#pragma once

#include "Matrix.hpp"
#include <vector>
#include <cstddef>

class MatrixTransform {
    public:
        static Matrix swapRows(const Matrix& matrix, std::size_t row1, std::size_t row2);
        static void scaleRow(Matrix& matrix, std::size_t row, double scalar);
        static void addRowMultiple(Matrix& matrix, std::size_t sourceRow,
                           std::size_t targetRow, double scalar);
};