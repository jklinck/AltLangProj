# For compiling and linking. 
main: src/main.cpp src/Cell.cpp src/functions.cpp
	g++ -o main src/main.cpp src/Cell.cpp src/functions.cpp -Iinclude

# For compiling and linking the Catch2 tests
tests: tests/test.cpp src/Cell.cpp src/functions.cpp
	g++ -o tests tests/test.cpp src/Cell.cpp src/functions.cpp -Iinclude -I../Catch2 -lCatch2

# Delete the previous executable. 
clean: 
	rm -f main

# Deletes the previous executable, create a new one, clear the command line and run the new 
# executable.
run:
	make clean && make && clear && ./main


