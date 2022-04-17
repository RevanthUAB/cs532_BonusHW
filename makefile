OBJS	= main.o commands.o
SOURCE	= main.c commands.c
HEADER	= myhead.h
OUT	= uab_sh
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c 

commands.o: commands.c
	$(CC) $(FLAGS) commands.c 


clean:
	rm -f $(OBJS) $(OUT)