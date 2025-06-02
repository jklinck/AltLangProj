# For compiling and linking. 
main: src/main.cpp src/Cell.cpp src/functions.cpp
	g++ -o main src/main.cpp src/Cell.cpp src/functions.cpp -Iinclude

# Delete the previous executable. 
clean: 
	rm -f main

# Everything in the kitchen sink, delete the previous executable, create a new one, 
# clear the command line and run the new executable.
run:
	make clean && make && clear && ./main


