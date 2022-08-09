a.out: green.o blue.o
	cc green.o blue.o

green.o: green.c common.h
	cc -c green.c

blue.o: blue.c common.h
	cc -c blue.c

clean:
	rm -rf *.o a.out *~
