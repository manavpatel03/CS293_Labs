# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++20

# Source file
SRCS = eval.cpp

# Object file
OBJS = hash.o

# Executable
EXEC = eval

# Targets for different operating systems
all: $(EXEC)

eval: hash.o
	$(CXX) $(OBJS) -o $(EXEC)

crack: hash.o crack.cpp
	$(CXX) crack.cpp -o crack

# Clean up generated files
clean:
	rm -f $(EXEC)
