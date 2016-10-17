OBJS +=  periodic_table.so electron.o main.o

electron.o:
	$(CC) -I./ -o $@ -c electron.c

main.o:
	$(CC) -I./ -o $@ -c main.c

periodic_table.so:
	$(CC) -Wall -o $@ $(OBJS)

all:
	electron.o main.o periodic_table.so

clean:
	$(RM) -fr $(OBJS)

.PHONY:
	all clean
