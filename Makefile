CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinclude

SRC = src/main.cpp src/MatrixMath.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)