build: main.cpp
	clang++ main.cpp -lm -std=c++20 -g3 -fsanitize=address
generate: generator.c 
	gcc generator.c -g3 -std=c2x -lm
