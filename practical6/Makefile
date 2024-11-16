CC = gcc
CPROGS = $(shell ls *.c)
OBJ = $(CPROGS:.c=.o)

all: prog

prog: $(OBJ)
	$(CC) -o $@ $^ -lm

$(OBJ):
	$(CC) -c $(@:.o=.c)

clean:
	/bin.rm -f *.o
