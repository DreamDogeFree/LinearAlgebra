#include "MatrixTransform.hpp"
#include <utility>

Matrix MatrixTransform::swapRows(const Matrix& matrix, std::size_t row1, std::size_t row2) {
    matrix.checkIndex(row1, matrix.getRows());
    matrix.checkIndex(row2, matrix.getRows());

    Matrix result = matrix;
    matrix.traverseMatrix([&](std::size_t i, std::size_t j) {
        if (i == row1) {
            std::swap(result(row1, j), result(row2, j));
        }
        
    });
    return result;
}

