#Makefile

CC = gcc
OBJS = main.o data.o dice.o curses_init.o print.o
OPTION = -lncurses

Africa : $(OBJS)
	cc -o $@ $(OBJS) $(OPTION) -W
	rm *.o

#サフィックスルール
.c.o :
	$(CC) -c $<

clean :
	rm *.o

