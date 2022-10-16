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

typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::milliseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

template <class T>
struct benchresult {
    matrix<T> result;
    double btime;
};

template <class T>
benchresult<T> time_function(matrix<T>& a, matrix<T>& b) {
    TimeVar t1 = timeNow();
    benchresult<T> res = { matmul(a, b), duration(timeNow() - t1) };
    return res;
}

int main(int argc, char* argv[])
{
    size_t m, n, p, r;

    std::cin >> m >> n;
    matrix<double> a(m, n);
    a.fill_matrix();

    std::cin >> p >> r;
    matrix<double> b(p, r);
    b.fill_matrix();

    benchresult<double> benchresult = time_function(a, b);

    std::cout << "Size of matrices: (" << m << ", " << n << "),"
                << " (" << p << ", " << r << ")\n"
                << "Timing: " << benchresult.btime << " ms\n"
                << "GFLOPS: " << m * n * p * 2 * 1e-9 << std::endl;

    return 0;
}
