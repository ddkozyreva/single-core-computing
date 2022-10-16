#include "array_types.hpp"
#include "timer.hpp"
#include "linalg.hpp"

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
