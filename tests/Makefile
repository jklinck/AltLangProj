tests:
	g++ -o tests test.cpp ../src/Cell.cpp ../src/functions.cpp -Iinclude -I../Catch2 -lCatch2

clean: 
	rm -f tests

run: 
	make clean && make && clear && ./tests