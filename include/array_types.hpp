#ifndef ARRAY_TYPES_H
#define ARRAY_TYPES_H

#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

template <class T>
class matrix
{
public:
    matrix(int m, int n)
    {
        this->rows_ = m;
        this->cols_ = n;
        this->p = new double*[rows_];
        for (int i = 0; i < rows_; ++i) {
            p[i] = new double[cols_];
        }
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                p[i][j] = 0;
            }
        }
    }

    ~matrix()
    {
        for (int i = 0; i < rows_; ++i) {
            delete[] p[i];
        }
        delete[] p;
    }


    void print_matrix() {
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                std::cout << p[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }


    void fill_matrix() {
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                std::cin >> p[i][j];
            }
        }
    }


    void generate_matrix() {
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                p[i][j] = (T)rand();
            }
        }
    }

    int rows_, cols_;
    T **p;
};

#endif