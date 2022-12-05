CC=g++
CFLAGS=-g -Wall -Wshadow -Wvla -Werror -pedantic
DEBUG=gdb
SRC_H=heap.h
SRC_C=heap.cpp main.cpp
EXECUTABLE=heap

$(EXECUTABLE):$(SRC_H) $(SRC_C)
	$(CC) -o heap $(CFLAGS) heap.cpp main.cpp

debug:
	$(DEBUG) heap

clean:
	rm ./$(EXECUTABLE)