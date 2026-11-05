#pragma once
#include <cstddef>
#include <vector>
#include "Matrix.hpp"

class MatrixFactory {

    public:
        static Matrix zeros(std::size_t rows, std::size_t cols);
        static Matrix ones(std::size_t rows, std::size_t cols);
        static Matrix identity(std::size_t n);
        static Matrix diagonal(const std::vector<double>& diagonalValues);
        static Matrix random(std::size_t rows, std::size_t cols);
        static void setElement(Matrix& matrix, std::size_t row, std::size_t col, double value);

    private:
        static Matrix fill(std::size_t rows, std::size_t cols, double value);
        
};