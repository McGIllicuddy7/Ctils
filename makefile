build: main.cpp 
	gcc main.cpp -std=c++17 -lm -g3 -fsanitize=address
generate: generator.c 
	gcc generator.c -g3 -std=c2x -lm
