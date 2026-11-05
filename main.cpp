#include "Matrix.hpp"
#include "MatrixIO.hpp"
#include "MatrixFactory.hpp"
#include <iostream>
#include <stdexcept>

int main() {

    // 1. 创建矩阵并设置元素
    std::cout << "===== 1. Matrix Construction =====" << std::endl;

    Matrix A(2, 3);

    A(0, 0) = 1.0;
    A(0, 1) = 2.0;
    A(0, 2) = 3.0;
    A(1, 0) = 4.0;
    A(1, 1) = 5.0;
    A(1, 2) = 6.0;

    std::cout << "Matrix A:" << std::endl;
    MatrixIO::print(A);


    // 2. 获取矩阵维度
    std::cout << "\n===== 2. Matrix Dimensions =====" << std::endl;

    std::cout << "Rows: " << A.getRows() << std::endl;
    std::cout << "Cols: " << A.getCols() << std::endl;


    // 3. 元素访问
    std::cout << "\n===== 3. Element Access =====" << std::endl;

    std::cout << "A(0, 1) = " << A(0, 1) << std::endl;

    MatrixFactory::setElement(A, 0, 1, 10.0);

    std::cout << "After setElement:" << std::endl;
    MatrixIO::print(A);


    // 4. 矩阵加法
    std::cout << "\n===== 4. Matrix Addition =====" << std::endl;

    Matrix B(2, 3);

    B(0, 0) = 1.0;
    B(0, 1) = 1.0;
    B(0, 2) = 1.0;
    B(1, 0) = 1.0;
    B(1, 1) = 1.0;
    B(1, 2) = 1.0;

    Matrix C = A + B;

    std::cout << "A + B:" << std::endl;
    MatrixIO::print(C);


    // 5. 矩阵减法
    std::cout << "\n===== 5. Matrix Subtraction =====" << std::endl;

    Matrix D = A - B;

    std::cout << "A - B:" << std::endl;
    MatrixIO::print(D);


    // 6. 矩阵数乘
    std::cout << "\n===== 6. Scalar Multiplication =====" << std::endl;

    Matrix E = A * 2.0;

    std::cout << "A * 2:" << std::endl;
    MatrixIO::print(E);


    // 7. 矩阵乘法
    std::cout << "\n===== 7. Matrix Multiplication =====" << std::endl;

    Matrix F(3, 2);

    F(0, 0) = 1.0;
    F(0, 1) = 2.0;
    F(1, 0) = 3.0;
    F(1, 1) = 4.0;
    F(2, 0) = 5.0;
    F(2, 1) = 6.0;

    Matrix G = A * F;

    std::cout << "A * F:" << std::endl;
    MatrixIO::print(G);


    // 8. 异常检查：矩阵加法维度不匹配
    std::cout << "\n===== 8. Exception Testing =====" << std::endl;

    try {
        Matrix H(3, 3);
        Matrix I = A + H;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Addition Error: " << e.what() << std::endl;
    }


    // 9. 异常检查：矩阵乘法维度不匹配
    try {
        Matrix J(4, 2);
        Matrix K = A * J;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Multiplication Error: " << e.what() << std::endl;
    }

    return 0;
}