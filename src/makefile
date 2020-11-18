OBJS	= printtime.o
SOURCE	= printtime.c
HEADER	= 
OUT	= printtime
CC	 = gcc
FLAGS	 = -g3 -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

printtime.o: printtime.c
	$(CC) $(FLAGS) printtime.c -std=gnu17 -lcunit


clean:
	rm -f $(OBJS) $(OUT)

debug: ./$(OUT)
	valgrind ./$(OUT) 2h0

valgrind: ./$(OUT)
	valgrind ./$(OUT) 2h0

valgrind_leakcheck: ./$(OUT)
	valgrind --leak-check=full ./$(OUT) 2h0

valgrind_extreme: ./$(OUT)
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes ./$(OUT) 2h0make