CC = g++
CFLAGS = -Wall -Wextra -g -std=c++20
TARGET = alley_p2

all: alley_p2 test

# test: alley_p2

alley_p2: alley_p2.o
	$(CC) $(CFLAGS) -o alley_p2 alley_p2.o

alley_p2.o: alley_p2.cpp
	$(CC) $(CFLAGS) -c alley_p2.cpp

clean:
	rm -f alley_p2 *.o
