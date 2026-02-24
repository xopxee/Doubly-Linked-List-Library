CC = gcc
LDFLAGS =
TARGET = main
HEADERS = doubly_linked_list.h
SOURCES = doubly_linked_list.c main.c
DEPENDENCIES = $(HEADERS) $(SOURCES)

all: $(TARGET)

$(TARGET): $(DEPENDENCIES)
	$(CC) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)
	
clean:
	rm -f $(TARGET)