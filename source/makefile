#Makefile

CC = gcc
OBJS = data.o dice.o curses_init.o print.o control.o main.o result.o
OPTION = -lncurses

Africa : $(OBJS)
	cc -o $@ $(OBJS) $(OPTION) -W

#サフィックスルール
.c.o :
	$(CC) -c $<

clean :
	rm *.o
