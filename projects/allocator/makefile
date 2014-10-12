all:

Allocator.log:
	git log > Allocator.log

Doxyfile:
	doxygen -g

html: Doxyfile Allocator.h Allocator.c++ TestAllocator.c++
	doxygen Doxyfile

TestAllocator: Allocator.h Allocator.c++ TestAllocator.c++
	g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Allocator.c++ TestAllocator.c++ -o TestAllocator -lgtest -lgtest_main -lpthread

TestAllocator.out: TestAllocator
	valgrind TestAllocator        >  TestAllocator.out 2>&1
	gcov-4.7 -b Allocator.c++     >> TestAllocator.out
	gcov-4.7 -b TestAllocator.c++ >> TestAllocator.out

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f TestAllocator
	rm -f TestAllocator.out
