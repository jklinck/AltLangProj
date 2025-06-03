# AltLangProj

## Report

I picked C++, I chose this language as I already know C and a couple OOP langauges and wanted to 
see how they combined. I somewhat regret my decision as I see what people mean when they say C++ 
can be a real pain. C++ handles OOP/file ingestion/conditions/etc. pretty much the same as Java 
does wit the excpetion that C++ uses pointers. I used many libraries in this project: Catch2 
testing library for tests, unorder_map for creating a hashmap, and cmath so I could perfrom 
some rounding in functions.cpp. 

## Running the Project

To run the project type `make run` into the terminal. This will delete the previous executable (if 
there is one), create a new executable, clear the terminal and run the project.

To run tests, cd into the tests directory and type `make run` into the terminal. This will delete 
the previous executable (if there is one), create a new executable, clear the terminal and run the 
project.

While running the project and running tests looks similar and uses the same command, they are 
coming from separate Makefiles. There is a main Makefile for the project and then the tests 
directory has it's own Makefile. 

## Project Details

C++ does not allow strings or floats to be null. Empty strings will be represented as `-` and a 
null float value will be represented as `0.0`. While it does allow ints to be NULL, for the sake 
of continuity all NULL ints in this project will be represented as `0`. No other data types are 
used in any of the cells.

The 7 functions I have added are mostly in functions.cpp except toString() which is in Cell.cpp.