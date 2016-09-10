TARGET  = robottop
SRCS    = main.c
CC      = gcc
CFLAGS  = -O2 -std=gnu99 -Wall -Werror
LDFLAGS = -lrobotdriver -lm

all: $(TARGET)

clean:
	rm -f $(TARGET)
