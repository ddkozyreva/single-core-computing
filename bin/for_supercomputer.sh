#! /bin/bash
#SBATCH --job-name=prac1            # Название задачи
#SBATCH --ntasks=1                     # Количество MPI процессов
#SBATCH --nodes=1                      # Требуемое кол-во узлов
#SBATCH --cpus-per-task=1              # Требуемое кол-во CPU
#SBATCH --constraint=type_a
#SBATCH --account=proj_1339

MAX_SIZE=2300
echo "CPP"
for ((i=100; i <= $MAX_SIZE; i+=100))
do
    ./bin/for_supercomputer < "./data/data_files/${i}.txt"
done

module load Python
echo "PYTHON"
for ((i=100; i <= $MAX_SIZE; i+=100))
do
    python3 ./python/main.py < "./data/data_files/${i}.txt"
done
