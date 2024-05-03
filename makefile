# Mutez make
MAKEFLAGS += --silent

# Nom du programme final
TARGET = airwatcher

# Compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -ansi -pedantic -Wall -std=c++11 -g -DMAP

# Répertoire des fichiers sources
SRC_DIR = $(CURDIR)/src/*

# Répertoire pour les fichiers objets
OBJ_DIR = $(CURDIR)/obj

# Liste des fichiers source
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
HEADERS = $(wildcard $(SRC_DIR)/*.h)

# Liste des fichiers objets générés à partir des fichiers source
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# ---------------------------------------------------------------------
# ---------------------------------------------------------------------
# ---------------------------------------------------------------------

# Règle par défaut
all: $(TARGET)

# Règle pour générer le programme final
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Compilation terminée executable créé: $@"

# Règle spéciale pour le main qui n'a pas de .h
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Fin de la création du fichier objet $@"

# Règle générique pour la création des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Fin de la création du fichier objet $@"

# Nettoyage de tout
clean:
	rm -f $(OBJECTS) $(TARGET)
	rm -f ./sauvegarde.txt
	@echo "Nettoyage terminé!"
