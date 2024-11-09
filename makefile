build: main.c
	gcc main.c -std=c2x -lm -g3 -fsanitize=address
generate: generator.c 
	gcc generator.c -g3 -std=c2x -lm
