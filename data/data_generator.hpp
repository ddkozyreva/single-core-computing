#include <iostream>
#include <fstream>

#include <vector>
#include <chrono>
template <class T>
void data_generator(std::string file_name, size_t dim1, size_t dim2, size_t dim3) {
    // Create and open a text file
    std::ofstream MyFile(file_name);

    MyFile << dim1 << " " << dim2 << std::endl;    

    // Write to the file
    for (int i = 0; i < dim1; ++i) {
        for (int j = 0; j < dim2; ++j) {
            MyFile << (T)rand() << " ";
        }
        MyFile << std::endl;
    }

    MyFile << dim3 << " " << dim2 << std::endl;    

    for (int i = 0; i < dim3; ++i) {
        for (int j = 0; j < dim2; ++j) {
            MyFile << (T)rand() << " ";
        }
        MyFile << std::endl;
    }

    // Close the file
    MyFile.close();
}