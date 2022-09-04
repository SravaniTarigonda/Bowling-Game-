OBJS= main.o 
CO = gcc -o
CC = gcc -c
RM = rm *.o

test: $(OBJS)
	$(CO) test $(OBJS) -lpthread

main.o : main.c 
	$(CC) main.c


clean:
	$(RM)
