TARGET = sw
CC = gcc
CFLAGS = -g -Wall

KERNEL = kernel.cl
OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
LIBS   = -lm -lOpenCL -lrt
endif
ifeq ($(UNAME), Darwin)
LIBS     = -framework OpenCL
endif

.PHONY: default all clean

default: $(TARGET)
all: default

%.o: %.c $(HEADERS)
	$(CC)  -c $< -o $@

$(TARGET): $(OBJECTS) $(KERNEL)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) -o $(TARGET)

clean:
	rm -f $(OBJECTS)

cleanall: clean
	rm -f $(TARGET)
