default: main

flags = -std=c++20

main: dist build build/main.o build/ComplexNumberInt.o build/ComplexNumberFloat.o
	g++ $(flags) -o dist/main build/main.o build/ComplexNumberInt.o build/ComplexNumberFloat.o

build/main.o: build src/main.cpp
	g++ $(flags) -o build/main.o -c src/main.cpp

build/ComplexNumberInt.o: build src/ComplexNumberInt.cpp
	g++ $(flags) -o build/ComplexNumberInt.o -c src/ComplexNumberInt.cpp

build/ComplexNumberFloat.o: build src/ComplexNumberFloat.cpp
	g++ $(flags) -o build/ComplexNumberFloat.o -c src/ComplexNumberFloat.cpp


# clean method
clean:
	rm dist/main
	rm build/*.o

# create required dirs
dist:
	mkdir dist

build:
	mkdir build