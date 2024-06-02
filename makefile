# Mutez make
MAKEFLAGS += --silent

# Nom du programme final
TARGET = airwatcher

# Compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -ansi -pedantic -Wall -std=c++11 -O3 -g

# Répertoire des fichiers sources et tests
SRC_DIR = $(CURDIR)/src
TEST_DIR = $(CURDIR)/tests

# Répertoire pour les fichiers objets
OBJ_DIR = $(CURDIR)/obj

# Liste des fichiers source
SOURCES = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(TEST_DIR)/*.cpp)
HEADERS = $(wildcard $(SRC_DIR)/*.h) $(wildcard $(TEST_DIR)/*.h)

# Liste des fichiers objets générés à partir des fichiers source
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# ---------------------------------------------------------------------
# ---------------------------------------------------------------------
# ---------------------------------------------------------------------

# Règle par défaut
all: $(TARGET)

# Règle pour générer le programme final
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ -lm
	@echo "Compilation terminée, executable créé: $@"

# Règle générique pour la création des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Fin de la création du fichier objet $@"


# Nettoyage de tout
clean:
	rm  $(OBJ_DIR)/*.o $(TARGET)
