build: main.c
	gcc main.c tests.c -lm -std=c2x -g3 -fsanitize=address
generate: generator.c 
	gcc generator.c -g3 -std=c2x -lm
cpp: main.cpp
	g++ main.cpp -lm -g3 -fsanitize=address -Wall -Wextra -pedantic

