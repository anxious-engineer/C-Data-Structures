CC = gcc
CFLAGS = -g -c
AR = ar -rc
RANLIB = ranlib


Target: linked_list.o queue.o multilevel_queue.o hashtable.o

linked_list.o: linked_list.h
	$(CC) $(CFLAGS) linked_list.c

queue.o: queue.h
	$(CC) $(CFLAGS) queue.c

multilevel_queue.o: multilevel_queue.h
	$(CC) $(CFLAGS) multilevel_queue.c

hashtable.o: hashtable.h
	$(CC) $(CFLAGS) hashtable.c

clean:
	rm -rf testfile *.o *.a
