CC      = gcc
CFLAGS  =
LDFLAGS =
LIBS    =
INCLUDE = -I./include -I/usr/include/ncurses
SRC_DIR = ./source
OBJ_DIR = ./build
SOURCES = $(shell ls $(SRC_DIR)/*.c)
OBJS    = $(subst $(SRC_DIR),$(OBJ_DIR), $(SOURCES:.c=.o))
TARGET  = Africa
DEPENDS = $(OBJS:.o=.d)
OPTION = -lncurses


all: $(TARGET)

$(TARGET): $(OBJS) $(LIBS)
	$(CC) -o $@ $(OBJS) $(OPTION) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	$(RM) $(OBJS) $(TARGET) $(DEPENDS)

-include $(DEPENDS)

.PHONY: all clean
