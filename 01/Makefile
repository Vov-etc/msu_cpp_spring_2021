CC=g++
FLAGS=-std=c++17 -Wall -Werror -Wextra -Wno-unused-variable

all: my_prog

my_prog: main.o allocator.o
	$(CC) $(FLAGS) -o my_prog main.o allocator.o

main.o: main.cpp allocator.h
	$(CC) $(FLAGS) -c main.cpp
    
square.o: allocator.cpp allocator.h
	$(CC) $(FLAGS) -c allocator.cpp

test:
	my_prog

clean:
	@echo (Resolve-Path .\).Path
	rm -rf *.o my_prog
