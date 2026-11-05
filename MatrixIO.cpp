#include "MatrixIO.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>

void MatrixIO::print(const Matrix& matrix) {
    std::cout << "[" << std::endl;
    matrix.traverseMatrix([&](std::size_t i, std::size_t j, double value) {
        std::cout << value << " ";
        if (j + 1 == matrix.getCols()) {
            std::cout << std::endl;
        }
    });
    std::cout << "]" << std::endl;
}

Matrix MatrixIO::read(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("Cannot open file: " + filename);
    }

    std::size_t rows, cols;
    if (!(file >> rows >> cols)) {
        throw std::invalid_argument("Invalid file format: cannot read matrix dimensions.");
    }

    if (rows == 0 || cols == 0) {
        throw std::invalid_argument("Matrix dimensions must be positive.");
    }

    Matrix result(rows, cols);

    result.traverseMatrix([&](std::size_t i, std::size_t j, double value) {
        if (!(file >> value)) {
            throw std::invalid_argument("Invalid file format: cannot read matrix element at (" + 
                std::to_string(i) + ", " + std::to_string(j) + ").");
        }
        result(i, j) = value;
    });

    file.close();
    return result;
}

void MatrixIO::write(const Matrix& matrix, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("Cannot open file for writing: " + filename);
    }

    file << matrix.getRows() << " " << matrix.getCols() << std::endl;

    matrix.traverseMatrix([&](std::size_t i, std::size_t j, double value) {
        if (j > 0) {
            file << " ";
        }
        file << value;
        if (j == matrix.getCols() - 1) {
            file << std::endl;
        }
    });

    file.close();
}