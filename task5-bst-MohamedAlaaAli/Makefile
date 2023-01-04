all: a.out

a.out: tests/test.cpp my_tree.h
	g++ -std=c++11 tests/test.cpp -o a.out

test: a.out
	./a.out

clean:
	rm a.out