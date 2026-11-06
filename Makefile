CC = gcc
CFLAGS = -Wall -Wextra -g

DESTDIR = /

all: in2bin
in2bin:
	$(CC) $(CFLAGS) -c main.c -o main.o
	$(CC) $(CFLAGS) main.o -o in2bin

.PHONY: clean install
clean:
	@rm -fv *.o
	@rm -fv in2bin

install:
	@mkdir -pv $(DESTDIR)/usr/bin
	@cp -fv in2bin $(DESTDIR)/usr/bin
