CC = gcc
CFLAGS = -Ithird/SDL3/x86_64-w64-mingw32/include
LDFLAGS = -Lthird/SDL3/x86_64-w64-mingw32/lib -lSDL3

all: game.exe

game.exe: main.o
	$(CC) main.o -o game.exe $(LDFLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

clean:
	del *.o *.exe