#pragma once
#include <vector>
#include "Matrix.hpp"

class MatrixAlgebra {
    
    public:
        static Matrix add(const Matrix& A, const Matrix& B);
        static Matrix sub(const Matrix& A, const Matrix& B);
        static Matrix mul(const Matrix& A, const Matrix& B);
        static Matrix mul(const Matrix& A, double scalar);
        static Matrix transpose(const Matrix& A);
    
};

