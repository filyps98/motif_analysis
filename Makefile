
TARGET = main

SRC = src
INC = mnp_lib
BIN = bin

SOURCE = $(wildcard $(SRC)/*.c)
OBJECT = $(patsubst %,$(BIN)/%, $(notdir $(SOURCE:.c=.o)))

CC = gcc
CFLAGS = -I$(INC)

LIBS = -lm

$(BIN)/$(TARGET) : $(OBJECT)
		$(CC) -o $@ $^ $(LIBS)

$(BIN)/%.o : $(SRC)/%.c
		$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: help run clean

run: $(BIN)/$(TARGET)
		$(BIN)/$(TARGET)

clean:
		rm -f $(OBJECT) $(BIN)/$(TARGET)

help:
		@echo "src: $(SOURCE)"