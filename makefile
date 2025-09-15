CC = g++
CFLAGS = -Wall -Wextra -g -std=c++20
TARGET = alley_p2

all: alley_p2 test

test: alley_p2
	./alley_p2 LLLLL 1111
	./alley_p2 LLLLL 0000
	./alley_p2 LLLLL 10101010
	./alley_p2 LLLLL 01010101
	./alley_p2 RRRRR 1111
	./alley_p2 LRLRL 1111
	./alley_p2 RLRLR 1111
	./alley_p2 RRLRR 1111
	./alley_p2 LRLLRL 1111
	./alley_p2 LLLLL 1111 1002

alley_p2: alley_p2.o
	$(CC) $(CFLAGS) -o alley_p2 alley_p2.o

alley_p2.o: alley_p2.cpp
	$(CC) $(CFLAGS) -c alley_p2.cpp

clean:
	rm -f alley_p2 *.o
