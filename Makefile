SRC_DIR := src
INC_DIR := include
BUILD_DIR := textEditor


TARGET := $(BUILD_DIR)/prog
SRC := main.c $(wildcard $(SRC_DIR)/*.c)


CC := gcc
CFLAGS := -Wall -I$(INC_DIR)
DEBUG_FLAGS := -g 
LIBS := -lncurses

default: $(TARGET)


$(TARGET): $(SRC)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)


debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(TARGET)


leak: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)



# Limpeza
clean:
	rm -rf $(TARGET)

# Execução
run: $(TARGET)
	./$(TARGET)
