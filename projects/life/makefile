all:

Life.log:
	git log > Life.log

Doxyfile:
	doxygen -g

html: Doxyfile Life.h Life.c++ RunLife.c++ TestLife.c++
	doxygen Doxyfile

RunLife: Life.h Life.c++ RunLife.c++
	g++-4.7 -pedantic -std=c++11 -Wall Life.c++ RunLife.c++ -o RunLife

RunLifeCell.out: RunLife
	RunLife > RunLifeCell.out

RunLifeCell.tmp: RunLife
	RunLife > RunLifeCell.tmp
	diff RunLifeCell.tmp RunLifeCell.out

RunLifeConway.out: RunLife
	RunLife > RunLifeConway.out

RunLifeConway.tmp: RunLife
	RunLife > RunLifeConway.tmp
	diff RunLifeConway.tmp RunLifeConway.out

RunLifeFredkin.out: RunLife
	RunLife > RunLifeFredkin.out

RunLifeFredkin.tmp: RunLife
	RunLife > RunLifeFredkin.tmp
	diff RunLifeFredkin.tmp RunLifeFredkin.out

TestLife: Life.h Life.c++ TestLife.c++
	g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Life.c++ TestLife.c++ -o TestLife -lgtest -lgtest_main -lpthread

TestLife.out: TestLife
	valgrind TestLife        >  TestLife.out 2>&1
	gcov-4.7 -b Life.c++     >> TestLife.out
	gcov-4.7 -b TestLife.c++ >> TestLife.out

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f RunLife
	rm -f RunLifeCell.out
	rm -f RunLifeCell.tmp
	rm -f RunLifeConway.out
	rm -f RunLifeConway.tmp
	rm -f RunLifeFredkin.out
	rm -f RunLifeFredkin.tmp
	rm -f TestLife
	rm -f TestLife.out
