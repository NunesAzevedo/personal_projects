# Compilador
CC = gcc
CFLAGS = -g -Wall -O3
INCLUDE = $(wildcard $(SRC_DIR)/*.h)
SOURCES = $(wildcard $(SRC_DIR)/*.c)
# RELATORIO = $(wildcard $(RELATORIO_DIR)/*.txt)
OBJ = $(SOURCES:$(SRC_DIR)/%.c = $(SRC_DIR)/%.o)

# Target
NOME_EXECUTAVEL = Gerador_de_relatorios
TARGET = $(BIN_DIR)/$(NOME_EXECUTAVEL)
RELATORIO = $(RELATORIO_DIR)/relatorio.txt

# Diretórios
SRC_DIR = src
BIN_DIR = bin
RELATORIO_DIR = relatorio

# Criar diretórios bin e build
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(RELATORIO_DIR):
	mkdir -p $(RELATORIO_DIR)

# Compilar arquivos .c em arquivos .o
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJ) $(BIN_DIR) $(RELATORIO_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

debug: $(OBJ) $(BIN_DIR) $(RELATORIO_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) -DDEBUG

run: $(TARGET)
	$(TARGET)

open: $(RELATORIO)
	code $(RELATORIO) &

.PHONY: clean

clean:
	@rm -f $(BUILD_DIR)/*.o ./*.zip $(TARGET) core

zip: 
	@rm -f *.zip
	zip -r $(NOME_EXECUTAVEL).zip $(SRC_DIR)/* ./Makefile