ifeq ($(OS),Windows_NT)
    # Windows settings (MinGW)
    CC = gcc
    CFLAGS = -Ithird/SDL3/x86_64-w64-mingw32/include
    LDFLAGS = -Lthird/SDL3/x86_64-w64-mingw32/lib -lSDL3
    TARGET = game.exe
    CLEAN_CMD = del *.o *.exe
else
    # macOS settings (Apple Silicon/Homebrew)
    CC = clang
    CFLAGS = -I/opt/homebrew/include
    LDFLAGS = -L/opt/homebrew/lib -lSDL3 -Wl,-rpath,/opt/homebrew/lib
    TARGET = game
    CLEAN_CMD = rm -f *.o $(TARGET)
endif

all: $(TARGET)

$(TARGET): main.o
	$(CC) main.o -o $(TARGET) $(LDFLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

clean:
	$(CLEAN_CMD)