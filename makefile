make: main.c 
	gcc main.c -fsanitize=address -g3 -std=c2x
