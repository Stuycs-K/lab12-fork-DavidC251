compile runme: fork.o fork.h main.o
	@gcc -o runme fork.o main.o

main.o: main.c fork.h
	@gcc -c main.c

fork.o: fork.c fork.h
	@gcc -c fork.c

run: runme
	@./runme

clean:
	@rm *.o
	@rm runme
