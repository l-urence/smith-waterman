TARGET = sw
CC = gcc
CFLAGS = -Wall -std=c99

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
INCL_P  = -I$(HOME)/inc -I/usr/local/cuda/include
LIBS   = -lm -lOpenCL -lrt
INCL_AMD = -I$(HOME)/inc -I$(AMDAPPSDKROOT)/include
LIBS_AMD = -L$(AMDAPPSDKROOT)/lib/x86_64 $(LIBS)
CFLAGS_AMD  = $(CFLAGS) -DATI_OS_LINUX
endif
ifeq ($(UNAME), Darwin)
INCL_P   = -I$(HOME)/inc
LIBS     = -framework OpenCL
INCL_AMD = $(INCL_P)
LIBS_AMD = $(LIBS)
CFLAGS_AMD = $(CFLAGS)
endif

.PHONY: default all clean

default: $(TARGET)
all: default

%.o: %.c $(HEADERS)
	$(CC)  -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -framework opencl  -o $(TARGET)

clean:
	rm -f $(OBJECTS)

cleanall: clean
	rm -f $(TARGET)
