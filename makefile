# define variables
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lm
HAL_SOURCES = HAL
EXECUTABLE = main
OUTPUT_DIR = build

# source files
SOURCES = main.c
SOURCES	+= $(HAL_SOURCES)/device.c
SOURCES	+= $(HAL_SOURCES)/hal_max96853.c

# location of header files 
INCLUDES = -I./$(HAL_SOURCES)

OBJECTS = $(SOURCES:.c=.o)

all: $(EXECUTABLE)

# complier
%.o: %.c
	$(CC) $(CFLAGS) -c -o $(OUTPUT_DIR)/$@ $< 

# linker
$(EXECUTABLE): $(OBJECTS)
#	$(CC) $(LDFLAGS) $(OUTPUT_DIR)/$(OBJECTS) -o $(OUTPUT_DIR)/$@
	$(CC) $(LDFLAGS) -o $(OUTPUT_DIR)/$@ $(OUTPUT_DIR)/main.o $(OUTPUT_DIR)/$(HAL_SOURCES)/device.o $(OUTPUT_DIR)/$(HAL_SOURCES)/hal_max96853.o

clean:
	rm -rf $(OUTPUT_DIR)
	mkdir -p $(OUTPUT_DIR)
	mkdir -p $(OUTPUT_DIR)/$(HAL_SOURCES)
	
