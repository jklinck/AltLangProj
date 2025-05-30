main: src/Main.cpp src/Phone.cpp
	g++ -o main src/Main.cpp src/Phone.cpp -Iinclude

clean: 
	rm -f main


