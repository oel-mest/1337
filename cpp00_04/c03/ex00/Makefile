# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Target executable
TARGET = ex00

# Source files
SRC = main.cpp ClapTrap.cpp

# Build target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean build files
clean:
	rm -f $(TARGET)

re : clean all
# Phony targets
.PHONY: all clean re
