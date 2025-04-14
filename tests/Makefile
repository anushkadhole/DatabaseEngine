CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRC = src/main.cpp src/Database.cpp src/BTree.cpp src/Parser.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = dbengine

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
