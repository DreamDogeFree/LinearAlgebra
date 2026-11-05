#include "Matrix.hpp"
#include<stdexcept>
#include <iostream>

Matrix::Matrix(std::size_t rows, std::size_t cols)
    : rows_(rows), cols_(cols), data_(rows * cols, 0.0) {}

double& Matrix::operator()(std::size_t row, std::size_t col) {
    checkIndex(row, rows_);
    checkIndex(col, cols_);

    return data_[row * cols_ + col];
}

double Matrix::operator()(std::size_t row, std::size_t col) const {
    checkIndex(row, rows_);
    checkIndex(col, cols_);
    
    return data_[row * cols_ + col];
}

std::size_t Matrix::getRows() const {
    return rows_;
}

std::size_t Matrix::getCols() const {
    return cols_;
}

/*Matrix Matrix::operator+(const Matrix& other) const{
    checkMatrixAddition(other);
    Matrix result(rows_, cols_);
    for(std::size_t i=0;i<rows_;++i){
        for(std::size_t j=0;j<other.cols_;++j){
            result(i,j)=(*this)(i,j)+other(i,j);
        }
    }
    return result;

}*/

Matrix Matrix::operator+(const Matrix& other) const{
    checkMatrixAddition(other);
    Matrix result(rows_, cols_);
    traverseMatrix([&](std::size_t i, std::size_t j, double value) {
        result(i, j) = value + other(i, j);
    });
    return result;

}


/*Matrix Matrix::operator-(const Matrix& other) const{
    checkMatrixAddition(other);
    Matrix result(rows_, cols_);
    for(std::size_t i=0;i<rows_;++i){
        for(std::size_t j=0;j<other.cols_;++j){
            result(i,j)=(*this)(i,j)-other(i,j);
        }
    }
    return result;

}*/
Matrix Matrix::operator-(const Matrix& other) const{
    checkMatrixAddition(other);
    Matrix result(rows_, cols_);
    traverseMatrix([&](std::size_t i, std::size_t j, double value) {
        result(i, j) = value - other(i, j);
    });
    return result;

}


Matrix Matrix::operator*(double scalar) const{
    Matrix result(rows_, cols_);
    traverseMatrix([&](std::size_t i, std::size_t j, double value) {
        result(i, j) = value * scalar;
    });
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    checkMatrixMultiplication(other);

    Matrix result(rows_, other.cols_);
    for (std::size_t i = 0; i < rows_; ++i) {
        for (std::size_t k = 0; k < cols_; ++k) {
            const double a = (*this)(i, k);
            for (std::size_t j = 0; j < other.cols_; ++j) {
                result(i, j) += a * other(k, j);
            }
        }
    }
    return result;
}

void Matrix::checkMatrixAddition(const Matrix& other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        throw std::invalid_argument("Incompatible matrix dimensions for addition.");
    }
}

void Matrix::checkMatrixMultiplication(const Matrix& other) const {
    if (cols_ != other.rows_) {
        throw std::invalid_argument("Incompatible matrix dimensions for multiplication.");
    }
}

void Matrix::checkIndex(std::size_t index, std::size_t limit) const {
    if (index >= limit) {
        throw std::out_of_range("Index out of range.");
    }
}