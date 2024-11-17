CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -lcheck -lm -lsubunit

SRC = src/main.c 
TEST_SRC = tests/test_pile.c

BIN = build/main
TEST_BIN = build/test

all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

test: $(TEST_SRC)
	$(CC) $(CFLAGS) -o $(TEST_BIN) tests/test_pile.c $(LDFLAGS)
	./$(TEST_BIN)

clean:
	rm -f $(BIN) $(TEST_BIN)
