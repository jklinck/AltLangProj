# AltLangProj

C++ does not allow strings or floats to be null. Empty strings will be represented as `-` and a 
null float value will be represented as `0.0`. While it does allow ints to be NULL, for the sake 
of continuity all NULL ints in this project will be represented as `0`. No other data types are 
used in any of the cells.

To run the project you can use the Makefile to create the executable by typing the word `make` 
into the terminal. That will create the executable and you can run the project with `./main`. 

If you recompile make sure to run `make clean` first to delete the previous executable. While this 
is not always necessary, there is the possibilty that the new executable doesn't remove all of the 
old build artifcats. 