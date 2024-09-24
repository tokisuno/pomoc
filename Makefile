CC = gcc
CFLAGS = -Wall -Wextra

make:
	$(CC) $(CFLAGS) main.c -o pomoc

format:
	@echo TODO

install: 
	mv pomoc /usr/local/bin/
