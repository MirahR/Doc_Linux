
CC = gcc
CFLAGS = -Wall -02

cible: main.c 
    $(CC) $(CFLAGS) -o cible main.c
