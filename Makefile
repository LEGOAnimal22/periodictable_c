OBJS += electron.o main.o
TARGET := periodic_table.so

%.o: %.c
	$(CC) -I./ -o $@ -c $^

target_: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -Wall -I./ -o $@ $^

all: target_

clean:
	rm -fr $(OBJS)

.PHONY:
	all clean
