
CC=gcc
CFLAGS:=-std=c99 -Wall -Wextra -Wpedantic -Werror -c
LDFLAGS=

SOURCES+= \
	main.c \
	qb_object_foo.c \
	qb_object_bar.c \
	../utils/logger/qb_logger.c

OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=method

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
