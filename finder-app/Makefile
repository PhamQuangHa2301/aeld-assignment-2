CROSS_COMPILE ?=
SRC_FOLDER = ./

CC      := $(CROSS_COMPILE)gcc
CXX     := $(CROSS_COMPILE)g++
LD      := $(CROSS_COMPILE)ld
OBJCOPY := $(CROSS_COMPILE)objcopy

TARGET = $(SRC_FOLDER)/writer

all: $(TARGET)

$(TARGET): $(SRC_FOLDER)/writer.c
	$(CC) $(SRC_FOLDER)/writer.c -o $(TARGET)

clean: 
	rm -f $(TARGET) *.o

.PHONY: all clean