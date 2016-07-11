one:
	gcc gen.c
	./a.out >pointin
	gcc LR.c
	./a.out <pointin
