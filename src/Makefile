CC = gcc
CFLAGS = -g -c
AR = ar -rc
RANLIB = ranlib


Target: linked_list.o queue.o multilevel_queue.o

# my_pthread.a: my_pthread.o my_data_structures.o my_scheduler.o
# 	$(AR) libmy_pthread.a my_pthread.o my_data_structures.o my_scheduler.o
# 	$(RANLIB) libmy_pthread.a

linked_list.o: linked_list.h
	$(CC) $(CFLAGS) linked_list.c

queue.o: queue.h
	$(CC) $(CFLAGS) queue.c

multilevel_queue.o: multilevel_queue.h
	$(CC) $(CFLAGS) multilevel_queue.c

clean:
	rm -rf testfile *.o *.a
