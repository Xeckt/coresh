run:
	gcc ./src/main.c -o ./coresh && ./coresh

debug:
	valgrind ./coresh