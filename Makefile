CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

SRC = src/<> main.c
OBJ = $(SRC:.c=.o)

TARGET = app

all : $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
