
CC = gcc
CFLAGS = -Wall -g

TARGET = terminal_clicker.exe

all: $(TARGET)

$(TARGET): terminal_clicker.c
	$(CC) $(CFLAGS) terminal_clicker.c -o $(TARGET)
clean:
	if exist $(TARGET) del /F /Q $(TARGET)
