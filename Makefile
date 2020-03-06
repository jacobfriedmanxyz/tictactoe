CC = c89
CFLAGS = -Wall -O3
PREFIX = ~/.local

tictactoe: main.c
	$(CC) $< -o $@

.PHONY: clean
clean:
	rm tictactoe

.PHONY: install
install: tictactoe
	cp $< $(PREFIX)/bin/
