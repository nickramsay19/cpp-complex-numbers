default: main

flags = -std=c++20

main: dist build build/main.o build/ComplexNumber.o
	g++ $(flags) -o dist/main build/main.o build/ComplexNumber.o

build/main.o: build src/main.cpp
	g++ $(flags) -o build/main.o -c src/main.cpp

build/ComplexNumber.o: build src/ComplexNumber.cpp
	g++ $(flags) -o build/ComplexNumber.o -c src/ComplexNumber.cpp


# clean method
clean:
	rm dist/main
	rm build/*.o

# create required dirs
dist:
	mkdir dist

build:
	mkdir build