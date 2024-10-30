build: main.c 
	gcc main.c -fsanitize=address -g3 -std=c2x
generate: generator.c 
	gcc generator.c -g3 -std=c2x
