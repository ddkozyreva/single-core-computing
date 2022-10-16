#ifndef LINALG_H
#define LINALG_H

#include "array_types.hpp"

template <class T>
matrix<T> matmul(matrix<T>& a, matrix<T>& b)
{   
    size_t rows_of_a = a.rows_;
    size_t cols_of_a = a.cols_;
    size_t rows_of_b = b.rows_;
    size_t cols_of_b = b.cols_;
    matrix<T> result(rows_of_a, rows_of_b);

    if (cols_of_a == cols_of_b) {
        for (size_t i = 0; i < rows_of_a; i++) {
            for (size_t j = 0; j < rows_of_b; j++)
            {
                result.p[i][j] = 0;
                for (size_t k = 0; k < cols_of_a; k++)
                {
                    result.p[i][j] += a.p[i][k] * b.p[j][k];
                }
            }
        }
    } else {
        printf("Matrix multiplication is not possible due to uncorrect dimensions.\n");
    }
   
    return result;
}

#endif
