# Combined Makefile for performance_test2, test_OSULL, and Test

# Default target
all: performance_test2 test_OSULL Test

# Compile performance_test2
performance_test2: performance_test2.o OSLL.o
	g++ -Wall -o performance_test2 performance_test2.o OSLL.o

performance_test2.o: performance_test2.cpp OSLL.h
	g++ -Wall -o performance_test2.o -c performance_test2.cpp

# Compile test_OSULL
test_OSULL: test_OSULL.o OSULL.o
	g++ -Wall -o test_OSULL test_OSULL.o OSULL.o

test_OSULL.o: test_OSULL.cpp OSULL.h
	g++ -Wall -o test_OSULL.o -c test_OSULL.cpp

# Compile Test
Test: Test.o
	g++ -Wall -o Test Test.o

Test.o: Test.cpp OSLL.h 
	g++ -Wall -o Test.o -c Test.cpp 

# Compile OSLL.cpp and OSULL.cpp
OSLL.o: OSLL.cpp OSLL.h
	g++ -Wall -o OSLL.o -c OSLL.cpp

OSULL.o: OSULL.cpp OSULL.h
	g++ -Wall -o OSULL.o -c OSULL.cpp

# Clean all compiled files
clean:
	rm -f performance_test2 test_OSULL Test *.o

