CC = gcc
MKDIR = mkdir -p
RM = rm -rf
CFLAGS = -Werror -Wall

SOURCES := $(shell find ./src -type f -name '*.c')
OBJECTS := $(patsubst ./src/%.c, ./build/obj/%.o, $(SOURCES))

# Main and default target to build the executable
build/bin/lae: $(OBJECTS)
	$(MKDIR) $(@D)
	$(CC) $^ -o $@ $(CFLAGS)

./build/obj/%.o: ./src/%.c
	$(MKDIR) $(@D)
	$(CC) -c $< -o $@ $(CFLAGS)

list_sources:
	for FILE in $(SOURCES); do \
		echo $$FILE; \
	done

clean:
	$(RM) build
