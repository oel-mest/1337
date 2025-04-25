# Compiler
CXX = clang++

# Compiler flags
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Target executable
TARGET = ex02

# Source files
SRC = tests.cpp Account.cpp

# Build target
all: $(TARGET)

$(TARGET): $(SRC) Account.hpp
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean build files
clean:
	rm -f $(TARGET)

re : clean all
# Phony targets
.PHONY: all clean re
