#ifndef TIMER_H
#define TIMER_H
#include "array_types.hpp"
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

#endif
