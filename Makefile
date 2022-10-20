all: data_gen on_supercomputer
	

clean:
	rm -rf build/* bin/data_generator bin/for_supercomputer bin/program
	rm -rf data/data_files/*
on_supercomputer:
	g++ -O3 -march=native for_supercomputer/main.cpp -o bin/for_supercomputer
	sbatch -A proj_1339 bin/for_supercomputer.sh

task:
	g++ for_supercomputer/main.cpp -o bin/program
	sh bin/build.sh

cmake:
	sh bin/build.sh

data_gen:
	mkdir -p data/data_files
	g++ data/data_generator.cpp -o bin/data_generator
	./bin/data_generator