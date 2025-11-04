# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -O

# Source files
SRC = main.cpp user.cpp transactions.cpp hasher.cpp gen.cpp block.cpp blockchain.cpp

# Object files (replace .cpp with .o)
OBJ = $(SRC:.cpp=.o)

# Executable name
TARGET = blockchain

# Default rule
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o
%.o: %.cpp main.h
	$(CXX) $(CXXFLAGS) -c $<

# Clean compiled files
clean:
	rm -f $(OBJ) $(TARGET)
