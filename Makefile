CC := g++
LD := g++

SRC := src/client
BUILD_BASE := build
BUILD := build/client
BIN := bin
TARGET := bin/client

ifeq (${ARG},server)
	SRC := src/server
	TARGET := bin/server
	BUILD := build/server
endif


SOURCES := $(shell find $(SRC) -type f -name "*.cpp")
OBJS := $(SOURCES:$(SRC)/%.cpp=$(BUILD)/%.o)

FLAGS := -Wall -std=c++11 -lpthread

all: $(TARGET)
	@true

$(TARGET): $(OBJS)
	@mkdir -p bin
	@mkdir -p $(@D)
	@$(LD) $+ $(FLAGS) -o $@
	@echo "Building $@"

$(BUILD)/%.o: $(SRC)/%.cpp 
	@mkdir -p build
	@mkdir -p $(BUILD)
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $< -c -o $@
	@echo "Building $@"


clean:
	@rm -f $(OBJS)  
	@rm -f $(TARGET) 
	-@find $(BIN) -type d -empty -delete 2> /dev/null || true
	-@find $(BUILD_BASE) -type d -empty -delete 2> /dev/null || true

.PHONY: all 
.SECONDARY: $(OBJS) 
