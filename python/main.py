import random
import numpy as np
import time
class Matrix:
    def __init__(self, m, n):
        self.rows_ = m
        self.cols_ = n
        self.p = np.zeros((m, n))

    def fill_matrix(self):
        for i in range(self.rows_):
            row = []
            while len(row) != self.cols_:
                row = list(map(float, input().split()))
            self.p[i] = np.array(row)
        return self.p

    def generate_matrix(self):
        for i in range(self.rows_):
            for j in range(self.cols_):
                self.p[i][j] = random.uniform(0, 1)
        return self.p

    def set_lengths(self, rows, cols):
        self.rows_ = int(rows)
        self.cols_ = int(cols)
        self.p = np.zeros((rows, cols))
        

    def matrix_multiplicate_on_transpose(self, b):
        rows_of_a = self.rows_
        cols_of_a = self.cols_
        rows_of_b = b.rows_
        cols_of_b = b.cols_
        c = Matrix(rows_of_a, rows_of_b)
        start = time.time()
        if cols_of_a == cols_of_b:
            for i in range(rows_of_a):
                for j in range(rows_of_b):
                    c.p[i][j] = 0
                    for k in range(cols_of_a):
                        c.p[i][j] += self.p[i][k] * b.p[j][k]   
        else:
            print(f'Matrix multiplication is not possible due to uncorrect dimensions.\n')
            c = Matrix(0,0)
        end = time.time()
        duration = round((end - start) * 1000)
        return c, duration

    def print_matrix(self):
        for i in range(self.rows_):
            for j in range(self.cols_):
                print(self.p[i][j], end = ' ')
            print()

if __name__ == '__main__':
    a = Matrix(0,0)
    b = Matrix(0,0)

    rows_of_a, cols_of_a = list(map(int, input().split()))
    a.set_lengths(rows_of_a, cols_of_a)
    a.fill_matrix()

    rows_of_b, cols_of_b = list(map(int, input().split()))
    b.set_lengths(rows_of_b, cols_of_b)
    b.fill_matrix()
    
    c, duration = a.matrix_multiplicate_on_transpose(b)
    print(f'For matrices A{a.rows_, a.cols_} and B{b.rows_, b.cols_}'
        f'\nTiming: {duration}\n'
        f'GFLOPS: {rows_of_a * cols_of_a * rows_of_b * 2 * 1e-9}')
    a.p = []
    b.p = []
    c.p = []