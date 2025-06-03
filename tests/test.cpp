#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
// #include "../Catch2/src/catch2/catch_all.hpp"
// #include <catch2/catch_test_macros.hpp>
// #include <catch2/catch_session.hpp>

#include "../Catch2/src/catch2/catch_test_macros.hpp"
#include "../Catch2/src/catch2/catch_session.hpp"



#include "../include/Cell.h"
#include "../include/functions.h"

TEST_CASE("Make sure launchAnnounced is turned into an int, bodyWeight and displaySize are 
turned into floats") {
    Cell newCell = new Cell("a", "b", "5", "c", "d", "3.4", "e", "f", "5.7", "g", "h", "i");
    REQUIRE(newCell.getLaunchAnnounced() == 5);
    REQUIRE(newCell.bodyWeight() == 3.4);
    REQUIRE(newCell.getDisplaySize() == 5.7);
}

// git submodule add https://github.com/catchorg/Catch2.git


/*
I spent hours trying to get this thing working. I tried everything I possibly could and 
have zero clue why it is still giving me errors about not finding files that I can clearly see 
are there. Not mater what I do I always get some type of error like this:

g++ -o tests tests/test.cpp src/Cell.cpp src/functions.cpp -Iinclude -I../Catch2/src/catch2 -I../Catch2/src/catch2/internal
In file included from tests/test.cpp:7:
tests/../Catch2/src/catch2/catch_test_macros.hpp:11:10: fatal error: 'catch2/internal/catch_test_macro_impl.hpp' file not found
   11 | #include <catch2/internal/catch_test_macro_impl.hpp>
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1 error generated.
make: *** [tests] Error 1

It says it can't find it but the file is clearly there. I altered my tests command in the Makefile 
probably a hundred times to no avail. I've tried changing from andgle braket (pre-processor) includes 
at the top of this file to the regular double quote includes. Every change I make will just give 
another iteration of the error above. 


*/
