CC = gcc
COMP_FLAG = -Wall -g


all: frequency 

frequency: main.o heder.h
	$(CC) -g $(COMP_FLAG)   -o frequency main.o 


main.o: main.c heder.h
	$(CC) $(COMP_FLAG) -c $*.c


.PHONY: clean all 

clean:
	rm -f  *.o frequency

	


