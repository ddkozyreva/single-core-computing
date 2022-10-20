#include "data_generator.hpp"
#define MIN_SIZE 100
#define MAX_SIZE 3000

int main(int argc, char* argv[])
{
    size_t m, n, p, r;
    std::vector<int> vector_of_sizes;
    std::vector<int> vector_of_times;
    std::string name_of_dir = "data/data_files/";
    for (int matrix_size = MIN_SIZE; matrix_size <= MAX_SIZE; matrix_size += 100) {
        size_t dim1 = matrix_size;
        size_t dim2 = matrix_size;
        size_t dim3 = matrix_size;
        std::string file_name = name_of_dir + std::to_string(matrix_size) + ".txt";
        data_generator<double>(file_name, dim1, dim2, dim3);
        std::cout << file_name << "\n";
    }
    return 0;
}