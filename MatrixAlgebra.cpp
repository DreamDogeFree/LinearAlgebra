#include "MatrixAlgebra.hpp"
#include <stdexcept>

Matrix MatrixAlgebra::add(const Matrix& A, const Matrix& B) {
    A.checkMatrixAddition(B);
    Matrix result(A.getRows(), A.getCols());
    A.traverseMatrix([&](std::size_t i, std::size_t j, double value) {
        result(i, j) = value + B(i, j);
    });
    return result;
}

Matrix MatrixAlgebra::sub(const Matrix& A, const Matrix& B) {
    A.checkMatrixAddition(B);
    Matrix result(A.getRows(), A.getCols());
    A.traverseMatrix([&](std::size_t i, std::size_t j, double value) {
        result(i, j) = value - B(i, j);
    });
    return result;
}

Matrix MatrixAlgebra::mul(const Matrix& A, const Matrix& B) {
    A.checkMatrixMultiplication(B);
    Matrix result(A.getRows(), B.getCols());
    for (std::size_t i = 0; i < A.getRows(); ++i) {
        for (std::size_t k = 0; k < A.getCols(); ++k) {
            const double a = A(i, k);
            for (std::size_t j = 0; j < B.getCols(); ++j) {
                result(i, j) += a * B(k, j);
            }
        }
    }
    return result;
}

Matrix MatrixAlgebra::mul(const Matrix& A, double scalar) {
    Matrix result(A.getRows(), A.getCols());
    A.traverseMatrix([&](std::size_t i, std::size_t j, double value) {
        result(i, j) = value * scalar;
    });
    return result;
}

Matrix MatrixAlgebra::transpose(const Matrix& A) {
    Matrix result(A.getCols(), A.getRows());
    A.traverseMatrix([&](std::size_t i, std::size_t j, double value) {
        result(j, i) = value;
    });
    return result;
}
