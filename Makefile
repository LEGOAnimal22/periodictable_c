# Makefile for Periodic Table(C)

# directory
SOURCE_DIR = ./source

OBJS += $(SOURCE_DIR)/electron.o $(SOURCE_DIR)/elements.o $(SOURCE_DIR)/main.o
TARGET := periodic_table.so

%.o: %.c
	$(CC) -I./include -o $@ -c $^

target_: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -Wall -I./include -o $@ $^

all: target_

clean:
	rm -fr $(OBJS)

.PHONY:
	all clean
