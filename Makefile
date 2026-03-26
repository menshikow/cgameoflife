# Compiler
CC = clang
CFLAGS = -Wall -Wextra -std=c11

# Files
SRC = src/main.c
EXEC = life

# Default target
all: $(EXEC)

# Build executable
$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)

# Clean compiled executable
clean:
	rm -f $(EXEC)