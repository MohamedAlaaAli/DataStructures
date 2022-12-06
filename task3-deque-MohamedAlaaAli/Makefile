all: a.out

a.out: tests/test.cpp deque.cpp deque.h
	g++ -std=c++11 tests/test.cpp deque.cpp -o a.out

test: a.out
	./a.out

clean:
	rm a.out