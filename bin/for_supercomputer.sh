#!/bin/sh
#SBATCH --cpus-per-task=1 
#SBATCH --job-name=hw1
#SBATCH --constraint="type_d|type_c"

MAX_SIZE=3000
echo "CPP"
mkdir -p output
for ((i=100; i <= $MAX_SIZE; i+=100))
do
    touch "output/output_cpp_${i}.txt"
    ./bin/program < "./data/data_files/${i}.txt" > "output/output_${i}.txt"
done

module load Python
echo "PYTHON"
for ((i=100; i <= $MAX_SIZE; i+=100))
do
    touch "output/output_python_${i}.txt"
    python3 ./python/main.py < "./data/data_files/${i}.txt" > "output/output_python_${i}.txt"
done