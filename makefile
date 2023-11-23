CC = gcc
CFLAGS = -Wall -fpic
LDFLAGS = -shared

SRC = dotenv.c
OBJ = $(SRC:.c=.o)
LIB = libdotenv.so

all: $(LIB)

$(LIB): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(LIB)
