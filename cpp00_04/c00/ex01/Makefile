# Compiler
CXX = clang++

# Compiler flags
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Target executable
TARGET = ex01

# Source files
SRC = main.cpp Contact.cpp PhoneBook.cpp

# Build target
all: $(TARGET)

$(TARGET): $(SRC) Contact.hpp PhoneBook.hpp
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean build files
clean:
	rm -f $(TARGET)

re : clean all
# Phony targets
.PHONY: all clean re
