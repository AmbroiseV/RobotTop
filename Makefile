TARGET  = robottop
SRCS    = $(TARGET).c
CC      = gcc
CFLAGS  = -O2 -std=gnu99 -Wall 
LDFLAGS = -lrobotdriver -lm

all: $(TARGET)

test: tests
	./$<

clean:
	rm -f $(TARGET) tests
