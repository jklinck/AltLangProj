# AltLangProj

## Running the Project

To run the project you can use the Makefile to create the executable by typing the word `make` 
into the terminal. That will create the executable and you can run the project with `./main`. 

If you recompile make sure to run `make clean` first to delete the previous executable. While this 
is not always necessary, there is the possibilty that the new executable doesn't remove all of the 
old build artifcats. 

You can also run `make run` which will delete the previous executable, create a new executable, 
clear the terminal and run the project.

You will need to download `Catch 2` testing framework to run the tests. Put the download into the 
same directory as where you put the project. You can fine the download here: 
https://github.com/catchorg/Catch2/releases/tag/v3.8.1
Click on the zip file to download. Make sure to download this exact version since the file path 
in the include statement in tests/test.cpp depends upon it. 

To run tests you first have to compile the tests `make tests` and then run `./test`.

## Project Details

C++ does not allow strings or floats to be null. Empty strings will be represented as `-` and a 
null float value will be represented as `0.0`. While it does allow ints to be NULL, for the sake 
of continuity all NULL ints in this project will be represented as `0`. No other data types are 
used in any of the cells.

The 7 functions I have added are mostly in functions.cpp except toString() which is in Cell.cpp.