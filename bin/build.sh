#! /bin/bash
#SBATCH --job-name=prac1            # Название задачи
#SBATCH --ntasks=1                     # Количество MPI процессов
#SBATCH --nodes=1                      # Требуемое кол-во узлов
#SBATCH --cpus-per-task=1              # Требуемое кол-во CPU
#SBATCH --constraint=type_a
#SBATCH --account=proj_1339

MAX_SIZE=3000
echo "CPP"
# Building cpp files:
cmake --build build
cmake --build build --target install
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
