all: a.out

p1.out: p1/p1_test/test.cpp p1/p1.cpp p1/p1.h
	g++ -std=c++11 p1/p1_test/test.cpp p1/p1.cpp -o p1.out

p2.out: p2/p2_test/test.cpp p2/p2.cpp p2/p2.h
	g++ -std=c++11 p2/p2_test/test.cpp p2/p2.cpp -o p2.out

test1: p1.out
	./p1.out

test2: p2.out
	./p2.out

clean:
	rm *.out