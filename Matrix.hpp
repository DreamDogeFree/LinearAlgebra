#pragma once
#include <vector>
#include <cstddef>



class Matrix {
    public:

        Matrix(std::size_t rows, std::size_t cols);

        std::size_t getRows() const;
        std::size_t getCols() const;

        double& operator()(std::size_t row, std::size_t col);
        double operator()(std::size_t row, std::size_t col) const;

        Matrix operator+(const Matrix& other) const;
        Matrix operator-(const Matrix& other) const;
        Matrix operator*(const Matrix& other) const;
        Matrix operator*(double scalar) const;

    private:

        void checkMatrixAddition(const Matrix& other) const;
        void checkMatrixMultiplication(const Matrix& other) const;
        void checkIndex(std::size_t index, std::size_t limit) const;
        template<typename Function> void traverseMatrix(Function func) const;

        std::size_t rows_;
        std::size_t cols_;
        std::vector<double> data_; //真正存放数字



    friend class MatrixAlgebra;
    friend class MatrixFactory;
    friend class MatrixTransform;
    friend class MatrixIO;




};


enum class TraverseMode {
    All,
    Row,
    Column
};


template<typename Function> void Matrix::traverseMatrix(Function func) const{
    for (std::size_t i = 0; i < rows_; ++i) {
        for (std::size_t j = 0; j < cols_; ++j) {
            func(i, j, (*this)(i, j));
        }
    }
}

