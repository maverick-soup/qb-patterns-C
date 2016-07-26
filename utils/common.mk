
CC=gcc
CFLAGS:=-std=c99 -Wall -Wextra -Wpedantic -Werror -c
LDFLAGS=

OBJECTS=$(SOURCES:.c=.o)

.PHONY : all
all : app

app : $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY : clean
clean :
	rm $(OBJECTS) $(EXECUTABLE)

