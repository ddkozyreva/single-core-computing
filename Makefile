all: data_gen on_supercomputer
	

clean:
	rm -rf build/* bin/data_generator bin/for_supercomputer bin/program
	rm -rf data/data_files/*
on_supercomputer:
	g++ for_supercomputer/main.cpp -o bin/for_supercomputer
	sh bin/for_supercomputer.sh

cmake:
	sh bin/build.sh

data_gen:
	mkdir -p data/data_files
	g++ data/data_generator.cpp -o bin/data_generator
	./bin/data_generator