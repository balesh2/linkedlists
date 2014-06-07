all: list.o test_list.o
	gcc list.o test_list.o -o a.out

nine: list.o lab9test_list.o
	gcc list.o lab9test_list.o -g -o nine.out
	
list.o: list.c
	gcc list.c -c

lab9test_list.o: lab9test_list.c
	gcc lab9test_list.c -c

clean:
	rm -f *.out *.o
