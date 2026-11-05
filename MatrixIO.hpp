#pragma once
#include <string>
#include "Matrix.hpp"

class MatrixIO {

    public:
        static void print(const Matrix& matrix);
        static Matrix read(const std::string& filename);
        static void write(const Matrix& matrix, const std::string& filename);

};