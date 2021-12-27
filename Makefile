CC			= gcc
CFLAGS	= -Wall -g 
LDFLAGS 	= -lm
OBJFILES	= main.o base_converter.o
TARGET	= tp
all: main.o base_converter.o
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
main.o: main.c
	gcc -Wall -c main.c
base_converter.o: base_converter.c
	gcc -Wall -c base_converter.c
clean:
	rm -f $(OBJFILES) $(TARGET) *~
