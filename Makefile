# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -I./include
LIBS = -lglfw -lGL -lm

# Directories
SRC_DIR = src
OBJDIR = bin
BUILD_DIR = build

# Find all .cpp files recursively
SRCS = $(shell find $(SRC_DIR) -name '*.cpp')

# Create matching object paths (replace src/ with bin/ and .cpp -> .o)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

# Glad source file (if it’s not already in src/OpenGL)
GLAD_SRC = $(SRC_DIR)/glad.c
GLAD_OBJ = $(OBJDIR)/glad.o

# Output executable
TARGET = $(BUILD_DIR)/F0X

# Default target
all: $(TARGET)

# Link object files
$(TARGET): $(OBJS) $(GLAD_OBJ)
	@mkdir -p $(dir $(TARGET))
	$(CXX) $(OBJS) $(GLAD_OBJ) -o $(TARGET) $(LIBS)

# Compile .cpp files into .o files under bin/
$(OBJDIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile glad.c
$(GLAD_OBJ): $(GLAD_SRC)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
clean:
	rm -rf $(OBJDIR) $(BUILD_DIR)
