#See README.md for more info
INCLUDE_DIR = include
BUILD_DIR = build
SOURCE_DIR = src
CXX_STANDARD = c++17
CXX_WARNINGS = -Wall -Wextra -Wpedantic
EXECUTABLE_NAME = main
CXX = g++
CXXFLAGS = $(CXX_WARNINGS) -std=$(CXX_STANDARD)
CPPFLAGS = -I $(INCLUDE_DIR)

COMPILER_CALL = $(CXX) $(CXXFLAGS) $(CPPFLAGS)
CXX_SOURCES = $(wildcard $(SOURCE_DIR)/*.cpp)      						  		   #Combine all .cpp file 
CXX_OBJECTS = $(patsubst $(SOURCE_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(CXX_SOURCES))    #Combine all object file

build: $(CXX_OBJECTS)
	$(COMPILER_CALL) $(CXX_OBJECTS) -o $(BUILD_DIR)/$(EXECUTABLE_NAME)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(COMPILER_CALL) -c $< -o $@

run: build
	./$(BUILD_DIR)/$(EXECUTABLE_NAME)
clean:
	rm -f $(BUILD_DIR)/*.o
	rm -f $(BUILD_DIR)/$(EXECUTABLE_NAME)