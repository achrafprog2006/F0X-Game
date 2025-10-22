# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -I./include
LIBS = -lglfw -lGL -lm

# Source files
SRCS = $(wildcard src/*.cpp)
OBJS = $(patsubst src/%.cpp, $(OBJDIR)/%.o, $(SRCS))  # Place .o files in the bin directory
OBJDIR = bin

# Glad source file
GLAD_SRC = src/glad.c
GLAD_OBJ = $(OBJDIR)/glad.o

# Output executable name
TARGET = build/F0X

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS) $(GLAD_OBJ)
	@mkdir -p $(dir $(TARGET))  # Ensure the build directory exists
	$(CXX) $(OBJS) $(GLAD_OBJ) -o $(TARGET) $(LIBS)

# Compile each .cpp file into a .o file in the OBJDIR
$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(OBJDIR)  # Create OBJDIR if it doesn't exist
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile glad.c into an object file
$(GLAD_OBJ): $(GLAD_SRC)
	@mkdir -p $(OBJDIR)  # Ensure the OBJDIR exists
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(GLAD_OBJ) $(TARGET)
