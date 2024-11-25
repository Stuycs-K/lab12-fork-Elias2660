.PHONY: clean compile run

run: runner
	@./runner

compile runner: main.o randomfuncs.o
	@gcc -Wall -o runner main.o randomfuncs.o

randomfuncs.o: randomfuncs.c randomfuncs.h
	@gcc -Wall -c randomfuncs.c

main.o: main.c randomfuncs.h
	@gcc -Wall -c main.c

clean:
	rm runner
	rm -rf *.o