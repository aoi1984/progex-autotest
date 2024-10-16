main: main.c
	gcc main.c -o main
test: main test1 test2 exp1 exp2
	./main < test1 > test1.out
	diff exp1 test1.out; 
	./main < test2 > test2.out
	diff exp2 test2.out; 
clean: 
	rm main test1.out test2.out *~
