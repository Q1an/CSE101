# CSE 101 PA 1 Makefile
#
# DO NOT MODIFY

CC=g++
FLAGS=-std=c++0x -I./

HEADERS=$(wildcard *.hpp)
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

TestDFS.o: testsrc/TestDFS.cpp $(HEADERS)
	$(CC) -I testsrc/ $(FLAGS) -g -c testsrc/TestDFS.cpp

TestSCC.o: testsrc/TestSCC.cpp $(HEADERS)
	$(CC) -I testsrc/ $(FLAGS) -g -c testsrc/TestSCC.cpp

TestWorm.o: testsrc/TestWorm.cpp $(HEADERS)
	$(CC) -I testsrc/ $(FLAGS) -g -c testsrc/TestWorm.cpp

TestTopOrder.o: testsrc/TestTopOrder.cpp $(HEADERS)
	$(CC) -I testsrc/ $(FLAGS) -g -c testsrc/TestTopOrder.cpp

TestDFS: TestDFS.o DFS.o
	$(CC) $(FLAGS) -g -o TestDFS.out TestDFS.o DFS.o

TestSCC: TestSCC.o SCC.o DFS.o
	$(CC) $(FLAGS) -g -o TestSCC.out TestSCC.o SCC.o DFS.o

TestWorm: TestWorm.o Worm.o DFS.o
	$(CC) $(FLAGS) -g -o TestWorm.out TestWorm.o Worm.o DFS.o

TestTopOrder: TestTopOrder.o TopOrder.o DFS.o
	$(CC) $(FLAGS) -g -o TestTopOrder.out TestTopOrder.o TopOrder.o DFS.o

TestAll: TestDFS TestTopOrder TestSCC TestWorm

RotatedArray:
	$(CC) $(FLAGS) -o RotatedArray.out RotatedArray.cpp

%.o: %.cpp
	$(CC) $(FLAGS) -g -c -o $@ $<

clean:
	rm -f *.o
	rm -f *.out
