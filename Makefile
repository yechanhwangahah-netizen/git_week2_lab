CC = gcc

C004: main.c class.o myclass.o
	$(CC) -o $@ $^

class.o: class.c class.h
	$(CC) -c $<

myclass.o: myclass.c class.h
	$(CC) -c $<

clean:
	rm -f *.o C004
