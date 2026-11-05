#include "MatrixFactory.hpp"

Matrix MatrixFactory::fill(std::size_t rows, std::size_t cols, double value) {
    Matrix result(rows, cols);

    result.traverseMatrix([&](std::size_t i, std::size_t j, double value) {
        result(i, j) = value;
    });

    return result;
}

Matrix MatrixFactory::zeros(std::size_t rows, std::size_t cols) {
    return fill(rows, cols, 0.0);
}

Matrix MatrixFactory::ones(std::size_t rows, std::size_t cols) {
    return fill(rows, cols, 1.0);
}

Matrix MatrixFactory::identity(std::size_t n) {
    return diagonal(std::vector<double>(n, 1.0));
}

Matrix MatrixFactory::diagonal(const std::vector<double>& diagonalValues) {
    std::size_t n = diagonalValues.size();
    Matrix result(n, n);
    result.traverseMatrix([&](std::size_t i, std::size_t j, double value) {
        if (i == j) {
            result(i, j) = diagonalValues[i];
        }
    });
    return result;
}

Matrix MatrixFactory::random(std::size_t rows, std::size_t cols) {
    Matrix result(rows, cols);
    result.traverseMatrix([&](std::size_t i, std::size_t j, double value) {
        result(i, j) = static_cast<double>(rand()) / RAND_MAX;
    });
    return result;
}

void MatrixFactory::setElement(Matrix& matrix, std::size_t row, std::size_t col, double value) {
    matrix(row, col) = value;
}
