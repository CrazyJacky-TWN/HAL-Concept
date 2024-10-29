# define variables
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lm
APP_SOURCES = app
HAL_SOURCES = hal
EXECUTABLE = main
OUTPUT_DIR = build

# source files
SOURCES = main.c
SOURCES	+= $(APP_SOURCES)/app_serializer.c
SOURCES	+= $(HAL_SOURCES)/iic_device.c

# location of header files 
INCLUDES = -I./$(HAL_SOURCES)
INCLUDES += -I./$(APP_SOURCES)

OBJECTS = $(SOURCES:.c=.o)

all: $(EXECUTABLE)

# complier
%.o: %.c
	$(CC) $(CFLAGS) -c -o $(OUTPUT_DIR)/$@ $< 

# linker
$(EXECUTABLE): $(OBJECTS)
#	$(CC) $(LDFLAGS) $(OUTPUT_DIR)/$(OBJECTS) -o $(OUTPUT_DIR)/$@
	$(CC) $(LDFLAGS) -o $(OUTPUT_DIR)/$@ $(OUTPUT_DIR)/main.o $(OUTPUT_DIR)/$(HAL_SOURCES)/iic_device.o $(OUTPUT_DIR)/$(APP_SOURCES)/app_serializer.o

clean:
	rm -rf $(OUTPUT_DIR)
	mkdir -p $(OUTPUT_DIR)
	mkdir -p $(OUTPUT_DIR)/$(HAL_SOURCES)
	
